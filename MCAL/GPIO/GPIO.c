#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

#include "../../SERVICES/BIT_MATH.h"

void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction)
{
    switch(Port)
    {
        case GPIO_PORTA:
            if(Direction == GPIO_OUTPUT) CLR_BIT(GPIO_TRISA_REG, Pin);
            else SET_BIT(GPIO_TRISA_REG, Pin);
            break;
        case GPIO_PORTB:
            if(Direction == GPIO_OUTPUT) CLR_BIT(GPIO_TRISB_REG, Pin);
            else SET_BIT(GPIO_TRISB_REG, Pin);
            break;
        case GPIO_PORTC:
            if(Direction == GPIO_OUTPUT) CLR_BIT(GPIO_TRISC_REG, Pin);
            else SET_BIT(GPIO_TRISC_REG, Pin);
            break;
        case GPIO_PORTD:
            if(Direction == GPIO_OUTPUT) CLR_BIT(GPIO_TRISD_REG, Pin);
            else SET_BIT(GPIO_TRISD_REG, Pin);
            break;
        case GPIO_PORTE:
            if(Direction == GPIO_OUTPUT) CLR_BIT(GPIO_TRISE_REG, Pin);
            else SET_BIT(GPIO_TRISE_REG, Pin);
            break;
        default: break;
    }
}

void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value)
{
    switch(Port)
    {
        case GPIO_PORTA:
            if(Value == GPIO_HIGH) SET_BIT(GPIO_PORTA_REG, Pin);
            else CLR_BIT(GPIO_PORTA_REG, Pin);
            break;
        case GPIO_PORTB:
            if(Value == GPIO_HIGH) SET_BIT(GPIO_PORTB_REG, Pin);
            else CLR_BIT(GPIO_PORTB_REG, Pin);
            break;
        case GPIO_PORTC:
            if(Value == GPIO_HIGH) SET_BIT(GPIO_PORTC_REG, Pin);
            else CLR_BIT(GPIO_PORTC_REG, Pin);
            break;
        case GPIO_PORTD:
            if(Value == GPIO_HIGH) SET_BIT(GPIO_PORTD_REG, Pin);
            else CLR_BIT(GPIO_PORTD_REG, Pin);
            break;
        case GPIO_PORTE:
            if(Value == GPIO_HIGH) SET_BIT(GPIO_PORTE_REG, Pin);
            else CLR_BIT(GPIO_PORTE_REG, Pin);
            break;
        default: break;
    }
}

u8 GPIO_GetPinValue(u8 Port, u8 Pin)
{
    u8 Local_Value = 0;
    switch(Port)
    {
        case GPIO_PORTA: Local_Value = GET_BIT(GPIO_PORTA_REG, Pin); break;
        case GPIO_PORTB: Local_Value = GET_BIT(GPIO_PORTB_REG, Pin); break;
        case GPIO_PORTC: Local_Value = GET_BIT(GPIO_PORTC_REG, Pin); break;
        case GPIO_PORTD: Local_Value = GET_BIT(GPIO_PORTD_REG, Pin); break;
        case GPIO_PORTE: Local_Value = GET_BIT(GPIO_PORTE_REG, Pin); break;
        default: break;
    }
    return Local_Value;
}

void GPIO_Init(void)
{
    GPIO_TRISA_REG = GPIO_PORTA_DIR;
    GPIO_TRISB_REG = GPIO_PORTB_DIR;
    GPIO_TRISC_REG = GPIO_PORTC_DIR;
    GPIO_TRISD_REG = GPIO_PORTD_DIR;
    GPIO_TRISE_REG = GPIO_PORTE_DIR;

    GPIO_PORTA_REG = GPIO_PORTA_INIT_VAL;
    GPIO_PORTB_REG = GPIO_PORTB_INIT_VAL;
    GPIO_PORTC_REG = GPIO_PORTC_INIT_VAL;
    GPIO_PORTD_REG = GPIO_PORTD_INIT_VAL;
    GPIO_PORTE_REG = GPIO_PORTE_INIT_VAL;
}
