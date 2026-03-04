#include "LED.h"

void led_Init(void)
{
    PORTC.F0 = 0;
    TRISC.F0 = 0;
}
void led_Toggle(void)
{
    PORTC.F0 = ~PORTC.F0;
}