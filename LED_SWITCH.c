#include "LED_SWITCH.h"

void LED_On(void)
{
    PORTB.F0 = 1;
    PORTB.F1 = 1;
}

void LED_Off(void)
{
    PORTB.F0 = 0;
    PORTB.F1 = 0;
}

unsigned char SW1_Read(void)
{
    return PORTA.F0;
}

unsigned char SW2_Read(void)
{
    return PORTA.F1;
}