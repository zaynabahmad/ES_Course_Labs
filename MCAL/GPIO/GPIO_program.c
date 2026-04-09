#include "GPIO_private.h"
#include "GPIO_interface.h"

// Set pin direction
void GPIO_SetPinDirection(char port, char pin, char direction)
{
    if (port == 'A')
    {
        if (direction == OUTPUT)
            DDRA |= (1 << pin);
        else
            DDRA &= ~(1 << pin);
    }
    else if (port == 'B')
    {
        if (direction == OUTPUT)
            DDRB |= (1 << pin);
        else
            DDRB &= ~(1 << pin);
    }
}

// Write value to pin
void GPIO_WritePin(char port, char pin, char value)
{
    if (port == 'A')
    {
        if (value == HIGH)
            PORTA |= (1 << pin);
        else
            PORTA &= ~(1 << pin);
    }
    else if (port == 'B')
    {
        if (value == HIGH)
            PORTB |= (1 << pin);
        else
            PORTB &= ~(1 << pin);
    }
}

// Read pin value
char GPIO_ReadPin(char port, char pin)
{
    if (port == 'A')
        return (PINA >> pin) & 1;
    else if (port == 'B')
        return (PINB >> pin) & 1;

    return 0;
}