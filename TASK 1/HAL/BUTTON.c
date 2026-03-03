#include "BUTTON.h"

void Button_Init(unsigned short *tris, unsigned short pin)
{
     GPIO_SetPinDirection(tris, pin, INPUT);
}

unsigned short Button_Read(unsigned short *port, unsigned short pin)
{
     return GPIO_ReadPin(port, pin);
}