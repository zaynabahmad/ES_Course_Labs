#include "GPIO_interface.h"
#include "../../Services/bit_math.h"

/* NOTE: In mikroC PRO for PIC, all SFRs (TRISA, PORTA, TRISB, PORTB, etc.)
   are built-in — no #include needed. Do NOT use #include <xc.h> */

void GPIO_SetPinDirection(uint8 port, uint8 pin, uint8 direction)
{
    switch(port)
    {
        case GPIO_PORTA:
            if(direction == GPIO_INPUT)  SET_BIT(TRISA, pin);
            else                         CLEAR_BIT(TRISA, pin);
            break;

        case GPIO_PORTB:
            if(direction == GPIO_INPUT)  SET_BIT(TRISB, pin);
            else                         CLEAR_BIT(TRISB, pin);
            break;

        case GPIO_PORTC:
            if(direction == GPIO_INPUT)  SET_BIT(TRISC, pin);
            else                         CLEAR_BIT(TRISC, pin);
            break;

        case GPIO_PORTD:
            if(direction == GPIO_INPUT)  SET_BIT(TRISD, pin);
            else                         CLEAR_BIT(TRISD, pin);
            break;

        case GPIO_PORTE:
            if(direction == GPIO_INPUT)  SET_BIT(TRISE, pin);
            else                         CLEAR_BIT(TRISE, pin);
            break;

        default: break;
    }
}

void GPIO_WritePin(uint8 port, uint8 pin, uint8 value)
{
    switch(port)
    {
        case GPIO_PORTA:
            if(value == GPIO_HIGH)  SET_BIT(PORTA, pin);
            else                    CLEAR_BIT(PORTA, pin);
            break;

        case GPIO_PORTB:
            if(value == GPIO_HIGH)  SET_BIT(PORTB, pin);
            else                    CLEAR_BIT(PORTB, pin);
            break;

        case GPIO_PORTC:
            if(value == GPIO_HIGH)  SET_BIT(PORTC, pin);
            else                    CLEAR_BIT(PORTC, pin);
            break;

        case GPIO_PORTD:
            if(value == GPIO_HIGH)  SET_BIT(PORTD, pin);
            else                    CLEAR_BIT(PORTD, pin);
            break;

        case GPIO_PORTE:
            if(value == GPIO_HIGH)  SET_BIT(PORTE, pin);
            else                    CLEAR_BIT(PORTE, pin);
            break;

        default: break;
    }
}

uint8 GPIO_ReadPin(uint8 port, uint8 pin)
{
    uint8 val = GPIO_LOW;

    switch(port)
    {
        case GPIO_PORTA: val = READ_BIT(PORTA, pin); break;
        case GPIO_PORTB: val = READ_BIT(PORTB, pin); break;
        case GPIO_PORTC: val = READ_BIT(PORTC, pin); break;
        case GPIO_PORTD: val = READ_BIT(PORTD, pin); break;
        case GPIO_PORTE: val = READ_BIT(PORTE, pin); break;
        default: break;
    }

    return val;
}