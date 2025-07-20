#pragma once

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/i2c_master.h>
#include <driver/gpio.h>
#include <ads111x.h>

#define JOYSTICK_NUM_ADC_CHANNELS 4
#define JOYSTICK_TASK_NOTIFY_INDEX 1

class Joystick {
public:
  Joystick(gpio_num_t i2c_sda, gpio_num_t i2c_scl, gpio_num_t alert_pin);
  ~Joystick();

  volatile uint8_t joy1_h;
  volatile uint8_t joy1_v;
  volatile uint8_t joy2_h;
  volatile uint8_t joy2_v;
  volatile bool ready = false;

  /// Start the main task loop
  void start(TaskHandle_t caller_task_handle);
private:
  i2c_dev_t adc_i2c;
  gpio_num_t alert_pin;
  static void IRAM_ATTR alert_isr_handler(void* arg);

  void main_loop();
  TaskHandle_t main_loop_handle;
  TaskHandle_t caller_task_handle;
  /// static function that just calls member function
  static inline void main_loop_handoff(void* arg) { ((Joystick*) arg)->main_loop(); }
};
