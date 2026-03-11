#include "EXT_INT_interface.h"
#include "EXT_INT_private.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"



void EXT_INT0_Init(void)
{
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
}

void EXT_INT0_Enable(void)
{
    SET_BIT(INTCON, INTE);
    SET_BIT(INTCON, GIE);
}

void EXT_INT0_Disable(void)
{
    CLR_BIT(INTCON, INTE);
}

void EXT_INT0_SetEdge(u8 edge)
{
    if (edge == RISING_EDGE)
        SET_BIT(OPTION_REG, INTEDG);
    else
        CLR_BIT(OPTION_REG, INTEDG);
}

void EXT_INT0_SetCallback(void (*ptr)(void))
{
    EXT_INT0_Callback = ptr;
}

void EXT_INT0_ISR(void)
{
    if(EXT_INT0_Callback != 0)
    {
        EXT_INT0_Callback();
    }

    CLR_BIT(INTCON, INTF);
}

void EXT_INT0_ClearFlag(void)
{
    CLR_BIT(INTCON, INTF);
}