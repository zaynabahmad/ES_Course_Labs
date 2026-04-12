#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "Services/bit_math.h"

void GPIO_SetPinDirection(unsigned char port, unsigned char pin, unsigned char dir)
{
    switch (port)
    {
        case GPIO_PORTA:
            if (dir == GPIO_INPUT) SET_BIT(TRISA_REG, pin); else CLR_BIT(TRISA_REG, pin);
            break;
        case GPIO_PORTB:
            if (dir == GPIO_INPUT) SET_BIT(TRISB_REG, pin); else CLR_BIT(TRISB_REG, pin);
            break;
        case GPIO_PORTC:
            if (dir == GPIO_INPUT) SET_BIT(TRISC_REG, pin); else CLR_BIT(TRISC_REG, pin);
            break;
        case GPIO_PORTD:
            if (dir == GPIO_INPUT) SET_BIT(TRISD_REG, pin); else CLR_BIT(TRISD_REG, pin);
            break;
        case GPIO_PORTE:
            if (dir == GPIO_INPUT) SET_BIT(TRISE_REG, pin); else CLR_BIT(TRISE_REG, pin);
            break;
    }
}

void GPIO_WritePin(unsigned char port, unsigned char pin, unsigned char val)
{
    switch (port)
    {
        case GPIO_PORTA:
            if (val == GPIO_HIGH) SET_BIT(PORTA_REG, pin); else CLR_BIT(PORTA_REG, pin);
            break;
        case GPIO_PORTB:
            if (val == GPIO_HIGH) SET_BIT(PORTB_REG, pin); else CLR_BIT(PORTB_REG, pin);
            break;
        case GPIO_PORTC:
            if (val == GPIO_HIGH) SET_BIT(PORTC_REG, pin); else CLR_BIT(PORTC_REG, pin);
            break;
        case GPIO_PORTD:
            if (val == GPIO_HIGH) SET_BIT(PORTD_REG, pin); else CLR_BIT(PORTD_REG, pin);
            break;
        case GPIO_PORTE:
            if (val == GPIO_HIGH) SET_BIT(PORTE_REG, pin); else CLR_BIT(PORTE_REG, pin);
            break;
    }
}

unsigned char GPIO_ReadPin(unsigned char port, unsigned char pin)
{
    switch (port)
    {
        case GPIO_PORTA: return GET_BIT(PORTA_REG, pin);
        case GPIO_PORTB: return GET_BIT(PORTB_REG, pin);
        case GPIO_PORTC: return GET_BIT(PORTC_REG, pin);
        case GPIO_PORTD: return GET_BIT(PORTD_REG, pin);
        case GPIO_PORTE: return GET_BIT(PORTE_REG, pin);
    }
    return 0;
}

void GPIO_TogglePin(unsigned char port, unsigned char pin)
{
    switch (port)
    {
        case GPIO_PORTA: TOG_BIT(PORTA_REG, pin); break;
        case GPIO_PORTB: TOG_BIT(PORTB_REG, pin); break;
        case GPIO_PORTC: TOG_BIT(PORTC_REG, pin); break;
        case GPIO_PORTD: TOG_BIT(PORTD_REG, pin); break;
        case GPIO_PORTE: TOG_BIT(PORTE_REG, pin); break;
    }
}