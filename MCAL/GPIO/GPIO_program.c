#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

void GPIO_voidSetPinDirection(u8 port, u8 pin, u8 dir)
{
    switch(port)
    {
        case 'A':
            if(dir == INPUT) SET_BIT(TRISA,pin);
            else CLR_BIT(TRISA,pin);
        break;

        case 'B':
            if(dir == INPUT) SET_BIT(TRISB,pin);
            else CLR_BIT(TRISB,pin);
        break;
    }
}

void GPIO_voidSetPinValue(u8 port, u8 pin, u8 val)
{
    switch(port)
    {
        case 'A':
            if(val == HIGH) SET_BIT(PORTA,pin);
            else CLR_BIT(PORTA,pin);
        break;

        case 'B':
            if(val == HIGH) SET_BIT(PORTB,pin);
            else CLR_BIT(PORTB,pin);
        break;
    }
}