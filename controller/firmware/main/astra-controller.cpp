#include <esp_timer.h>
#include <freertos/FreeRTOS.h>
#include <freertos/timers.h>
#include <driver/gpio.h>
#include "led_strip.h"
#include "led_strip_types.h"
#include "v202_protocol.hpp"
#include "nrf24.hpp"
#include "joystick.hpp"

#define NEOPIXEL_GPIO GPIO_NUM_8
#define NUM_NEOPIXEL 3

// this is a UART pin - might need to be disabled
#define BUTTON_ENCODER_0 GPIO_NUM_20
#define BUTTON_ENCODER_1 GPIO_NUM_5
#define BUTTON_ENCODER_2 GPIO_NUM_6

#define ADC_SDA GPIO_NUM_10
#define ADC_SCL GPIO_NUM_9
#define ADC_INT GPIO_NUM_7

typedef enum {
  BTN_NONE = 0,
  BTN_JOY_R = 1,
  BTN_JOY_L = 2,
  BTN_JOY_BOTH = 3,
  BTN_3 = 4,
  BTN_1 = 5,
  BTN_2 = 6,
  BTN_4 = 7
} button_state_t;

// this essentially stores the currently pressed button number (1-7)
static button_state_t button_state = BTN_NONE;

/// Higher-level handler for buttons presses
static void button_press_handler(button_state_t button_pressed) {
  // TODO: unimplemented
  // note - this is called from an interrupt - use queues if delays or other long operations are needed
}

/// Button priority encoder interrupt handler
static void IRAM_ATTR button_isr_handler(void* arg) {
  gpio_num_t gpio_num = (gpio_num_t) (uint32_t) arg;
  // active-low, so invert
  int new_pin_state = !gpio_get_level(gpio_num);
  uint8_t new_button_state = button_state;

  // convert gpio number to bit index
  uint8_t bit;
  switch (gpio_num) {
    case BUTTON_ENCODER_0:
      bit = 0;
    case BUTTON_ENCODER_1:
      bit = 1;
    case BUTTON_ENCODER_2:
      bit = 2;
    default: return;
  }

  // clear
  new_button_state &= ~(1 << bit);
  // set
  new_button_state |= (new_pin_state << bit);

  if (new_button_state != button_state && new_button_state != 0) {
    button_press_handler(button_state = (button_state_t) new_button_state);
  }
}

led_strip_handle_t init_neopixel() {
  // configure neopixel
  led_strip_config_t neopixel_config = {
    .strip_gpio_num = NEOPIXEL_GPIO,
    .max_leds = NUM_NEOPIXEL,
    .led_model = LED_MODEL_WS2812,
    .color_component_format = LED_STRIP_COLOR_COMPONENT_FMT_GRB,
    .flags = {
      .invert_out = false
    }
  };
  led_strip_rmt_config_t neopixel_rmt_config = {
    .clk_src = RMT_CLK_SRC_DEFAULT,
    .resolution_hz = 10 * 1000 * 1000, // 10 MHz
    .mem_block_symbols = 64,
    .flags = {
      .with_dma = false, // not available on C3
    }
  };
  led_strip_handle_t neopixel_handle = nullptr;
  ESP_ERROR_CHECK(led_strip_new_rmt_device(&neopixel_config, &neopixel_rmt_config, &neopixel_handle));
  // turn all off
  led_strip_clear(neopixel_handle);
  return neopixel_handle;
}

void init_buttons() {
  // configure button GPIOs
  gpio_config_t io_conf = {
    // rising or falling
    .pin_bit_mask = (1ULL << BUTTON_ENCODER_0) | (1ULL << BUTTON_ENCODER_1) | (1ULL << BUTTON_ENCODER_2),
    .mode = GPIO_MODE_INPUT,
    .pull_up_en = GPIO_PULLUP_ENABLE,
    .pull_down_en = GPIO_PULLDOWN_DISABLE,
    .intr_type = GPIO_INTR_ANYEDGE,
  };
  gpio_config(&io_conf);

  // register interrupt handlers
  gpio_isr_handler_add(BUTTON_ENCODER_0, button_isr_handler, (void*) BUTTON_ENCODER_0);
  gpio_isr_handler_add(BUTTON_ENCODER_1, button_isr_handler, (void*) BUTTON_ENCODER_1);
  gpio_isr_handler_add(BUTTON_ENCODER_2, button_isr_handler, (void*) BUTTON_ENCODER_2);
}

uint8_t map_v202_rotation(uint8_t joystick_value) {
  int8_t signed_value = (int8_t) (joystick_value - 128);

  // [-128, 0] gets mapped to [0, 128] (left)
  if (signed_value <= 0) return (uint8_t) (-signed_value);
  // (0, 127] gets mapped to (128, 255] (right)
  else return (uint8_t) (signed_value) + 0x80;
}

void app_main(void)
{
  // setup per-pin interrupts
  gpio_install_isr_service(0);

  TaskHandle_t main_task = xTaskGetCurrentTaskHandle();

  led_strip_handle_t neopixel = init_neopixel();
  // LED 0 <- Red
  led_strip_set_pixel(neopixel, 0, 255, 0, 0);

  init_buttons();

  // configure TX
  V202 v202;
  // pins configured in defconfig
  NRF24 nrf24;
  v202.init(&nrf24, TX, TAER);

  // initialize joystick ADC
  Joystick joystick(ADC_SDA, ADC_SCL, ADC_INT);

  // start joystick main loop
  joystick.start(main_task);

  // wait for initialization
  ulTaskNotifyTakeIndexed(JOYSTICK_TASK_NOTIFY_INDEX, pdTRUE, portMAX_DELAY);

  // main loop
  while (true) {
    // transmitter mode 2
    uint8_t throttle = joystick.joy1_v;
    uint8_t yaw = map_v202_rotation(joystick.joy1_h);
    uint8_t pitch = map_v202_rotation(joystick.joy2_v);
    uint8_t roll = map_v202_rotation(joystick.joy2_h);

    // TODO: do something here
    uint8_t flags = 0;
    v202.command(throttle, yaw, pitch, roll, flags);

    vTaskDelay(50 / portTICK_PERIOD_MS);
  }
}
