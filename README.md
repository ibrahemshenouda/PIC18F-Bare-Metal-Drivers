# PIC18F46K20 Drivers (HAL & MCAL)

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Microchip](https://img.shields.io/badge/Microchip-E42024?style=for-the-badge&logo=microchip&logoColor=white)

This repository contains bare-metal embedded C drivers for the **Microchip PIC18F46K20** microcontroller. The project implements a clean, standard layered software architecture, strictly separating the **Hardware Abstraction Layer (HAL / ECU Layer)** from the **Microcontroller Abstraction Layer (MCAL)**. 

It is designed for embedded systems projects that require reliable, modular, and reusable low-level hardware control without the overhead of an RTOS.

---

## 🏗️ Architecture Layers

### 1. MCAL (Microcontroller Abstraction Layer)
This layer directly interacts with the PIC18F46K20 hardware registers. It encapsulates the hardware complexities and provides a standardized, hardware-independent API to the upper layers.
- **GPIO**: Comprehensive General Purpose Input/Output driver for pin/port direction and logic control.
- **Interrupts**: Framework for handling External and Internal (Peripheral) interrupts.
- **EEPROM**: Driver for reading and writing to the internal Data EEPROM.
- *Includes core configurations: `device_config.h`, `compiler.h`, `mcal_std_types.h`, establishing standard data types and compiler directives.*

### 2. ECU Layer / HAL (Electronic Control Unit / Hardware Abstraction Layer)
Sits on top of the MCAL and provides drivers for external electronic modules and actuators. These drivers are highly portable, relying solely on the MCAL APIs rather than direct register manipulation.
- **LED**: Standard LED toggling and state management.
- **Button**: Push-button interface logic.
- **Relay**: Switching control for electromagnetic relays.
- **DC Motor**: Bidirectional DC motor control via H-Bridges.
- **7-Segment Display**: Driver for single and multiplexed 7-segment displays.
- **KeyPad**: Matrix keypad scanning and debouncing.
- **Character LCD (Chr_LCD)**: Driver for standard alphanumeric character LCDs (e.g., HD44780).

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
