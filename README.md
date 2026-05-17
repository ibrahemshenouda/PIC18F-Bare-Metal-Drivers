# PIC18F46K20 Drivers (HAL & MCAL)

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Microchip](https://img.shields.io/badge/Microchip-E42024?style=for-the-badge&logo=microchip&logoColor=white)
![ATmega32 AVR](https://img.shields.io/badge/ATmega32%20AVR-00B2EE?style=for-the-badge&logo=microchip&logoColor=white)

This repository contains bare-metal embedded C drivers for the **Microchip PIC18F46K20** microcontroller. The project implements a clean, standard layered software architecture, strictly separating the **Hardware Abstraction Layer (HAL / ECU Layer)** from the **Microcontroller Abstraction Layer (MCAL)**.

It is designed for embedded systems projects that require reliable, modular, and reusable low-level hardware control without the overhead of an RTOS.

---

## 🎬 AVR Demos

### 🌡️ Temperature Sensor
> Real-time temperature readings from a sensor displayed live on screen, demonstrating ADC interfacing and data formatting on AVR.

https://github.com/user-attachments/assets/83b1cca2-19b5-4d6b-8c20-c1c62f2d3c71

---

### 🧮 Basic Calculator
> A fully functional calculator using a matrix keypad for input and a display for output, showcasing keypad scanning and arithmetic logic on AVR.

https://github.com/user-attachments/assets/7548e2f1-905d-4e85-b734-fb807bc9d035

---

### ⚙️ DC Motor — 2 Directions
> Demonstrates bidirectional DC motor control via an H-Bridge, smoothly spinning the motor clockwise and counter-clockwise on command.

https://github.com/user-attachments/assets/a145ce62-a717-46bf-88de-5899d59b26f1

---

### 🖥️ Character LCD
> Dynamic text rendering on a standard alphanumeric character LCD, demonstrating the full HD44780-compatible driver stack on AVR.

https://github.com/user-attachments/assets/09fc3f1f-ddda-471e-bf0f-c0c1f1ff1d11

---

## 🏗️ Architecture Layers

### 1. MCAL (Microcontroller Abstraction Layer)
This layer directly interacts with the PIC18F46K20 hardware registers. It encapsulates the hardware complexities and provides a standardized, hardware-independent API to the upper layers.

- **GPIO**: Comprehensive General Purpose Input/Output driver for pin/port direction and logic control.

  > Simulation of GPIO control — an LED is driven high/low by configuring pin direction and output logic level via the GPIO driver.

  <img width="1600" height="849" alt="GPIO LED simulation showing pin control" src="https://github.com/user-attachments/assets/9e57e125-9ce4-46eb-bdd3-5727aa3d4625" />

- **Interrupts**: Framework for handling External and Internal (Peripheral) interrupts.

  > Interrupt handling demonstration — an external hardware trigger fires an ISR, illustrating the priority-based interrupt framework.

  <img width="1600" height="849" alt="External interrupt simulation triggering an ISR" src="https://github.com/user-attachments/assets/aa9a5b22-7a49-4908-8591-15ecc19b372b" />

- **EEPROM**: Driver for reading and writing to the internal Data EEPROM.

- *Includes core configurations: `device_config.h`, `compiler.h`, `mcal_std_types.h`, establishing standard data types and compiler directives.*

---

### 2. ECU Layer / HAL (Electronic Control Unit / Hardware Abstraction Layer)
Sits on top of the MCAL and provides drivers for external electronic modules and actuators. These drivers are highly portable, relying solely on the MCAL APIs rather than direct register manipulation.

- **LED**: Standard LED toggling and state management.

  > LED driver simulation — demonstrates toggling and state management of an LED using only HAL API calls, with no direct register access.

  <img width="1600" height="849" alt="LED driver simulation showing toggle and state control" src="https://github.com/user-attachments/assets/38d8e6c1-d0b5-4101-8d8f-422df48bc6a3" />

- **Button**: Push-button interface logic.

  > Button driver simulation — physical button presses are read and debounced, cleanly reporting stable HIGH/LOW states to the application layer.

  <img width="1600" height="850" alt="Push-button debounce simulation" src="https://github.com/user-attachments/assets/ab9f928d-a470-4e0e-bdc8-05e4ef353328" />

- **Relay**: Switching control for electromagnetic relays.

  > Relay driver simulation — the HAL driver switches an electromagnetic relay on and off to control a higher-power load circuit.

  <img width="1600" height="849" alt="Relay switching simulation for load control" src="https://github.com/user-attachments/assets/980d705d-5ec8-4ea5-af16-baf15c034cc4" />

- **DC Motor**: Bidirectional DC motor control via H-Bridges.

  > DC motor control simulation — the HAL driver commands an H-Bridge to drive the motor in forward and reverse directions with speed control.

  <img width="1600" height="849" alt="DC motor H-Bridge bidirectional control simulation" src="https://github.com/user-attachments/assets/d7807127-57ab-473b-aba6-83762543f82f" />

- **7-Segment Display**: Driver for single and multiplexed 7-segment displays.

  > Single-digit 7-segment display — the driver decodes a numeric value and drives the correct segments to render a digit.

  <img width="1600" height="850" alt="Single 7-segment display showing digit output" src="https://github.com/user-attachments/assets/8f19f7f7-13df-4041-857f-7b4dc0afcc83" />

  > Multiplexed 7-segment display (2 digits) — rapid digit switching creates the illusion of a persistent multi-digit display.

  <img width="1600" height="848" alt="Multiplexed 7-segment display with 2 digits" src="https://github.com/user-attachments/assets/e979329a-dc3d-4f9f-932b-216731a9a6d2" />

  > Multiplexed 7-segment display (4 digits, config A) — four-digit counter demonstrating full multiplexed display management.

  <img width="1600" height="850" alt="4-digit multiplexed 7-segment display configuration A" src="https://github.com/user-attachments/assets/c398af73-af4b-4994-af18-afc5cba471a4" />

  > Multiplexed 7-segment display (4 digits, config B) — alternate wiring configuration validating driver flexibility across display layouts.

  <img width="1600" height="847" alt="4-digit multiplexed 7-segment display configuration B" src="https://github.com/user-attachments/assets/6bd41143-0417-4080-9578-1ebff2f04170" />

  > Multiplexed 7-segment display (counting sequence) — a live counting sequence showcasing smooth digit transitions and timing control.

  <img width="1600" height="849" alt="7-segment display counting sequence simulation" src="https://github.com/user-attachments/assets/b344cc7a-971a-4d22-8965-a41f642dd513" />

- **KeyPad**: Matrix keypad scanning and debouncing.

  > Matrix keypad simulation — rows and columns are scanned to detect key presses, with debouncing logic ensuring reliable and accurate input capture.

  <img width="1600" height="849" alt="Keyboard" src="https://github.com/user-attachments/assets/010d5598-dba8-457c-a1fd-71d1d37a4881" />


- **Character LCD (Chr_LCD)**: Driver for standard alphanumeric character LCDs (e.g., HD44780).

  > Character LCD simulation — the HD44780-compatible driver initializes the display and renders custom strings and characters across cursor positions.

  <img width="1600" height="848" alt="Character LCD driver simulation rendering text" src="https://github.com/user-attachments/assets/2e8706dc-2ef7-4bef-b68f-a10adc37e861" />

---

## 🛠️ Software Requirements

To compile and use these drivers, you will need the official Microchip toolchain:
- **MPLAB X IDE** (Recommended for project management and debugging)
- **XC8 Compiler** (For compiling C code targeting the PIC18 architecture)
- *(Optional)* **Proteus Design Suite** (For hardware simulation if physical hardware is unavailable)

---

## 🚀 Getting Started

1. **Clone the repository**
   ```bash
   git clone https://github.com/ibrahemshenouda/PIC18F46K20-Drivers.git
   ```

2. **Open the Project**
   Open the `Interface_Projects` folder as a project in **MPLAB X IDE**.

3. **Include the Headers**
   In your `application.c` (or main file), simply include the initialization headers to gain access to the drivers:
   ```c
   #include "application.h"
   // All ECU and MCAL drivers are initialized via ecu_layer_init.h
   ```

4. **Build and Flash**
   Click the "Build" hammer icon in MPLAB X to compile the source code via the XC8 compiler. Flash the generated `.hex` file to your PIC18F46K20 using a programmer (like PICkit 3/4) or load it into your simulator.
