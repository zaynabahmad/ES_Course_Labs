# Lab 2 – External Interrupt INT0 (PIC16F877A)

## Objective
Toggle an LED using external interrupt INT0.

## Pin Mapping
- Button: RB0 / INT0
- LED: RB1

## Behavior
- RB0 is pulled up to VCC using 10k resistor.
- On button press, RB0 goes LOW (falling edge) → INT0 triggers.
- ISR calls a callback that toggles LED on RB1.

## Build
- mikroC PRO for PIC
- MCU: PIC16F877A
- Clock: 8 MHz

## Proteus Wiring
- RB1 → 330Ω → LED → GND
- RB0 → 10k → VCC
- RB0 → Button → GND
- MCLR → 10k → VCC