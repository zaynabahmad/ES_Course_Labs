#include "switch.h"

void SWITCH_Init(uint8 pin) {
    // pin is abstract here; INT0 is always RB0 on this chip
    TRISB.F0 = 1; 
}