#include "GPIO_interface.h"

void GPIO_SetPinDirection(char port, char pin, char direction)
{
    if(port == 'A')
    {
        if(direction == INPUT)
            TRISA |= (1 << pin);
        else
            TRISA &= ~(1 << pin);
    }

    else if(port == 'B')
    {
        if(direction == INPUT)
            TRISB |= (1 << pin);
        else
            TRISB &= ~(1 << pin);
    }
}

void GPIO_WritePin(char port, char pin, char value)
{
    if(port == 'B')
    {
        if(value == HIGH)
            PORTB |= (1 << pin);
        else
            PORTB &= ~(1 << pin);
    }
}

char GPIO_ReadPin(char port, char pin)
{
    if(port == 'A')
        return (PORTA >> pin) & 1;   // ? THIS IS CORRECT FOR PIC

    return 0;
}