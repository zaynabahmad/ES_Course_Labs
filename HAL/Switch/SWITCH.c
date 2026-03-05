#include "SWITCH.h"

void SWITCH_Init(uint8 pin)
{
    TRISB |= (1 << pin);   // Input
}
uint8 SWITCH_Read(uint8 pin)
{
    return (PORTB >> pin) & 1;
}