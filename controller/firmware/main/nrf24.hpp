#pragma once

#include <mirf.h>

#undef mirf_CONFIG
#define mirf_CONFIG ((1<<MASK_TX_DS) | (1<<EN_CRC) | (1<<CRCO) )

class NRF24 {
private:
  NRF24_t dev;
public:
  NRF24();
  ~NRF24();
  void config_tx(uint8_t payload_size, uint8_t channel);
  void setFreq(uint8_t channel);
  void writePayload(uint8_t* buf);
};
