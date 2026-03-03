#include "LED.h"

void LED_Init(unsigned short *tris, unsigned short pin)
{
     GPIO_SetPinDirection(tris, pin, OUTPUT);
}

void LED_On(unsigned short *port, unsigned short pin)
{
     GPIO_WritePin(port, pin, HIGH);
}

void LED_Off(unsigned short *port, unsigned short pin)
{
     GPIO_WritePin(port, pin, LOW);
}