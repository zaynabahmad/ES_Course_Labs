#include "TIMER_0_Interface.h"

static void (*TIMER0_Callback)(void) = 0;

void TIMER0_Init(void)
{
    CLR_BIT(OPTION_REG, T0CS_BIT);
    CLR_BIT(OPTION_REG, PSA_BIT);

    OPTION_REG = (OPTION_REG & ~PS_MASK) | (TIMER0_PRESCALER & PS_MASK);

    TMR0 = TIMER0_PRELOAD;

    CLR_BIT(INTCON, T0IF_BIT);
    CLR_BIT(INTCON, T0IE_BIT);
}

void TIMER0_Enable(void)
{
    CLR_BIT(INTCON, T0IF_BIT);
    SET_BIT(INTCON, T0IE_BIT);
    SET_BIT(INTCON, GIE_BIT);
}

void TIMER0_Disable(void)
{
    CLR_BIT(INTCON, T0IE_BIT);
    CLR_BIT(INTCON, T0IF_BIT);
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
    CLR_BIT(INTCON, T0IF_BIT);
    TMR0 = TIMER0_PRELOAD;

    if(TIMER0_Callback != 0)
    {
        TIMER0_Callback();
    }
}
