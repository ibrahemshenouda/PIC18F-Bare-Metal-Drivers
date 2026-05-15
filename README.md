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
  <img width="1600" height="849" alt="Led" src="https://github.com/user-attachments/assets/9e57e125-9ce4-46eb-bdd3-5727aa3d4625" />

- **Interrupts**: Framework for handling External and Internal (Peripheral) interrupts.
  <img width="1600" height="849" alt="Interrupt_01" src="https://github.com/user-attachments/assets/aa9a5b22-7a49-4908-8591-15ecc19b372b" />

- **EEPROM**: Driver for reading and writing to the internal Data EEPROM.
- *Includes core configurations: `device_config.h`, `compiler.h`, `mcal_std_types.h`, establishing standard data types and compiler directives.*

### 2. ECU Layer / HAL (Electronic Control Unit / Hardware Abstraction Layer)
Sits on top of the MCAL and provides drivers for external electronic modules and actuators. These drivers are highly portable, relying solely on the MCAL APIs rather than direct register manipulation.
- **LED**: Standard LED toggling and state management.
  <img width="1600" height="849" alt="Led" src="https://github.com/user-attachments/assets/38d8e6c1-d0b5-4101-8d8f-422df48bc6a3" />

- **Button**: Push-button interface logic.
  <img width="1600" height="850" alt="Button" src="https://github.com/user-attachments/assets/ab9f928d-a470-4e0e-bdc8-05e4ef353328" />

- **Relay**: Switching control for electromagnetic relays.
   <img width="1600" height="849" alt="Relay" src="https://github.com/user-attachments/assets/980d705d-5ec8-4ea5-af16-baf15c034cc4" />

- **DC Motor**: Bidirectional DC motor control via H-Bridges.
   <img width="1600" height="849" alt="DC_Motor" src="https://github.com/user-attachments/assets/d7807127-57ab-473b-aba6-83762543f82f" />

- **7-Segment Display**: Driver for single and multiplexed 7-segment displays.
   <img width="1600" height="850" alt="Seven_Segmants_02" src="https://github.com/user-attachments/assets/8f19f7f7-13df-4041-857f-7b4dc0afcc83" />
   <img width="1600" height="848" alt="Seven_Segmants_01" src="https://github.com/user-attachments/assets/e979329a-dc3d-4f9f-932b-216731a9a6d2" />
  <img width="1600" height="850" alt="Seven_Segments_05" src="https://github.com/user-attachments/assets/c398af73-af4b-4994-af18-afc5cba471a4" />
  <img width="1600" height="847" alt="Seven_Segments_04" src="https://github.com/user-attachments/assets/6bd41143-0417-4080-9578-1ebff2f04170" />
  <img width="1600" height="849" alt="Seven_Segmants_03" src="https://github.com/user-attachments/assets/b344cc7a-971a-4d22-8965-a41f642dd513" />

- **KeyPad**: Matrix keypad scanning and debouncing.
  <img width="1600" height="849" alt="Keyboard" src="https://github.com/user-attachments/assets/091eb431-ac51-46a2-99cd-d2d45afabb3a" />

- **Character LCD (Chr_LCD)**: Driver for standard alphanumeric character LCDs (e.g., HD44780).
  <img width="1600" height="848" alt="LCD" src="https://github.com/user-attachments/assets/2e8706dc-2ef7-4bef-b68f-a10adc37e861" />


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
