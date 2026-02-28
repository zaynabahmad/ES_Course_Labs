#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

#include "../../SERVICES/BIT_MATH.h"


void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction)
{
    switch(Port)
    {
        case GPIO_PORTA:
            if(Direction == GPIO_OUTPUT)
                CLR_BIT(TRISA, Pin);
            else
                SET_BIT(TRISA, Pin);
        break;

        case GPIO_PORTB:
            if(Direction == GPIO_OUTPUT)
                CLR_BIT(TRISB, Pin);
            else
                SET_BIT(TRISB, Pin);
        break;

        case GPIO_PORTC:
            if(Direction == GPIO_OUTPUT)
                CLR_BIT(TRISC, Pin);
            else
                SET_BIT(TRISC, Pin);
        break;

        case GPIO_PORTD:
            if(Direction == GPIO_OUTPUT)
                CLR_BIT(TRISD, Pin);
            else
                SET_BIT(TRISD, Pin);
        break;

        case GPIO_PORTE:
            if(Direction == GPIO_OUTPUT)
                CLR_BIT(TRISE, Pin);
            else
                SET_BIT(TRISE, Pin);
        break;

        default:
        break;
    }
}



void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value)
{
    switch(Port)
    {
        case GPIO_PORTA:
            if(Value == GPIO_HIGH)
                SET_BIT(PORTA, Pin);
            else
                CLR_BIT(PORTA, Pin);
        break;

        case GPIO_PORTB:
            if(Value == GPIO_HIGH)
                SET_BIT(PORTB, Pin);
            else
                CLR_BIT(PORTB, Pin);
        break;

        case GPIO_PORTC:
            if(Value == GPIO_HIGH)
                SET_BIT(PORTC, Pin);
            else
                CLR_BIT(PORTC, Pin);
        break;

        case GPIO_PORTD:
            if(Value == GPIO_HIGH)
                SET_BIT(PORTD, Pin);
            else
                CLR_BIT(PORTD, Pin);
        break;

        case GPIO_PORTE:
            if(Value == GPIO_HIGH)
                SET_BIT(PORTE, Pin);
            else
                CLR_BIT(PORTE, Pin);
        break;

        default:
        break;
    }
}


u8 GPIO_GetPinValue(u8 Port, u8 Pin)
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


void EXT_INT0_Init(void)
{
    SET_BIT(TRISB, 0); 
    CLR_BIT(INTCON, 1); // INTF
    CLR_BIT(INTCON, 4); // INTE
    SET_BIT(INTCON, 7); // GIE
    CLR_BIT(OPTION_REG, 6);   // INTEGD -> Falling




}

void EXT_INT0_Enable(void) 
{
    CLR_BIT(INTCON, 1); // INTF 
    SET_BIT(INTCON, 4); // INTE
}

void EXT_INT0_Disable(void) 
{
    CLR_BIT(INTCON, 4);
}

void EXT_INT0_SetEdge(u8 edge_type) 
{
    if(edge_type == RISING_EDGE) {
        SET_BIT(OPTION_REG, 6);   // INTEGD -> Rising
    } else {
        CLR_BIT(OPTION_REG, 6);   // INTEGD -> Falling
    }
}

static void (*EXT_INT0_Callback)(void) = 0;

void EXT_INT0_SetCallback(void (*ptr)(void)) 
{
    EXT_INT0_Callback = ptr;
}


void interrupt()
{
    if(GET_BIT(INTCON, 1)) {
        CLR_BIT(INTCON, 1);
        if(EXT_INT0_Callback) {
            EXT_INT0_Callback();
        }
    }
}