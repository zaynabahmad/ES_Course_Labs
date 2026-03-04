#include "GPIO_interface.h"
#include "../MCU_Registers.h"
#include "GPIO_config.h"

#include "../../SERVICES/BIT_MATH.h"


void SetPinDirection(u8 Port, u8 Pin, u8 Direction)
{
    switch(Port)
    {
        case GPIO_PORTA:
            if(Direction == OUTPUT)
                CLR_BIT(TRISA, Pin);
            else
                SET_BIT(TRISA, Pin);
        break;

        case GPIO_PORTB:
            if(Direction == OUTPUT)
                CLR_BIT(TRISB, Pin);
            else
                SET_BIT(TRISB, Pin);
        break;

        case GPIO_PORTC:
            if(Direction == OUTPUT)
                CLR_BIT(TRISC, Pin);
            else
                SET_BIT(TRISC, Pin);
        break;

        case GPIO_PORTD:
            if(Direction == OUTPUT)
                CLR_BIT(TRISD, Pin);
            else
                SET_BIT(TRISD, Pin);
        break;

        case GPIO_PORTE:
            if(Direction == OUTPUT)
                CLR_BIT(TRISE, Pin);
            else
                SET_BIT(TRISE, Pin);
        break;

        default:
        break;
    }
}


void SetPinValue(u8 Port, u8 Pin, u8 Value)
{
    switch(Port)
    {
        case GPIO_PORTA:
            if(Value == HIGH)
                SET_BIT(PORTA, Pin);
            else
                CLR_BIT(PORTA, Pin);
        break;

        case GPIO_PORTB:
            if(Value == HIGH)
                SET_BIT(PORTB, Pin);
            else
                CLR_BIT(PORTB, Pin);
        break;

        case GPIO_PORTC:
            if(Value == HIGH)
                SET_BIT(PORTC, Pin);
            else
                CLR_BIT(PORTC, Pin);
        break;

        case GPIO_PORTD:
            if(Value == HIGH)
                SET_BIT(PORTD, Pin);
            else
                CLR_BIT(PORTD, Pin);
        break;

        case GPIO_PORTE:
            if(Value == HIGH)
                SET_BIT(PORTE, Pin);
            else
                CLR_BIT(PORTE, Pin);
        break;

        default:
        break;
    }
}


u8 GetPinValue(u8 Port, u8 Pin)
{
    u8 Local_Value = 0;

    switch(Port)
    {
        case GPIO_PORTA:
            Local_Value = GET_BIT(PORTA, Pin);
        break;

        case GPIO_PORTB:
            Local_Value = GET_BIT(PORTB, Pin);
        break;

        case GPIO_PORTC:
            Local_Value = GET_BIT(PORTC, Pin);
        break;

        case GPIO_PORTD:
            Local_Value = GET_BIT(PORTD, Pin);
        break;

        case GPIO_PORTE:
            Local_Value = GET_BIT(PORTE, Pin);
        break;

        default:
        break;
    }

    return Local_Value;
}

void GPIO_Init(void)
{
    TRISA = GPIO_PORTA_DIR;
    TRISB = GPIO_PORTB_DIR;

    PORTA = GPIO_PORTA_INIT_VAL;
    PORTB = GPIO_PORTB_INIT_VAL;
}