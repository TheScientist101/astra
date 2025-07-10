# Building Astra's firmware

It's based on Betaflight - config is in `config.h`

Follow these instructions to setup a Betaflight build environment: https://betaflight.com/docs/category/building

Copy the `config.h` into `betaflight/config/configs/ASTRA/` and run `make ASTRA`

## Detailed instructions:

```bash
$ git clone https://github.com/betaflight/betaflight.git
$ cd betaflight
$ make arm_sdk_install
$ make configs
$ mkdir -p src/config/configs/ASTRA/
$ cp /path/to/astra/firmware/config.h src/config/configs/ASTRA/
$ make ASTRA
```

