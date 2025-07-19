/* Adapted from https://github.com/Flaykz/Wltoys-v202/blob/master/src/V202.h
 * MIT Licensed
 */

#include "v202_protocol.hpp"
#include "freertos/timers.h"
#include "esp_timer.h"

V202::V202() {
  mTxid[0] = 0;
  mTxid[1] = 0;
  mTxid[2] = 0;
  mTimeout = 9999;
  mErrorTimeoutCode = NO_ERROR;

  for (uint8_t i = 0; i < 8; ++i) {
    uint8_t freq = 0x18 + (i << 3);
    freq_test[i] = (freq & 0x0F) ? freq : freq - 3;
  }

  mState = NO_BIND;
  mLastSignalTime = 0;
  mRfChNum = 0;
}

void V202::init(NRF24 *wireless, uint8_t mode, uint8_t txType) {
  mMode = mode;
  mTxType = txType;
  mWireless = wireless;
  mWireless->config_tx(16, freq_test[0]);
  if (mMode == RX) {
    //mWireless->rxMode(freq_test[0]);
  } else {
    packet_sent = false;
    //mWireless->txMode(freq_test[0]);
    mRfChNum = 0;
  }
  mLastSignalTime = esp_timer_get_time() / 1000ULL;
}

void V202::command(uint8_t throttle, int8_t yaw, int8_t pitch, int8_t roll,
                   uint8_t flags) {
  mFrame[14] = flags & 0xff;
  if (isBindingFrame()) {
    // binding
    mFrame[0] = 0;
    mFrame[1] = 0;
    mFrame[2] = 0;
    mFrame[3] = 0;
    mFrame[4] = 0;
    mFrame[5] = 0;
    mFrame[6] = 0;
  } else {
    // regular packet
    mFrame[0] = throttle; // T
    mFrame[1] = yaw;      // A
    mFrame[2] = pitch;    // E
    mFrame[3] = roll;     // R
    // Trims, middle is 0x40
    mFrame[4] = 0x40; // yaw
    mFrame[5] = 0x40; // pitch
    mFrame[6] = 0x40; // roll
  }
  // TX id
  mFrame[7] = mTxid[0];
  mFrame[8] = mTxid[1];
  mFrame[9] = mTxid[2];
  // empty
  mFrame[10] = flags >> 8;
  mFrame[11] = 0x00; // cam up cam down ?
  mFrame[12] = 0x00; // ?
  mFrame[13] = 0x00; // ?
  mFrame[15] = getCRC();

  packet_sent = false;
  uint8_t rf_ch = mRfChannels[mRfChNum >> 1];
  mRfChNum = (mRfChNum + 1) & 0x1F;
  mWireless->setFreq(rf_ch);
  mWireless->writePayload(mFrame);
  packet_sent = true;
  // delayMicroseconds(15);
}

void V202::setTXId(uint8_t txid[3]) {

  mTxid[0] = txid[0];
  mTxid[1] = txid[1];
  mTxid[2] = txid[2];
  retrieveFrequency();
}

void V202::retrieveFrequency() {
  uint8_t sum;
  sum = mTxid[0] + mTxid[1] + mTxid[2];
  // Base row is defined by lowest 2 bits
  uint8_t (&fh_row)[16] = freq_hopping[sum & 0x03];
  // Higher 3 bits define increment to corresponding row
  uint8_t increment = (sum & 0x1e) >> 2;
  for (int i = 0; i < 16; ++i) {
    uint8_t val = fh_row[i] + increment;
    // Strange avoidance of channels divisible by 16
    mRfChannels[i] = (val & 0x0f) ? val : val - 3;
  }
}

uint8_t V202::getCRC() {
  uint8_t sum = 0;
  for (uint8_t i = 0; i < 15; ++i)
    sum += mFrame[i];
  return sum;
}

bool V202::isBindingFrame() {
    return (mFrame[14] == 0xc0);
}
