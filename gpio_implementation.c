#include "gpio_interface.h"

/* ================= SET PIN DIRECTION ================= */
void set_pin_direction(u8 port , u8 pin , u8 direction)
{
    switch(port)
    {
        case _PORTA:
            if(direction == OUTPUT)
                TRISA &= ~(1<<pin);
            else
                TRISA |= (1<<pin);
        break;

        case _PORTB:
            if(direction == OUTPUT)
                TRISB &= ~(1<<pin);
            else
                TRISB |= (1<<pin);
        break;

        case _PORTC:
            if(direction == OUTPUT)
                TRISC &= ~(1<<pin);
            else
                TRISC |= (1<<pin);
        break;

        case _PORTD:
            if(direction == OUTPUT)
                TRISD &= ~(1<<pin);
            else
                TRISD |= (1<<pin);
        break;

        case _PORTE:
            if(direction == OUTPUT)
                TRISE &= ~(1<<pin);
            else
                TRISE |= (1<<pin);
        break;
    }
}

/* ================= SET PIN VALUE ================= */
void set_pin_value(u8 port , u8 pin , u8 value)
{
    switch(port)
    {
        case _PORTA:
            if(value == GPIO_LOW)
                PORTA &= ~(1<<pin);
            else
                PORTA |= (1<<pin);
        break;

        case _PORTB:
            if(value == GPIO_LOW)
                PORTB &= ~(1<<pin);
            else
                PORTB |= (1<<pin);
        break;

        case _PORTC:
            if(value == GPIO_LOW)
                PORTC &= ~(1<<pin);
            else
                PORTC |= (1<<pin);
        break;

        case _PORTD:
            if(value == GPIO_LOW)
                PORTD &= ~(1<<pin);
            else
                PORTD |= (1<<pin);
        break;

        case _PORTE:
            if(value == GPIO_LOW)
                PORTE &= ~(1<<pin);
            else
                PORTE |= (1<<pin);
        break;
    }
}

/* ================= GET PIN VALUE ================= */
u8 get_pin_value(u8 port , u8 pin)
{
    switch(port)
    {
        case _PORTA: return (PORTA >> pin) & 1;
        case _PORTB: return (PORTB >> pin) & 1;
        case _PORTC: return (PORTC >> pin) & 1;
        case _PORTD: return (PORTD >> pin) & 1;
        case _PORTE: return (PORTE >> pin) & 1;
    }

    return 0;
}