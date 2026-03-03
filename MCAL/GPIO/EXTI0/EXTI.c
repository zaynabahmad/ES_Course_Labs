#include "EXTI_Interface.h"
#include "EXTI_Config.h"
#include "EXTI_Private.h"

static void (*EXTI_CallBack)(void) = 0;

void EXTI_Init(void)
{
    /* Set RB0 as input */
    TRISB0 = 1;

    /* Set Edge */
    EXTI_SetEdge(EXTI_EDGE);

    /* Clear interrupt flag */
    INTF = 0;
}

void EXTI_SetEdge(u8 Edge)
{
    if (Edge == EXTI_RISING_EDGE)
    {
        INTEDG = 1;
    }
    else if (Edge == EXTI_FALLING_EDGE)
    {
        INTEDG = 0;
    }
}

void EXTI_Enable(void)
{
    INTE = 1;   // Enable INT0
    GIE  = 1;   // Enable Global Interrupt
}

void EXTI_Disable(void)
{
    INTE = 0;
}

void EXTI_SetCallBack(void (*Copy_ptr)(void))
{
    EXTI_CallBack = Copy_ptr;
}

/* ISR */
void __interrupt() ISR(void)
{
    if (INTF == 1)
    {
        if (EXTI_CallBack != 0)
        {
            EXTI_CallBack();
        }

        INTF = 0;  // Clear flag
    }
}
