#include "SWITCH.h"

void SWITCH_Init(uint8 pin)
{
    TRISB |= (1 << pin);   // Input
}