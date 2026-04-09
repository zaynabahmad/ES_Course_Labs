#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

#include "../../SERVICES/BIT_MATH.h"

void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction)
{
    switch (Port)
    {
    case GPIO_PORTA:
        (Direction == GPIO_OUTPUT) ? CLR_BIT(TRISA, Pin) : SET_BIT(TRISA, Pin);
        break;

    case GPIO_PORTB:
        (Direction == GPIO_OUTPUT) ? CLR_BIT(TRISB, Pin) : SET_BIT(TRISB, Pin);
        break;

    case GPIO_PORTC:
        (Direction == GPIO_OUTPUT) ? CLR_BIT(TRISC, Pin) : SET_BIT(TRISC, Pin);
        break;

    case GPIO_PORTD:
        (Direction == GPIO_OUTPUT) ? CLR_BIT(TRISD, Pin) : SET_BIT(TRISD, Pin);
        break;

    case GPIO_PORTE:
        (Direction == GPIO_OUTPUT) ? CLR_BIT(TRISE, Pin) : SET_BIT(TRISE, Pin);
        break;
    }
}

void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value)
{
    switch (Port)
    {
    case GPIO_PORTA:
        (Value == GPIO_HIGH) ? SET_BIT(PORTA, Pin) : CLR_BIT(PORTA, Pin);
        break;

    case GPIO_PORTB:
        (Value == GPIO_HIGH) ? SET_BIT(PORTB, Pin) : CLR_BIT(PORTB, Pin);
        break;

    case GPIO_PORTC:
        (Value == GPIO_HIGH) ? SET_BIT(PORTC, Pin) : CLR_BIT(PORTC, Pin);
        break;

    case GPIO_PORTD:
        (Value == GPIO_HIGH) ? SET_BIT(PORTD, Pin) : CLR_BIT(PORTD, Pin);
        break;

    case GPIO_PORTE:
        (Value == GPIO_HIGH) ? SET_BIT(PORTE, Pin) : CLR_BIT(PORTE, Pin);
        break;
    }
}

u8 GPIO_GetPinValue(u8 Port, u8 Pin)
{
    u8 Local_Value = 0;

    switch (Port)
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
    }

    return Local_Value;
}

void GPIO_Init(void)
{
    /* VERY IMPORTANT for PIC16F877A */
    ADCON1 = 0x06; // Make PORTA & PORTE digital

    TRISA = GPIO_PORTA_DIR;
    TRISB = GPIO_PORTB_DIR;
    TRISC = GPIO_PORTC_DIR;
    TRISD = GPIO_PORTD_DIR;
    TRISE = GPIO_PORTE_DIR;

    PORTA = GPIO_PORTA_INIT_VAL;
    PORTB = GPIO_PORTB_INIT_VAL;
    PORTC = GPIO_PORTC_INIT_VAL;
    PORTD = GPIO_PORTD_INIT_VAL;
    PORTE = GPIO_PORTE_INIT_VAL;
}