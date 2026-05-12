#include "EXT_INT0_INTERFACE.h"
#include "EXT_INT0_PRIVATE.h"
#include "../SERVICES/BIT_MATH.h"

static void (*EXT_INT0_Callback)(void) = NULL_PTR;

void EXT_INT0_Init(void)
{
    SET_BIT(TRISB, 0);    /* RB0 as input */
    CLR_BIT(INTCON, INTF); /* Clear interrupt flag */
}

void EXT_INT0_Enable(void)
{
    SET_BIT(INTCON, INTE); /* Enable INT interrupt */
    SET_BIT(INTCON, GIE);  /* Enable global interrupts */
}

void EXT_INT0_Disable(void)
{
    CLR_BIT(INTCON, INTE);
}

void EXT_INT0_SetEdge(u8 edge_type)
{
    if(edge_type == RISING_EDGE)
        SET_BIT(OPTION_REG, INTEDG);
    else
        CLR_BIT(OPTION_REG, INTEDG);
}

void EXT_INT0_SetCallback(void (*ptr)(void))
{
    EXT_INT0_Callback = ptr;
}

void EXT_INT0_HandleISR(void)
{
    if(GET_BIT(INTCON, INTF) == 1)
    {
        if(EXT_INT0_Callback != NULL_PTR)
        {
            EXT_INT0_Callback();
        }
        CLR_BIT(INTCON, INTF);
    }
}
