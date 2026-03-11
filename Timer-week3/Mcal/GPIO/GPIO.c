#include "GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"


void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction)
{
    if (Direction == GPIO_OUTPUT)
    {
        switch (Port)
        {
            case GPIO_PORTA: CLR_BIT(TRISA, Pin); break;
            case GPIO_PORTB: CLR_BIT(TRISB, Pin); break;
            case GPIO_PORTC: CLR_BIT(TRISC, Pin); break;
            case GPIO_PORTD: CLR_BIT(TRISD, Pin); break;
            case GPIO_PORTE: CLR_BIT(TRISE, Pin); break;
        }
    }
    else if (Direction == GPIO_INPUT)
    {
        switch (Port)
        {
            case GPIO_PORTA: SET_BIT(TRISA, Pin); break;
            case GPIO_PORTB: SET_BIT(TRISB, Pin); break;
            case GPIO_PORTC: SET_BIT(TRISC, Pin); break;
            case GPIO_PORTD: SET_BIT(TRISD, Pin); break;
            case GPIO_PORTE: SET_BIT(TRISE, Pin); break;
        }
    }
}

void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value)
{
    if (Value == GPIO_HIGH)
    {
        switch (Port)
        {
            case GPIO_PORTA: SET_BIT(PORTA, Pin); break;
            case GPIO_PORTB: SET_BIT(PORTB, Pin); break;
            case GPIO_PORTC: SET_BIT(PORTC, Pin); break;
            case GPIO_PORTD: SET_BIT(PORTD, Pin); break;
            case GPIO_PORTE: SET_BIT(PORTE, Pin); break;
        }
    }
    else if (Value == GPIO_LOW)
    {
        switch (Port)
        {
            case GPIO_PORTA: CLR_BIT(PORTA, Pin); break;
            case GPIO_PORTB: CLR_BIT(PORTB, Pin); break;
            case GPIO_PORTC: CLR_BIT(PORTC, Pin); break;
            case GPIO_PORTD: CLR_BIT(PORTD, Pin); break;
            case GPIO_PORTE: CLR_BIT(PORTE, Pin); break;
        }
    }
}

void GPIO_TogglePinValue(u8 Port, u8 Pin)
{
    switch (Port)
    {
        case GPIO_PORTA: TOGGLE_BIT(PORTA, Pin); break;
        case GPIO_PORTB: TOGGLE_BIT(PORTB, Pin); break;
        case GPIO_PORTC: TOGGLE_BIT(PORTC, Pin); break;
        case GPIO_PORTD: TOGGLE_BIT(PORTD, Pin); break;
        case GPIO_PORTE: TOGGLE_BIT(PORTE, Pin); break;
    }
}

u8 GPIO_GetPinValue(u8 Port, u8 Pin)
{
    u8 PinValue = 0;
    switch (Port)
    {
        case GPIO_PORTA: PinValue = GET_BIT(PORTA, Pin); break;
        case GPIO_PORTB: PinValue = GET_BIT(PORTB, Pin); break;
        case GPIO_PORTC: PinValue = GET_BIT(PORTC, Pin); break;
        case GPIO_PORTD: PinValue = GET_BIT(PORTD, Pin); break;
        case GPIO_PORTE: PinValue = GET_BIT(PORTE, Pin); break;
    }
    return PinValue;
}