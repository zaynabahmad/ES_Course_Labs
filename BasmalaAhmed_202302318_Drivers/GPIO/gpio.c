#include "gpio.h"

/* Example registers for AVR (ATmega32) */
#define DDRA *((volatile unsigned char*)0x3A)
#define PORTA_REG *((volatile unsigned char*)0x3B)

void GPIO_setPinDirection(unsigned char port, unsigned char pin, unsigned char direction)
{
    if(port == PORTA)
    {
        if(direction == OUTPUT)
            DDRA |= (1 << pin);
        else
            DDRA &= ~(1 << pin);
    }
}

void GPIO_writePin(unsigned char port, unsigned char pin, unsigned char value)
{
    if(port == PORTA)
    {
        if(value)
            PORTA_REG |= (1 << pin);
        else
            PORTA_REG &= ~(1 << pin);
    }
}