#include "nrf24.hpp"
#include <freertos/timers.h>

static uint8_t rxAddr[5] = { 0x88, 0x66, 0x86, 0x86, 0x86 };
static uint8_t txAddr[5] = { 0x66, 0x88, 0x68, 0x68, 0x68 };

NRF24::NRF24() {
  Nrf24_init(&dev);
}

NRF24::~NRF24() {
  Nrf24_deinit(&dev);
}

void NRF24::config_tx(uint8_t payload_size, uint8_t channel) {
  Nrf24_config(&dev, channel, payload_size);

  Nrf24_config(&dev, EN_AA, 0); // disable auto acknowledgment
  Nrf24_configRegister(&dev, SETUP_RETR, 0xFF);
  Nrf24_setRetransmitCount(&dev, 15);
  Nrf24_setRetransmitDelay(&dev, 15); // 15 = 4000us
  // 2 = -6dBm
  Nrf24_SetOutputRF_PWR(&dev, 2);

  // config addresses
  Nrf24_setRADDR(&dev, rxAddr);
  Nrf24_setTADDR(&dev, txAddr);
  Nrf24_addRADDR(&dev, 2, 0xC3);
  Nrf24_addRADDR(&dev, 3, 0xC4);
  Nrf24_addRADDR(&dev, 4, 0xC5);
  Nrf24_addRADDR(&dev, 5, 0xC6);

  vTaskDelay(50 / portTICK_PERIOD_MS);

  Nrf24_powerUpTx(&dev);
}

void NRF24::setFreq(uint8_t channel) {
  dev.channel = channel;
  Nrf24_configRegister(&dev, RF_CH, channel);
}

void NRF24::writePayload(uint8_t* buf) {
  Nrf24_send(&dev, buf);
}
