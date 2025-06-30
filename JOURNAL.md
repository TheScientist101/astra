---
title: "Astra"
author: "TheScientist101 and grimsteel"
description: "Autonomous FPV drone"
created_at: "2025-05-23"
---

### Total hours:

- TheScientist101: 16
- grimsteel: 26

# May 23rd:

TheScientist101 + grimsteel

**Hours spent: 3 each (huddle)**

We decided the initial drone features.

We plan on making a laser tag drone:

- Each player will control their own drone. (We'll be manufacturing two for this.)
- The objective of the game will be for the drones to find and tag each other using the attached remote controllable laser and IR sensors.

Other features include semi-autonomous navigation as well as a camera for photos/FPV.

Our main concern is the thrust and the weight of the drone.

This is what we spent the majority of the time figuring out, but we learned a lot about aerodynamics.

We decided on an initial BOM, which is included in our [Full planning document](./PLANNING.md)

# June 4th:

TheScientist101 + grimsteel

**Hours spent: 3.5 each (huddle)**

We did extensive research into components and created a more thorough [BOM](./BOM.md)

- We decided to use an STM32H7 microcontroller because of it's increased processing capabilities compared to the ESP32 and its compatibility with camera protocols, specifically DCMI.
- We decided on a brushless motor and propellers to allow us a total weight of 80 grams.
- We picked a camera model and did some research into the supporting components.
- We did some initial calculations regarding the weight of the drone components using [ecalc](https://ecalc.ch).
- We did some research on batteries, but that honestly bamboozled us more, so the battery is very much TBD.

We also decided to deprioritize laser tag, instead focusing on a modular design.

We are approaching our budget pretty quickly... We must keep in mind the cost of iterations and small things such as solder stencil.

# June 10th

TheScientist101 + grimsteel

**Hours spent: 2.5 each (huddle)**

We finished up our component research. ([BOM](./BOM.md))

- After considering the components and precision needed (ESC) to properly control a brushless motor, we decided to use a brushed motor instead of a brushless motor to decrease the overall complexity of the project
- We did some research regarding motor control (MOSFETS) and chose the components for this
- We also picked the remaining miscellaneous components on the PCB (Flash, IMU)
- We're finally ready to start the PCB design!
- We made a rough sketch of the device, which is shown below:

![Sketch](./assets/initial_sketch.png)

# June 10th

TheScientist101 + grimsteel

**Hours spent: 2 each (huddle)**

We started the initial schematic design

- We created multiple subsheets to make collaboration easier (and to reduce merge conflicts)
- We did some initial wiring for the STM32, flash, and power supply

![STM32 Schematic](./assets/initial-schematic-stm32.png)

# June 11th

TheScientist101 + grimsteel

**Hours spent: 1 each (huddle)**

We continued the schematic design

- We added more power stuff for the STM32.
- We looked more into STM32 datasheet to figure out what was needed and what capacitor values to use.
- Throughout the day, we did some research into other drone projects to see how they did their schematics and what components they used. (not logged for time, but thought this was worth mentioning)

![STM32 Schematic](./assets/day-2-schematic-stm32.png)

# June 12th

TheScientist101 + grimsteel
**Hours spent: 2 each (huddle)**

We continued the schematic design

- Siddhant worked on the motor control MOSFET things.
- He researched which MOSFETs were capable of handling the current and voltage we needed.
- He researched better voltage regulators.
- Urjith finished up the basic STM32 wiring.
- He researched which transceiver to use for the drone. We decided to use the NRF24L01+ transceiver because of its low cost and good range.
- He started wiring the transceiver to the STM32.

![Peripherals Schematic](./assets/day-3-schematic-peripherals.png) ![MCU Schematic](./assets/day-3-schematic-mcu.png) ![Motor Controller Schematic](./assets/day-3-schematic-motor.png)

# June 13th-14th

grimsteel

**Hours spent: 5**

I added almost all of the peripherals to the schematic:

- **JTAG connector for debugging** - this one was relatively simple as it's just a bunch of connections
- **NRF Wireless Chip** - Urjith had started this already, so I just finished the wiring. I decided to use the SPI2 peripheral instead of SPI1 (more on this below)
- **OV5640 Camera** - This was definitely the most complex. The Adafruit breakout board for the OV5640 was a very helpful reference for figuring out the wiring and components/pullups needed. I had to use 2 additional LDOs as well. I connected this to the STM32's DCMI interface as well as the I2C1 peripheral.
- **IMU** - This was relatively simple. I used a Sparkfun breakout board as a reference, and connected it to the I2C2 peripheral. I'm not sure whether multiple I2C subs can exist on the same peripheral, but we have enough pins on the STM32 to just use another.

![Peripherals](./assets/day-5-peripherals.png)

I also added a voltage divider to the battery so we can measure its voltage (using ADC1)

![Battery](./assets/day-5-bat-vd.png)

I decided to use an external 25 MHz crystal (recommended by the datasheet)

![rocket](./assets/day-5-crystal.png)

The hardest part of all of this was figuring out where to connect everything to the STM32. It's not like an ESP32 which has a GPIO matrix, which means there are specific pins for SPI and I2C and the other peripherals.

The STM32CubeMX software was a huge help with this. It helped me pick which pins to use to avoid conflicts.

![cube](./assets/day-5-stm-cube.png)

With this configuration, SPI1 is actually unusable, which is why I used SPI2.

Here's the resulting schematic:

![mcu](./assets/day-5-mcu.png)

I did end up altering some of the power circuitry again (ferrite bead between VDDA/VREF and +3.3V)

# June 20th

TheScientist101 + grimsteel
**Hours spent: 2 each (huddle)**

Siddhant started routing the PCB. He finalized the placement of most of the components and started routing the power traces. To improve signal quality, we decided to use four layers instead of two, and we will need to move the components around and re-route the PCB.

![PCB Placement](./assets/day-6-routing.png)

Urjith added the micro secure digital card interface socket connector to the schematic. We researched the microSD specification and the necessity for pull-up resistors on the data lines.

![SD Card Schematic](./assets/day-6-sd-card.png)

We still need to add a HAT interface connector socket for extensibility and modularity, but we will do that later.

# June 21st-30th

grimsteel

**Hours spent: 5**

Both of us have been pretty busy this past week, but I've been gradually routing the new PCB.

We switched to 4 layers for better signal quality and easier routing, so we had to pretty much start from scratch.

![Routing](./assets/day-7-routing.png)

Most of the routing is done, but we still need to do the last motor (figuring out where to place this will be hard) and a couple of the camera traces.

The last step will be to connect all of the battery nets. This is going to be pretty difficult as the tracks for the motors need to be really thick:

![Track Width](./assets/day-7-current.png)

Routing them on the external layers would require only a 0.4mm wide track, but there's not really much space left there.

The `In2.Cu` layer is _supposed_ to be for power, and this is where I'll probably end up routing them. The issue is that it's an internal layer, and the copper weight will be 0.5 oz/ft^2 (we could make it 1 oz, but we need to minimize weigh)

2 layer PCBs can be under 100x100mm before JLCPCB starts getting super expensive, but the cutoff is 50x50mm for 4 layers. Thankfully, we're just under that right now.
