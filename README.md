# Smart Mobile Manipulator Controller (PIC16F877A)
**Author:** Matthew Nader (202300103)  
**Course:** Embedded Systems (CIE349)

## 🚀 Project Overview
This project implements a fully functional layered architecture driver suite for the PIC16F877A. It features a unified "Smart Controller" that manages motor speeds, emergency systems, and dual-protocol telemetry.

### 🛠 Implemented Drivers
* **MCAL:** GPIO, ADC, Timer0, PWM, UART, SPI, I2C, Interrupt Manager
* **HAL:** LED

## 🏗 Key Architectural Feature: MSSP State Machine
The PIC16F877A shares hardware pins (RC3/RC4) for both I2C and SPI. To overcome this:
1.  **Boot Phase:** The system initializes **I2C** to simulate reading configuration data.
2.  **Runtime Phase:** The hardware is reconfigured for **SPI** to stream high-speed motor telemetry.

## 📺 Simulation Demo
![System Demo](Docs/simulation_demo.gif)

## 🕹 How to Test
1. **Potentiometer (RA0):** Adjusts motor speed (PWM duty cycle on RC2).
2. **Button (RB0):** Triggers Emergency Stop (Kills motor, turns on Red LED).
3. **Virtual Terminal:** - Type `f` for Forward.
   - Type `r` for Reverse.
   - Type `s` for Stop.
4. **Analyzers:** Watch the I2C debugger at boot, then SPI debugger for live speed data.
