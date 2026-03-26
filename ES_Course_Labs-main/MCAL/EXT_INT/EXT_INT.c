#include "EXT_INT_interface.h"

void EXT_INT_Init(void)
{
    GPIO_SetPinDirection(EXT_INT_PORT, EXT_INT_PIN, GPIO_INPUT);

    /* Default edge */
    EXT_INT_SetEdge(falling_edge);

    CLR_BIT(INTCON, INTF_BIT);
    CLR_BIT(INTCON, INTE_BIT);
}

void EXT_INT_Enable(void)
{
    SET_BIT(INTCON, INTE_BIT); // Enable INT
    SET_BIT(INTCON, GIE_BIT);  // Enable global interrupt
    CLR_BIT(INTCON, INTF_BIT);
}

void EXT_INT_Disable(void)
{
    CLR_BIT(INTCON, INTF_BIT);
    CLR_BIT(INTCON, INTE_BIT);
}

/* ?? CORRECTED FUNCTION */
void EXT_INT_SetEdge(u8 Edgetype)
{
    if (Edgetype == rising_edge)
    {
        SET_BIT(OPTION_REG, INTEDGE_BIT);   // Rising edge
    }
    else if (Edgetype == falling_edge)
    {
        CLR_BIT(OPTION_REG, INTEDGE_BIT);   // Falling edge
    }
}

/* Callback pointer */
void (*EXT_INT_Callback)(void) = 0;

void EXT_INT_SetCallback(void (*ptr)(void))
{
    if (ptr != 0)
    {
        EXT_INT_Callback = ptr;
    }
}

void EXT_INT_ISR(void)
{
    CLR_BIT(INTCON, INTF_BIT);

    if (EXT_INT_Callback != 0)
    {
        EXT_INT_Callback();
    }
}