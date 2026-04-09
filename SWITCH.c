#include "SWITCH.h"

void SWITCH_Init(Switch_PinID_t pin)
{

    TRISB |= (1 << pin);
}