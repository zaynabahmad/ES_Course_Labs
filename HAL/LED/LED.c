#include "LED.h"

void LED_Init(uint8 pin) {
    if (pin == 0) { TRISD0_bit = 0; RD0_bit = 0; } // Sequence LED 1
    if (pin == 1) { TRISD1_bit = 0; RD1_bit = 0; } // Sequence LED 2
    if (pin == 2) { TRISD2_bit = 0; RD2_bit = 0; } // Interrupt LED
}

void LED_On(uint8 pin) {
    if (pin == 0) { RD0_bit = 1; }
    if (pin == 1) { RD1_bit = 1; }
    if (pin == 2) { RD2_bit = 1; }
}

void LED_Off(uint8 pin) {
    if (pin == 0) { RD0_bit = 0; }
    if (pin == 1) { RD1_bit = 0; }
    if (pin == 2) { RD2_bit = 0; }
}

void LED_Toggle(uint8 pin) {
    if (pin == 0) { RD0_bit = ~RD0_bit; }
    if (pin == 1) { RD1_bit = ~RD1_bit; }
    if (pin == 2) { RD2_bit = ~RD2_bit; }
}