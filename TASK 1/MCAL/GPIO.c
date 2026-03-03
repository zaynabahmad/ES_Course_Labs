#include "GPIO.h"

void GPIO_SetPinDirection(unsigned short *tris, unsigned short pin, unsigned short direction)
{
     if(direction == OUTPUT)
         *tris &= ~(1 << pin);
     else
         *tris |= (1 << pin);
}

void GPIO_WritePin(unsigned short *port, unsigned short pin, unsigned short value)
{
     if(value == HIGH)
         *port |= (1 << pin);
     else
         *port &= ~(1 << pin);
}

unsigned short GPIO_ReadPin(unsigned short *port, unsigned short pin)
{
     return ((*port >> pin) & 1);
}