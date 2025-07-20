#include "joystick.hpp"
#include <esp_err.h>
#include <esp_log.h>

#define TAG "Joystick"

// channel index to mux mode mapping
static ads111x_mux_t channel_mux[4] = {
  ADS111X_MUX_0_GND,
  ADS111X_MUX_1_GND,
  ADS111X_MUX_2_GND,
  ADS111X_MUX_3_GND,
};

#define MAX_RAW_ADC_VALUE 26400
#define MAX_USED_RAW_ADC_VALUE 26214
#define EPSILON 0.000001

/// Scale a signed 16-bit 3.3V ADC value to an unsigned byte
uint8_t scale_adc_value(int16_t value) {
  uint32_t unsigned_value = value < 0 ? 0 : value;
  // max input voltage: 3.3V
  // max range: 4.096V
  // max output value (theoretical): 2^15
  // max actual output value: 3.3V/4.096V * 2^15 = 26400
  static_assert((int) (3.3/4.096 * (1 << 15) + EPSILON) == MAX_RAW_ADC_VALUE, "Expect MAX_RAW_ADC_VALUE to be correct");
  // 26400 * 5 >> 9 = 257 (which is really close to 255)
  static_assert(MAX_RAW_ADC_VALUE * 5 >> 9 > 255, "Expect MAX_RAW_ADC_VALUE to be out of bounds when converting");
  static_assert((MAX_USED_RAW_ADC_VALUE + 1) * 5 >> 9 > 255, "Expect MAX_USED_RAW_ADC_VALUE + 1 to be out of bounds when converting");
  // 26214 * 5 >> 9 = 255 (max value that yields 255)
  static_assert(MAX_USED_RAW_ADC_VALUE * 5 >> 9 == 255, "Expect MAX_USED_RAW_ADC_VALUE to be scaled to 255");
  // this is a 0.7% loss in range
  uint8_t result = 255;
  if (unsigned_value <= MAX_USED_RAW_ADC_VALUE) {
    result = (unsigned_value * 5) >> 9;
  }
  return result;
}

Joystick::Joystick(gpio_num_t i2c_sda, gpio_num_t i2c_scl, gpio_num_t alert_pin) : alert_pin(alert_pin) {
  ESP_LOGI(TAG, "Initializing ADC");

  // ADC has internal pullups
  adc_i2c.cfg.scl_pullup_en = false;
  adc_i2c.cfg.sda_pullup_en = false;

  // init i2c device
  ESP_ERROR_CHECK(ads111x_init_desc(&adc_i2c, ADS111X_ADDR_GND, I2C_NUM_0, i2c_sda, i2c_scl));

  ESP_ERROR_CHECK(ads111x_set_gain(&adc_i2c, ADS111X_GAIN_4V096));
  // about 4x as fast as nRF - we can tune this
  ESP_ERROR_CHECK(ads111x_set_data_rate(&adc_i2c, ADS111X_DATA_RATE_250));
  //ESP_ERROR_CHECK(ads111x_set_comp_mode(&adc_i2c, ADS111X_COMP_MODE_NORMAL));
  // assert after 1 conversion
  ESP_ERROR_CHECK(ads111x_set_comp_queue(&adc_i2c, ADS111X_COMP_QUEUE_1));

  // set ALERT to conversion-ready pin
  // lowest bit 0
  ESP_ERROR_CHECK(ads111x_set_comp_low_thresh(&adc_i2c, 0x0000));
  // highest bit 1
  ESP_ERROR_CHECK(ads111x_set_comp_high_thresh(&adc_i2c, 0x8000));

  // configure alert pin
  gpio_config_t alert_pin_cfg;
  alert_pin_cfg.pin_bit_mask = 1ULL << alert_pin;
  alert_pin_cfg.pull_down_en = GPIO_PULLDOWN_DISABLE;
  alert_pin_cfg.pull_up_en = GPIO_PULLUP_ENABLE;
  alert_pin_cfg.mode = GPIO_MODE_INPUT;
  // interrupt on rising edge (active-low)
  // TODO: check this?
  alert_pin_cfg.intr_type = GPIO_INTR_POSEDGE;
  ESP_ERROR_CHECK(gpio_config(&alert_pin_cfg));
}

Joystick::~Joystick() {
  ESP_LOGI(TAG, "Stopping conversion task");
  vTaskDelete(main_loop_handle);
  ESP_LOGI(TAG, "Cleaning up ADC");
  ESP_ERROR_CHECK(ads111x_set_mode(&adc_i2c, ADS111X_MODE_SINGLE_SHOT));
  ESP_ERROR_CHECK(ads111x_free_desc(&adc_i2c));
}

void Joystick::start(TaskHandle_t caller_task_handle) {
  this->caller_task_handle = caller_task_handle;

  ESP_LOGI(TAG, "Starting conversion task");
  xTaskCreate(Joystick::main_loop_handoff, "Joystick_Conversion_Task", 4096, this, 10, &main_loop_handle);
}


void IRAM_ATTR Joystick::alert_isr_handler(void* arg) {
  // joystick instance passed as data parm
  Joystick* joystick = (Joystick*) arg;

  BaseType_t xHigherPriorityTaskWoken = pdFALSE;

  // resume the main loop
  vTaskNotifyGiveFromISR(joystick->main_loop_handle, &xHigherPriorityTaskWoken);

  portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

void Joystick::main_loop() {
  // register interrupt handler
  ESP_ERROR_CHECK(gpio_isr_handler_add(alert_pin, alert_isr_handler, this));

  ESP_LOGI(TAG, "Starting ADC");
  // trigger initial read
  uint8_t current_channel = 0;
  ESP_ERROR_CHECK(ads111x_set_input_mux(&adc_i2c, channel_mux[current_channel]));
  ESP_ERROR_CHECK(ads111x_set_mode(&adc_i2c, ADS111X_MODE_CONTINUOUS));

  while (true) {
    vTaskDelay(1);

    // wait for conversion to be ready
    ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

    int16_t value;
    ads111x_get_value(&adc_i2c, &value);
    uint8_t scaled_value = scale_adc_value(value);

    // store corresponding value
    switch (current_channel) {
      case 0: joy2_h = scaled_value; break;
      case 1: joy2_v = scaled_value; break;
      case 2: joy1_h = scaled_value; break;
      case 3: joy1_v = scaled_value; break;
    }

    if (!ready) {
      // if this is the first time fetching data, send notification
      ready = true;
      xTaskNotifyGiveIndexed(caller_task_handle, JOYSTICK_TASK_NOTIFY_INDEX);
    }

    if ((++current_channel) >= 4) current_channel = 0;

    // update channel
    ESP_ERROR_CHECK(ads111x_set_input_mux(&adc_i2c, channel_mux[current_channel]));
  }
}
