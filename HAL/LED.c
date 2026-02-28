#include "LED.h"

void LED_Init(void)
{
    TRISC.F0 = 0;
    PORTC.F0 = 0;
}

void LED_Toggle(void)
{
    PORTC.F0 = ~PORTC.F0;
}