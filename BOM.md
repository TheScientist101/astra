# Bill of Materials

## General Components

| Item                                 | Link                                                                                                                                                                         | Quantity | Total Price | Total Mass on Drone |
| ------------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------- | ----------- | ------------------- |
| PCB                                  |                                                                                                                                                                              | 1        | ~$25        | 10g                 |
| NRF24L01 Breakout                    | [AliExpress](https://www.aliexpress.us/item/3256805889378019.html)                                                                                                           | 1        | $0.99       | 2g                  |
| YoungRC 8520 Coreless Motor          | [Amazon](https://www.amazon.com/YoungRC-8520-Coreless-Propeller-Quadcopter/dp/B0BV6P4XYX)                                                                                    | 4        | $11.99      | 20g                 |
| SMD Solder Paste                     | [AliExpress](https://www.aliexpress.us/item/3256807158914612.html)                                                                                                           | 1        | $3.36       | -                   |
| Li-Po Battery (at least 12A current) | [Amazon](https://www.amazon.com/Tosiicop-3-7v-Drone-Lipo-Battery/dp/B0CR6DDGP1) [BetaFPV](https://betafpv.com/collections/batt-1s/products/bt2-0-450mah-1s-30c-battery-4pcs) | 1        | $9.99       | 17.6g               |
| OV5640 130 degree Camera             | [AliExpress](https://www.aliexpress.us/item/3256807307844099.html)                                                                                                           | 1        | $7.61       | 2g                  |

## PCB Components

_Mass estimate is included in PCB mass estimate_

| Item                                | Link                                                                                                                                                          | Quantity | Total Price             |
| ----------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------- | ----------------------- |
| 64 MB NOR Flash: W25Q64JVSSIQ       | [LCSC](https://www.lcsc.com/product-detail/NOR-FLASH_Winbond-Elec-W25Q64JVSSIQ_C179171.html?s_z=n_W25Q16JV)                                                   | 1        | $0.88                   |
| A03400A NMOS                        | [LCSC](https://lcsc.com/product-detail/MOSFETs_UMW-Youtai-Semiconductor-Co-Ltd-AO3400A_C347475.html)                                                          | 4        | $0.62 (for 20)          |
| BMI270 IMU                          | [LCSC](https://www.lcsc.com/product-detail/Accelerometers_Bosch-Sensortec-BMI270_C2836813.html?s_z=n_BMI270)                                                  | 1        | $0.92 (other suppliers) |
| STM32H750XBH6                       | [LCSC](https://www.lcsc.com/product-detail/Microcontrollers-MCU-MPU-SOC_STMicroelectronics-STM32H750XBH6_C405932.html?s_z=n_STM32H7)                          | 1        | $7.06                   |
| 25 MHz Crystal (optional, but good) | [LCSC](https://lcsc.com/product-detail/Crystals_Shenzhen-SCTF-Elec-SX3B25-000F1010F30_C2901684.html?s_z=n_25%2520MHz)                                         | 1        | $0.36 (5 ct)            |
| OT322524MJBA4SL 24 MHz Crystal      | [LCSC](https://lcsc.com/product-detail/Crystal-Oscillators_YXC-Crystal-Oscillators-OT322524MJBA4SL_C717686.html?s_z=n_24MHz%25203.3V)                         | 1        | $0.55               |
| 2.8V LDO                            | [LCSC](https://www.lcsc.com/product-detail/Voltage-Regulators-Linear-Low-Drop-Out-LDO-Regulators_Texas-Instruments-TLV74328PDBVR_C408971.html?s_z=n_TLV74328) | 1        | $0.05                   |
| 1.5V LDO                            | [LCSC](https://www.lcsc.com/product-detail/Voltage-Regulators-Linear-Low-Drop-Out-LDO-Regulators_MSKSEMI-TLV74315PDBVR-MS_C30197476.html?s_z=n_TLV74315)      | 1        | $0.09                   |
| 24 pin FPC Connector                | [LCSC](https://lcsc.com/product-detail/FFC-FPC-Flat-Flexible-Connector-Assemblies_JUSHUO-AFA07-S24FCA-00_C262726.html)                                        | 1        | $0.66 (5 ct)            |
| TLV1117LV-3.3                       | [LCSC](https://www.lcsc.com/product-detail/Voltage-Regulators-Linear-Low-Drop-Out-LDO-Regulators_Texas-Instruments-TLV1117LV33DCYR_C15578.html?s_z=n_TLV1117) | 1        | $0.84 (for 5)           |
| FCM1608KF-601T05 Ferrite Beads      | [LCSC](https://www.lcsc.com/product-detail/Ferrite-Beads_TAI-TECH-FCM1608KF-601T05_C133937.html?s_z=n_ferrite%2520beads)                                      | 1        | $0.18 (50 ct)           |
| FCM1608KF-121T06 Ferrite Beads      | [LCSC](https://lcsc.com/product-detail/Ferrite-Beads_TAI-TECH-FCM1608KF-121T06_C155064.html)                                                                  | 1        | $0.18 (50 ct)           |
| 100nF 16V 0805 Capacitor            | [LCSC](https://www.lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_Venkel-C0805X7R160-104KNP_C3865954.html?s_z=n_100%2520nF)               | 20       | $0.35 (50 ct)           |
| 1uF 16V 0805 Capacitor              | [LCSC](https://www.lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_Samsung-Electro-Mechanics-CL21B105KOFNNNE_C24123.html)                  | 5        | $0.21 (20 ct)           |
| 10uF 16V 0805 Capacitor             | [LCSC](https://www.lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_Samsung-Electro-Mechanics-CL21A106KOQNNNE_C1713.html)                   | 3        | $0.18 (20 ct)           |
| 3.9pF 50V 0603 Capacitor            | [LCSC](https://www.lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_Walsin-Tech-Corp-MT18N3R9C500CT_C908519.html)                           | 2        | $0.05 (20 ct)           |
| 4.7uF 25V 0805 Capacitor            | [LCSC](https://www.lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_Samsung-Electro-Mechanics-CL21A475KAQNNNE_C1779.html)                   | 1        | $0.23 (20 ct)           |
| 200nF 50V 0805 Capacitor            | [LCSC](https://www.lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_CCTC-TCC0805X7R204K500DT_C344170.html)                                  | 2        | $0.48 (50 ct)           |
| 1N4148 Flyback                      | [LCSC](https://lcsc.com/product-detail/Switching-Diodes_MDD-Microdiode-Semiconductor-1N4148WS-E_C41371421.html?s_z=n_1n4148)                                  | 4        | $0.06 (10 ct)           |
| 100k 125mW 0805 Resistor            | [LCSC](https://www.lcsc.com/product-detail/Chip-Resistor-Surface-Mount_FOJAN-FRC0805J104-TS_C2907293.html?s_z=n_100k)                                         | 4        | $0.13 (100 ct)          |
| 10k 125mW 0805 Resistor             | [LCSC](https://www.lcsc.com/product-detail/Chip-Resistor-Surface-Mount_FOJAN-FRC0805J103TS_C2930231.html?s_z=n_100k)                                          | 9        | $0.11 (100 ct)          |
| 220 125mW 0805 Resistor             | [LCSC](https://www.lcsc.com/product-detail/Chip-Resistor-Surface-Mount_FOJAN-FRC0805J221-TS_C2933537.html?s_z=n_100k)                                         | 4        | $0.13 (100 ct)          |
| 2.2k 125mW 0805 Resistor            | [LCSC](https://www.lcsc.com/product-detail/Chip-Resistor-Surface-Mount_FOJAN-FRC0805J222-TS_C2907303.html?s_z=n_100k)                                         | 2        | $0.13 (100 ct)          |
| SD Card Socket                      | [LCSC](https://lcsc.com/product-detail/SD-Card-Memory-Card-Connector_HOAUC-HYCW110-TF10-180B_C2962030.html)                                                   | 1        | $0.54 (10 ct)           |
| DPDT Switch |                        [LCSC](https://lcsc.com/product-detail/Slide-Switches_XKB-Connection-SS-3235S-L1_C500055.html?s_z=n_dpdt) | 1 | $0.52 |

> Target weight: **50g**

## Components which we already have:

| Item                    | Quantity | Total Mass on Drone |
| ----------------------- | -------- | ------------------- |
| Pin headers             | -        | -                   |
| 2 pin JST-2.0 connector | 5        | -                   |

<!--
| ESP32-S3-WROOM-1U-N4 | [DigiKey](https://www.digikey.com/en/products/detail/espressif-systems/ESP32-S3-WROOM-1U-N4/16162640) [LCSC](https://www.aliexpress.us/item/3256806096656294.html) | 1 | $3.61 + $4.99 | - |
| BetaFPV 1102 Brushless Motors | [Amazon](https://www.amazon.com/BETAFPV-18000KV-Brushless-Motor-Meteor75/dp/B0834P2LSY) | 4 | $45.99 | 11.2g |
-->
