//#include "LED.h"

//void LED_Init(void)
//{
//    TRISD.B0 = 0;   // RD0 output
//    PORTD.B0 = 0;   // LED OFF
//}

//void LED_Toggle(void)
//{
//    PORTD.B0 = ~PORTD.B0;
//}

#include "LED.h"

void LED_Init(void)
{
    TRISD.B0 = 0;   // LED1 output (RD0)
    TRISD.B1 = 0;   // LED2 output (RD1)
    PORTD.B0 = 0;
    PORTD.B1 = 0;
}

void LED_On(void)
{
    PORTD.B0 = 1;
    PORTD.B1 = 1;
}

void LED_Off(void)
{
    PORTD.B0 = 0;
    PORTD.B1 = 0;
}

void LED_Toggle(void)
{
    PORTD.B0 ^= 1;
    PORTD.B1 ^= 1;
}