#include "Switch.h"

void SWITCH_Init(uint8 pin) {
    if (pin == 0) { TRISB0_bit = 1; } // Interrupt Button (RB0)
    if (pin == 1) { TRISB1_bit = 1; } // Short Seq Switch (RB1)
    if (pin == 2) { TRISB2_bit = 1; } // Long Seq Switch (RB2)
}

uint8 SWITCH_Read(uint8 pin) {
    if (pin == 0) return RB0_bit;
    if (pin == 1) return RB1_bit;
    if (pin == 2) return RB2_bit;
    return HIGH; 
}