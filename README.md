
 External Interrupt Driver (Layered Architecture)
Project Overview
This project implements an External Interrupt (INT0) driver for the PIC16F887 microcontroller using a Layered Software Architecture. The system is designed to toggle the state of an LED connected to RD0 whenever a push button connected to RB0/INT is pressed.

Architecture Layers
The project is organized into three distinct layers to ensure modularity and hardware abstraction:

MCAL (Microcontroller Abstraction Layer): * Responsible for direct register manipulation.

Configures INTCON and OPTION_REG for the External Interrupt.

Sets up RB0 as a digital input with internal pull-up enabled.

HAL (Hardware Abstraction Layer): * Provides an abstraction for external components (the LED).

Contains functions like LED_Init() and LED_Toggle().

Application Layer: * Contains the main() function and the Interrupt Service Routine (ISR).

Handles the logic: When the interrupt occurs, it calls the LED_Toggle() function and resets the interrupt flag (INTF).

Hardware Requirements (Proteus)
MCU: PIC16F887.

Input: Push Button connected to RB0 (External Interrupt 0).

Output: LED connected to RD0 through a 330Ω resistor.

Reset: MCLR pin connected to 5V to ensure the MCU operates correctly.

How it Works
Unlike the polling method used in Week 2, this project uses an Event-Driven approach. The CPU stays idle in an infinite loop until the user presses the button. At that exact moment, the hardware triggers a jump to the interrupt() function, ensuring a near-instantaneous response.
