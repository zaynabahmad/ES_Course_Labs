#include "GPIO_interface.h"
#include "GPIO_private.h"

void GPIO_SetPinDirection(unsigned char port, unsigned char pin, unsigned char direction)
{
    switch(port)
    {
        case PORTA:
            if(direction == INPUT) TRISA_REG |= (1 << pin);
            else TRISA_REG &= ~(1 << pin);
            break;

        case PORTB:
            if(direction == INPUT) TRISB_REG |= (1 << pin);
            else TRISB_REG &= ~(1 << pin);
            break;

        case PORTC:
            if(direction == INPUT) TRISC_REG |= (1 << pin);
            else TRISC_REG &= ~(1 << pin);
            break;

        case PORTD:
            if(direction == INPUT) TRISD_REG |= (1 << pin);
            else TRISD_REG &= ~(1 << pin);
            break;

        case PORTE:
            if(direction == INPUT) TRISE_REG |= (1 << pin);
            else TRISE_REG &= ~(1 << pin);
            break;
    }
}

void GPIO_WritePin(unsigned char port, unsigned char pin, unsigned char value)
{
    switch(port)
    {
        case PORTA:
            if(value == HIGH) PORTA_REG |= (1 << pin);
            else PORTA_REG &= ~(1 << pin);
            break;

        case PORTB:
            if(value == HIGH) PORTB_REG |= (1 << pin);
            else PORTB_REG &= ~(1 << pin);
            break;

        case PORTC:
            if(value == HIGH) PORTC_REG |= (1 << pin);
            else PORTC_REG &= ~(1 << pin);
            break;

        case PORTD:
            if(value == HIGH) PORTD_REG |= (1 << pin);
            else PORTD_REG &= ~(1 << pin);
            break;

        case PORTE:
            if(value == HIGH) PORTE_REG |= (1 << pin);
            else PORTE_REG &= ~(1 << pin);
            break;
    }
}

unsigned char GPIO_ReadPin(unsigned char port, unsigned char pin)
{
    unsigned char value = 0;

    switch(port)
    {
        case PORTA:
            value = (PORTA_REG >> pin) & 1;
            break;

        case PORTB:
            value = (PORTB_REG >> pin) & 1;
            break;

        case PORTC:
            value = (PORTC_REG >> pin) & 1;
            break;

        case PORTD:
            value = (PORTD_REG >> pin) & 1;
            break;

        case PORTE:
            value = (PORTE_REG >> pin) & 1;
            break;
    }

    return value;
}

void GPIO_TogglePin(unsigned char port, unsigned char pin)
{
    switch(port)
    {
        case PORTA: PORTA_REG ^= (1 << pin); break;
        case PORTB: PORTB_REG ^= (1 << pin); break;
        case PORTC: PORTC_REG ^= (1 << pin); break;
        case PORTD: PORTD_REG ^= (1 << pin); break;
        case PORTE: PORTE_REG ^= (1 << pin); break;
    }
}