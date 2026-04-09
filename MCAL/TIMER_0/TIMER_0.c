#include "TIMER_0_Interface.h"
#include "TIMER_0_Private.h"
#include "TIMER_0_Config.h"

#include "../../SERVICES/BIT_MATH.h"

/* Callback pointer */
static void (*TIMER0_Callback)(void) = 0;

void TIMER0_Init(void)
{
    /* Select Timer mode */
#if TIMER0_MODE == TIMER0_MODE_TIMER
    CLR_BIT(OPTION_REG, T0CS_BIT);   // Internal clock
#else
    SET_BIT(OPTION_REG, T0CS_BIT);   // External clock
#endif

    /* Assign prescaler to Timer0 */
#if TIMER0_PRESCALER == 0
    CLR_BIT(OPTION_REG, PSA_BIT);
#else
    SET_BIT(OPTION_REG, PSA_BIT);
#endif

    /* Set prescaler value */
    OPTION_REG &= 0b11111000;
    OPTION_REG |= TIMER0_PRESCALER_VALUE;

    /* Load initial value */
    TMR0 = TIMER0_PRELOAD_VALUE;

    /* Clear flag */
    CLR_BIT(INTCON, T0IF_BIT);

    /* Enable interrupt */
    SET_BIT(INTCON, T0IE_BIT);

    /* Enable global interrupt */
    SET_BIT(INTCON, GIE_BIT);
}

void TIMER0_Start(void)
{
    /* Timer starts automatically after init */
}

void TIMER0_Stop(void)
{
    CLR_BIT(INTCON, T0IE_BIT);
}

void TIMER0_SetPreload(u8 value)
{
    TMR0 = value;
}

void TIMER0_SetCallback(void (*ptr)(void))
{
    if(ptr != 0)
    {
        TIMER0_Callback = ptr;
    }
}

/* ISR Handler */
void TIMER0_ISR(void)
{
    CLR_BIT(INTCON, T0IF_BIT);

    /* Reload (for periodic interrupt) */
    TMR0 = TIMER0_PRELOAD_VALUE;

    if(TIMER0_Callback != 0)
    {
        TIMER0_Callback();
    }
}

/* 🔥 REAL ISR */
/*void __interrupt() ISR(void)
{
    if(GET_BIT(INTCON, T0IF_BIT))
    {
        TIMER0_ISR();
    }
}*/