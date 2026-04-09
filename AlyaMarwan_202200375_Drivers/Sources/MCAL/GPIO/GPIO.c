#include "gpio.h"
#include "bit_math.h"


void GPIO_SetPinDirection(uint8 port, uint8 pin, uint8 direction)
{
    switch(port)
    {
        case GPIO_PORTA:
            if(direction == GPIO_OUTPUT) CLR_BIT(TRISA, pin);
            else                         SET_BIT(TRISA, pin);
            break;
        case GPIO_PORTB:
            if(direction == GPIO_OUTPUT) CLR_BIT(TRISB, pin);
            else                         SET_BIT(TRISB, pin);
            break;
        case GPIO_PORTC:
            if(direction == GPIO_OUTPUT) CLR_BIT(TRISC, pin);
            else                         SET_BIT(TRISC, pin);
            break;
        case GPIO_PORTD:
            if(direction == GPIO_OUTPUT) CLR_BIT(TRISD, pin);
            else                         SET_BIT(TRISD, pin);
            break;
        case GPIO_PORTE:
            if(direction == GPIO_OUTPUT) CLR_BIT(TRISE, pin);
            else                         SET_BIT(TRISE, pin);
            break;
    }
}

void GPIO_WritePin(uint8 port, uint8 pin, uint8 value)
{
    switch(port)
    {
        case GPIO_PORTA:
            if(value == GPIO_HIGH) SET_BIT(PORTA, pin);
            else                   CLR_BIT(PORTA, pin);
            break;
        case GPIO_PORTB:
            if(value == GPIO_HIGH) SET_BIT(PORTB, pin);
            else                   CLR_BIT(PORTB, pin);
            break;
        case GPIO_PORTC:
            if(value == GPIO_HIGH) SET_BIT(PORTC, pin);
            else                   CLR_BIT(PORTC, pin);
            break;
        case GPIO_PORTD:
            if(value == GPIO_HIGH) SET_BIT(PORTD, pin);
            else                   CLR_BIT(PORTD, pin);
            break;
        case GPIO_PORTE:
            if(value == GPIO_HIGH) SET_BIT(PORTE, pin);
            else                   CLR_BIT(PORTE, pin);
            break;
    }
}

uint8 GPIO_ReadPin(uint8 port, uint8 pin)
{
    uint8 pinValue = GPIO_LOW;
    switch(port)
    {
        case GPIO_PORTA: pinValue = GET_BIT(PORTA, pin); break;
        case GPIO_PORTB: pinValue = GET_BIT(PORTB, pin); break;
        case GPIO_PORTC: pinValue = GET_BIT(PORTC, pin); break;
        case GPIO_PORTD: pinValue = GET_BIT(PORTD, pin); break;
        case GPIO_PORTE: pinValue = GET_BIT(PORTE, pin); break;
    }
    return pinValue;
}

void GPIO_SetPortDirection(uint8 port, uint8 direction)
{
    switch(port)
    {
        case GPIO_PORTA: TRISA = direction; break;
        case GPIO_PORTB: TRISB = direction; break;
        case GPIO_PORTC: TRISC = direction; break;
        case GPIO_PORTD: TRISD = direction; break;
        case GPIO_PORTE: TRISE = direction; break;
    }
}

void GPIO_WritePort(uint8 port, uint8 value)
{
    switch(port)
    {
        case GPIO_PORTA: PORTA = value; break;
        case GPIO_PORTB: PORTB = value; break;
        case GPIO_PORTC: PORTC = value; break;
        case GPIO_PORTD: PORTD = value; break;
        case GPIO_PORTE: PORTE = value; break;
    }
}

uint8 GPIO_ReadPort(uint8 port)
{
    uint8 portValue = 0;
    switch(port)
    {
        case GPIO_PORTA: portValue = PORTA; break;
        case GPIO_PORTB: portValue = PORTB; break;
        case GPIO_PORTC: portValue = PORTC; break;
        case GPIO_PORTD: portValue = PORTD; break;
        case GPIO_PORTE: portValue = PORTE; break;
    }
    return portValue;
}