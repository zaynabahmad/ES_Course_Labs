#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "TIMER_0_Interface.h"
#include "TIMER_0_Private.h"
#include "TIMER_0_Config.h"

/* Callback pointer */
static void (*TIMER0_Callback)(void) = 0;

void TIMER0_Init(void)
{
    /* Assign prescaler to Timer0 */
    CLR_BIT(OPTION_REG, PSA);

    /* Set prescaler */
    OPTION_REG &= 0xF8;
    OPTION_REG |= TIMER0_PRESCALER;

    /* Load preload */
    TMR0 = TIMER0_PRELOAD;
}

void TIMER0_Enable(void)
{
    SET_BIT(INTCON, TMR0IE);
    SET_BIT(INTCON, GIE);
}

void TIMER0_Disable(void)
{
    CLR_BIT(INTCON, TMR0IE);
}

void TIMER0_Reload(void)
{
    TMR0 = TIMER0_PRELOAD;
}

u8 TIMER0_GetValue(void)
{
    return TMR0;
}

void TIMER0_SetCallback(void (*Callback)(void))
{
    if(Callback != 0)
    {
        TIMER0_Callback = Callback;
    }
}

void TIMER0_ISR(void)
{
    if(GET_BIT(INTCON, TMR0IF))
    {
        /* Clear flag */
        CLR_BIT(INTCON, TMR0IF);

        /* Reload timer */
        TIMER0_Reload();

        /* Call user function */
        if(TIMER0_Callback != 0)
        {
            TIMER0_Callback();
        }
    }
}