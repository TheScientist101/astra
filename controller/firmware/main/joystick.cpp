#include "joystick.hpp"
#include <esp_err.h>
#include <string.h>
#include <esp_log.h>

#define TAG "Joystick"

Joystick::Joystick(adc_channel_t joy1_h, adc_channel_t joy1_v, adc_channel_t joy2_h, adc_channel_t joy2_v) {
  adc_channels[0] = joy1_h;
  adc_channels[1] = joy1_v;
  adc_channels[2] = joy2_h;
  adc_channels[3] = joy2_v;

  ESP_LOGI(TAG, "Initializing ADC");

  // initialize ADC
  adc_continuous_handle_cfg_t adc_cfg = {
    .max_store_buf_size = 1024,
    .conv_frame_size = 256,
    .flags = { 0 }
  };
  ESP_ERROR_CHECK(adc_continuous_new_handle(&adc_cfg, &adc_handle));

  adc_digi_pattern_config_t adc_pattern[JOYSTICK_NUM_ADC_CHANNELS];
  for (int i = 0; i < JOYSTICK_NUM_ADC_CHANNELS; i++) {
    adc_pattern[i].atten = ADC_ATTEN_DB_12;
    adc_pattern[i].channel = adc_channels[i] & 0x7;
    adc_pattern[i].unit = ADC_UNIT_1;
    adc_pattern[i].bit_width = SOC_ADC_DIGI_MAX_BITWIDTH;
  }

  // configure the channels
  adc_continuous_config_t digi_cfg = {
    // 4 ADC channels used
    .pattern_num = JOYSTICK_NUM_ADC_CHANNELS,
    .adc_pattern = adc_pattern,
    .sample_freq_hz = 1 * 1000, // // Set sample frequency to 1 kHz
    // all pins are on ADC1
    .conv_mode = ADC_CONV_SINGLE_UNIT_1,
    .format = ADC_DIGI_OUTPUT_FORMAT_TYPE2,
  };

  ESP_ERROR_CHECK(adc_continuous_config(adc_handle, &digi_cfg));

  // register callbacks
  adc_continuous_evt_cbs_t cbs;
  cbs.on_conv_done = Joystick::adc_conv_done_callback;
  ESP_ERROR_CHECK(adc_continuous_register_event_callbacks(adc_handle, &cbs, this));

  main_task_handle = xTaskGetCurrentTaskHandle();
}

Joystick::~Joystick() {
  ESP_LOGI(TAG, "Cleaning up ADC");
  ESP_ERROR_CHECK(adc_continuous_stop(adc_handle));
  ESP_ERROR_CHECK(adc_continuous_deinit(adc_handle));
}

void Joystick::start() {
  ESP_LOGI(TAG, "Starting ADC");
  ESP_ERROR_CHECK(adc_continuous_start(adc_handle));
}

void Joystick::read() {
  // wait for adc data to come in
  ulTaskNotifyTakeIndexed(JOYSTICK_TASK_NOTIFY_INDEX, pdTRUE, portMAX_DELAY);

  uint8_t result[256];
  memset(result, 0xCC, 256);
  uint32_t ret_num = 0;

  // read until timeout
  while (true) {
    esp_err_t res = adc_continuous_read(adc_handle, result, 256, &ret_num, 0);
    switch (res) {
      ESP_LOGD(TAG, "Received %" PRIu32 " bytes from ADC", ret_num);
      case ESP_OK:
        for (int i = 0; i < ret_num; i += SOC_ADC_DIGI_RESULT_BYTES)  {
          adc_digi_output_data_t *output = (adc_digi_output_data_t*) &result[i];
          adc_channel_t chan = (adc_channel_t) output->type2.channel;
          // value from 0 to 2^SOC_ADC_MAX_BITWIDTH (4096)
          uint32_t data = output->type2.data;

          // store data
          if (chan == adc_channels[0]) {
            joy1_h = data;
          } else if (chan == adc_channels[1]) {
            joy1_v = data;
          } else if (chan == adc_channels[2]) {
            joy2_h = data;
          } else if (chan == adc_channels[3]) {
            joy2_v = data;
          } else {
            ESP_LOGW(TAG, "Invalid ADC channel: %" PRIu32, chan);
          }
        }
      case ESP_ERR_TIMEOUT:
        // no more ADC data available
        return;
      default:
        ESP_ERROR_CHECK(res);
    }

    // wait for 1 tick
    vTaskDelay(1);
  }
}

bool IRAM_ATTR Joystick::adc_conv_done_callback(adc_continuous_handle_t handle, const adc_continuous_evt_data_t *edata, void *user_data) {
  Joystick* joy = (Joystick*) user_data;
  BaseType_t mustYield = pdFALSE;
  // data processing done; continue
  vTaskNotifyGiveIndexedFromISR(joy->main_task_handle, JOYSTICK_TASK_NOTIFY_INDEX, &mustYield);

  return mustYield == pdTRUE;
}
