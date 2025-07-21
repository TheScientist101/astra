<h1 align="center">astra</h1>

![Made with KiCAD](https://img.shields.io/badge/Made%20with-KiCAD-blue?style=flat-square&logo=kicad&color=blue) ![GitHub Repo stars](https://img.shields.io/github/stars/TheScientist101/astra?style=flat-square&color=orange) ![Code License](https://img.shields.io/badge/Code%20license-GPLv3-red?style=flat-square) ![CAD License](https://img.shields.io/badge/CAD%20license-OHL--W-green?style=flat-square)

<h3 align="center">An open source, low cost, extensible brushed drone.</h3><img align="center" src="assets/cad.png" alt="Drone" title="Drone" />

## What is Astra?

Astra is an `~80mm` brushed quadcopter. It it powered off of a single 1s Li-Po (`4.2V`), and uses four brushed motors.

Astra supports an optional FPV module, and includes a HAT-style pin interface on the flight controller.

We've also designed our own transmitter for Astra. The flight controller and transmitter use an `nRF24` to communicate with low latency.

Every part of Astra was designed from scratch - the flight controller, the transmitter, and the frame.

## Why is Astra?

Siddhant and I both love making things, but we've never made anything that moves before. What cooler of a thing is there that moves than a drone? With air voyage in our control, it would open the gate to even cooler projects, like imagine if you could play laser tag with a drone as your teammate or if you could have a drone that follows you around and takes pictures of you. The possibilities are endless!

That's why we decided to make our drone extensible. To me, modularity is the coolest part of any gadget. It allows you to add new features and capabilities without having to redesign the entire thing. Astra has a HAT-style pin interface called the DUCKDUCKGOOSE (Digital Unified Centralized Kibibit Device Universal Coding Knowledge Generic Operable Objective Service Extensible) Connector on the flight controller, which allows you to add new peripherals and sensors easily.

On the other hand, most drone projects we've seen online are expensive. While Hack Club is dope enough to have a [program that gives us free hardware](https://highway.hackclub.com), it is difficult to find a "DIY" drone that is relatively cheap that flies well. Since we wanted to make sure that our drone was actually good at flying, we decided to remove the onboard camera that we had in our initial design in place of a more traditional FPV system rather than just trying to make our own.

## Cost

All of the components for the drone and can be bought for around `$75`. (See the [`BOM`](./BOM.md) for more details!)

The bulk of this is actually the cost to buy the PCBs and stencil (which is anticipated to be around `$25`). The actual component cost is closer to `$50`.

> Note:
> Adding an FPV system to the drone is relatively costly. The FPV Camera + VTX module costs `$25`, which is actually on the cheaper end for these systems. The total cost with the FPV module is slightly less than `$100` before taxes and other fees.

(for hackclub) Even though the total cost of this drone is under `$150`, we will likely need to have multiple iterations of the PCB before we can get it working right.

## Technical Details

The Flight Controller uses an `STM32H750`. This is a powerful chip with plenty of GPIO pins for peripherals. We plan to implement a software OSD within the H7 for the FPV interface.

PCB files can be found within the `drone/pcb/` folder.

The Flight Controller uses the [betaflight](https://betaflight.com/) firmware. A betaflight config file as well as flashing instructions can be found in the `drone/firmware/` folder

The frame for the FC was designed in Onshape. CAD files can be found in `drone/cad/`;

**Peripherals**:

- `BMI270` - IMU
- `BMP388` - Barometer
- 2 `WS2812B`s
- 2 configurable buttons
- microSD Card Socket
- A 22 pin header for HAT-style extensions. Includes SWD, UART, SPI, I2C, and extra GPIOs.
- An extra UART connector.

The Ground Transmitter uses an `ESP32-C3-SuperMini` (a C3 chip similar to the XIAO that we already have on hand). It features:

- 3 `WS2812B`s
- 2 Joysticks, configured for mode 2 control
- 4 configurable buttons (+2 from the joysticks)

The PCB, firmware, and case for the transmitter can be found in the `controller/` folder

## Pictures

[**Full Schematic PDF**](assets/schematic.pdf)

**Copper Layers:**

![Front Copper Layer](assets/pcb-f.png) ![Inner Layer 1](assets/pcb-in1.png) ![Inner Layer 2](assets/pcb-in2.png) ![Back Copper Layer](assets/pcb-b.png)

**PCB 3D Render:**

![top](assets/astra-top.png) ![bottom](assets/astra-bottom.png)

**Controller PCB Render:**
![controller pcb front](assets/controller-pcb-f.png) ![controller pcb back](assets/controller-pcb-b.png)

**Controller Assembled Render:**
![controller assembled](assets/controller-case-final.png)
