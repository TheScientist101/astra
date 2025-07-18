/*
 * This file is part of Betaflight.
 *
 * Betaflight is free software. You can redistribute this software
 * and/or modify this software under the terms of the GNU General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later
 * version.
 *
 * Betaflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define FC_TARGET_MCU     STM32H750

#define BOARD_NAME        ASTRA
#define MANUFACTURER_ID   DUCK

#define TARGET_BOARD_IDENTIFIER "ASTR"
#define USBD_PRODUCT_STRING "Astra"

#define FC_VMA_ADDRESS    0x97CE0000

#define EEPROM_SIZE 8192

#define USE_SPRACING_PERSISTENT_RTC_WORKAROUND

#define USE_USB_ID

// ======== PERIPHERAL CONFIGURATION =======

#define USE_QUADSPI
#define USE_QUADSPI_DEVICE_1
#define QUADSPI1_SCK_PIN PB2
#define QUADSPI1_BK1_IO0_PIN PD11
#define QUADSPI1_BK1_IO1_PIN PD12
#define QUADSPI1_BK1_IO2_PIN PE2
#define QUADSPI1_BK1_IO3_PIN PD13
#define QUADSPI1_BK1_CS_PIN  PB6
#define QUADSPI1_BK2_IO0_PIN NONE
#define QUADSPI1_BK2_IO1_PIN NONE
#define QUADSPI1_BK2_IO2_PIN NONE
#define QUADSPI1_BK2_IO3_PIN NONE
#define QUADSPI1_BK2_CS_PIN  NONE
#define QUADSPI1_MODE QUADSPI_MODE_BK1_ONLY
#define QUADSPI1_CS_FLAGS (QUADSPI_BK1_CS_HARDWARE | QUADSPI_BK2_CS_NONE | QUADSPI_CS_MODE_LINKED)

// Barometer
#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN            PA5
#define SPI1_SDI_PIN            PA6
#define SPI1_SDO_PIN            PA7
#define SPI1_NSS_PIN            PA4

// NRF, SD card
#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN            PB13
#define SPI2_SDI_PIN            PB14
#define SPI2_SDO_PIN            PB15

// DDG
#define USE_SPI_DEVICE_3
#define SPI3_SCK_PIN            PC10
#define SPI3_SDI_PIN            PC11
#define SPI3_SDO_PIN            PC12

// gyro
#define USE_SPI_DEVICE_4
#define SPI4_SCK_PIN            PE12
#define SPI4_SDI_PIN            PE13
#define SPI4_SDO_PIN            PE14

// DDG
#define USE_I2C_DEVICE_1
#define I2C1_SCL_PIN PB8
#define I2C1_SDA_PIN PB9
//  #define I2C_DEVICE I2CDEV_1

// DDG
#define UART2_TX_PIN         PD5
#define UART2_RX_PIN         PD6
#define SERIALRX_UART SERIAL_PORT_USART2

// Standalone JST
#define UART4_TX_PIN         PA0
#define UART4_RX_PIN         PA1

// ======== DEVICE CONFIGURATION ========

// Quad SPI Flash (64 MB)
#define FLASH_QUADSPI_INSTANCE  QUADSPI
#define USE_FLASH
#define USE_FLASH_QUADSPI
#define USE_FLASH_M25P16
#define FLASH_CS_PIN            PB6
#define CONFIG_IN_EXTERNAL_FLASH
#define USE_FIRMWARE_PARTITION

// ADC -  Battery Voltage Measurement
#define USE_ADC
#define ADC_INSTANCE                    ADC1
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
//#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
//#define DEFAULT_CURRENT_METER_SCALE     100
#define DEFAULT_VOLTAGE_METER_SCALE     110
#define ADC_VBAT_PIN                    PC4
//#define ADC_RSSI_PIN         PC4
//#define ADC_CURR_PIN         PC0
//#define ADC_EXTERNAL1_PIN    PC5
//#define DEFAULT_FEATURES FEATURE_RSSI_ADC

// MicroSD Card - SPI2
#define USE_SDCARD
#define USE_SDCARD_SPI
#define SDCARD_SPI_CS_PIN    PB12
#define SDCARD_DETECT_PIN    PD8
#define SDCARD_DETECT_INVERTED
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_SDCARD
#define SDCARD_SPI_INSTANCE  SPI2

// Barometer - SPI1
#define USE_BARO
#define USE_BARO_BMP388
#define BARO_SPI_INSTANCE    SPI1
#define BARO_CS_PIN          PA4

// WS2812B
#define USE_LED_STRIP
#define LED_STRIP_PIN        PC3

// Motors - PWM TIM1
#define MOTOR1_PIN           PE9
#define MOTOR2_PIN           PE11
#define MOTOR3_PIN           PA10
#define MOTOR4_PIN           PA11

// RX - NRF24
#define USE_RX
#define USE_RX_NRF24
#define USE_RX_SPI
// protocol - can be customized
#define USE_RX_SYMA
#define RX_CE_PIN           PB10
#define RX_SPI_CS_PIN       PB11
#define RX_SPI_EXTI_PIN     PC7
#define RX_SPI_INSTANCE     SPI2
#define RX_NSS_PIN          RX_SPI_CS_PIN

// BMI270 - SPI4
#define USE_GYRO
#define USE_ACC
#define USE_ACCGYRO_BMI270
#define GYRO_1_EXTI_PIN      PE14
#define GYRO_1_SPI_INSTANCE  SPI4
#define GYRO_1_ALIGN         CW0_DEG_FLIP
#define GYRO_1_CS_PIN        PE7

// Status LEDs
#define LED0_PIN             PC5
#define LED1_PIN             PE10

// Custom Buttons
#define USE_BUTTONS
#define BUTTON_A_PIN            PA3
#define BUTTON_A_PIN_INVERTED
#define BUTTON_B_PIN            PA2
#define BUTTON_B_PIN_INVERTED

// ========= DMA CONFIGURATION =========

// TODO: figure out these once we get the board
#define ADC1_DMA_OPT            8
#define TIMUP1_DMA_OPT          0
#define TIMUP2_DMA_OPT          0
#define TIMUP3_DMA_OPT          0
#define TIMUP4_DMA_OPT          0
#define TIMUP5_DMA_OPT          0
#define TIMUP8_DMA_OPT          2

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0, PA8, 1, 10) \
    TIMER_PIN_MAP(1, PB11, 1, 11) \
    TIMER_PIN_MAP(2, PB15, 2, -1) \
    TIMER_PIN_MAP(3, PE5, 1, 0) \
    TIMER_PIN_MAP(4, PE6, 1, -1) \
    TIMER_PIN_MAP(5, PA0, 2, 0) \
    TIMER_PIN_MAP(6, PA1, 2, 1) \
    TIMER_PIN_MAP(7, PA2, 2, 2) \
    TIMER_PIN_MAP(8, PA3, 2, 3) \
    TIMER_PIN_MAP(9, PB6, 2, 4) \
    TIMER_PIN_MAP(10, PB7, 2, 5) \
    TIMER_PIN_MAP(11, PC6, 2, 6) \
    TIMER_PIN_MAP(12, PC7, 2, 7) \
    TIMER_PIN_MAP(13, PD14, 1, 12) \
    TIMER_PIN_MAP(14, PD15, 1, -1) \
    TIMER_PIN_MAP(15, PA6, 1, 0) \
    TIMER_PIN_MAP(16, PA7, 2, 0) \
    TIMER_PIN_MAP(17, PB0, 2, 0) \
    TIMER_PIN_MAP(18, PB1, 2, 0)

#define TIMUP1_DMA_OPT 0
#define TIMUP2_DMA_OPT 0
#define TIMUP3_DMA_OPT 0
#define TIMUP4_DMA_OPT 0
#define TIMUP5_DMA_OPT 0
#define TIMUP8_DMA_OPT 2

// FPV stuff

//#define USE_MAX7456
//#define CAMERA_CONTROL_PIN   PE5
//#define MAX7456_SPI_CS_PIN   PE11
//#define MAX7456_SPI_INSTANCE SPI4
