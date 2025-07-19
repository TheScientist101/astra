# Ground Controller Firmware

Firmware for the `ESP32-C3-Super Mini` using `esp-idf`.

Drone communication uses the `V202` protocol.

### Credits and Libraries used:

- [`esp-idf-mirf`](https://github.com/nopnop2002/esp-idf-mirf) - nRF24 driver
- [`Flaykz/Wltoys-v202`](https://github.com/Flaykz/Wltoys-v202) - V202 protocol code/TX implementation
- [`betaflight`](https://github.com/betaflight/betaflight/blob/master/src/main/rx/nrf24_v202.c) - Betaflight's V202 implementation (used on the drone)
