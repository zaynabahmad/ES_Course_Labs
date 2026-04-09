#include "TIMER_0_Interface.h"
#include "TIMER_0_Private.h"
#include "TIMER_0_Config.h"

#include "../../SERVICES/BIT_MATH.h"

static void (*TIMER0_Callback)(void) = NULL_PTR;

void TIMER0_Init(void)
{
    /* Set Clock Source */
#if (TIMER0_CLOCK_SOURCE == 0)
    CLR_BIT(OPTION_REG, T0CS);
#else
    SET_BIT(OPTION_REG, T0CS);
#endif

    /* Set Prescaler Assignment */
#if (TIMER0_PSA_ASSINGMENT == 0)
    CLR_BIT(OPTION_REG, PSA);
#else
    SET_BIT(OPTION_REG, PSA);
#endif

    /* Set Prescaler Value */
    OPTION_REG = (OPTION_REG & 0xF8) | (TIMER0_PRESCALER_VAL & 0x07);

    /* Set Initial Value */
    TMR0 = TIMER0_INIT_VAL;
}

void TIMER0_SetPreload(u8 Value)
{
    TMR0 = Value;
}

u8 TIMER0_GetCount(void)
{
    return TMR0;
}

void TIMER0_EnableInterrupt(void)
{
    SET_BIT(INTCON, T0IE);
    SET_BIT(INTCON, GIE);
}

void TIMER0_DisableInterrupt(void)
{
    CLR_BIT(INTCON, T0IE);
}

void TIMER0_SetCallback(void (*Callback)(void))
{
    if(Callback != NULL_PTR)
    {
        TIMER0_Callback = Callback;
    }
}

void TIMER0_ISR(void)
{
    /* Clear Interrupt Flag */
    CLR_BIT(INTCON, T0IF);

    /* Execute Callback */
    if(TIMER0_Callback != NULL_PTR)
    {
        TIMER0_Callback();
    }
}
