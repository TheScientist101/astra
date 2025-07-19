#pragma once

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_adc/adc_continuous.h>

#define JOYSTICK_NUM_ADC_CHANNELS 4
#define JOYSTICK_TASK_NOTIFY_INDEX 1

class Joystick {
public:
  Joystick(adc_channel_t joy1_h, adc_channel_t joy1_v, adc_channel_t joy2_h, adc_channel_t joy2_v);
  ~Joystick();

  uint32_t joy1_h;
  uint32_t joy1_v;
  uint32_t joy2_h;
  uint32_t joy2_v;

  void start();
  void read();
private:
  adc_channel_t adc_channels[JOYSTICK_NUM_ADC_CHANNELS];
  adc_continuous_handle_t adc_handle = NULL;
  TaskHandle_t main_task_handle;

  static bool IRAM_ATTR adc_conv_done_callback(adc_continuous_handle_t handle, const adc_continuous_evt_data_t *edata, void *user_data);
};
