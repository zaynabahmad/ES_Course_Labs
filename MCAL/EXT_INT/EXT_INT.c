#include "EXT_INT_Interface.h"

/* Callback pointer */
void (*EXT_INT_Callback)(void) = 0;

void EXT_INT_Init(void)
{
    /* Configure RB0/INT pin as input */
    GPIO_SetPinDirection(EXT_INT_PORT, EXT_INT_PIN, GPIO_INPUT);

    /* Default: falling edge trigger */
    EXT_INT_SetEdge(FALLING_EDGE);

    /* Clear flag, disable INT initially */
    CLR_BIT(INTCON, INTF_BIT);
    CLR_BIT(INTCON, INTE_BIT);
}

void EXT_INT_Enable(void)
{
    CLR_BIT(INTCON, INTF_BIT);
    SET_BIT(INTCON, INTE_BIT);
    SET_BIT(INTCON, GIE_BIT);
}

void EXT_INT_Disable(void)
{
    CLR_BIT(INTCON, INTE_BIT);
    CLR_BIT(INTCON, INTF_BIT);
}

void EXT_INT_SetEdge(u8 EdgeType)
{
    /* PIC16F877A datasheet:
       INTEDG = 1 -> Rising edge
       INTEDG = 0 -> Falling edge */
    if(EdgeType == RISING_EDGE)
        SET_BIT(OPTION_REG, INTEDG_BIT);
    else
        CLR_BIT(OPTION_REG, INTEDG_BIT);
}

void EXT_INT_SetCallback(void (*Callback)(void))
{
    if(Callback != 0)
        EXT_INT_Callback = Callback;
}

void EXT_INT_ISR(void)
{
    CLR_BIT(INTCON, INTF_BIT);

    if(EXT_INT_Callback != 0)
        EXT_INT_Callback();
}
