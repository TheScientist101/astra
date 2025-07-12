# Building Astra's firmware

Astra's firmware is based on [Betaflight](https://betaflight.com).

We've provided a config in `config.h`. This includes everything except the timer DMA configuration - we need the physical board to figure out this.

Follow these instructions to setup a Betaflight build environment: https://betaflight.com/docs/category/building

## Detailed instructions:

1. Setup Betaflight build environment:
   ```bash
   $ git clone https://github.com/betaflight/betaflight.git
   $ cd betaflight
   $ make arm_sdk_install # if you don't have it installed already
   $ make configs
   ```
   
2. Copy astra config
   ```bash
   $ mkdir -p src/config/configs/ASTRA/
   $ cp /path/to/astra/firmware/config.h src/config/configs/ASTRA/
   ```
   
3. Apply patch to enable nRF24 RX
   ```bash
   $ git apply /path/to/astra/firmware/0001-build-link-NRF24-protocol-sources.patch
   ```
   
4. Build
   ```bash
   $ make ASTRA
   ```

