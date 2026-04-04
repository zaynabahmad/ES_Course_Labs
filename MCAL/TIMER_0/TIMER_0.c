#include "TIMER_0_Interface.h"

/* =========================================================
   Global callback pointer
========================================================= */

static void (*TIMER0_Callback)(void) = 0;

/* =========================================================
   TIMER0_Init
   - Internal clock (Fosc/4)
   - Prescaler from config
   - Preload TMR0
   - Interrupts NOT yet enabled (call TIMER0_Enable() separately)
========================================================= */

void TIMER0_Init(void)
{
    CLR_BIT(OPTION_REG, T0CS_BIT);             /* Internal clock (timer mode) */
    CLR_BIT(OPTION_REG, PSA_BIT);              /* Prescaler assigned to Timer0 */

    /* Set prescaler bits PS2:PS0 without disturbing other OPTION_REG bits */
    OPTION_REG = (OPTION_REG & ~PS_MASK) | (TIMER0_PRESCALER & PS_MASK);

    TMR0 = TIMER0_PRELOAD;

    CLR_BIT(INTCON, T0IF_BIT);                 /* Clear any pending overflow flag */
    CLR_BIT(INTCON, T0IE_BIT);                 /* Disable Timer0 interrupt (use TIMER0_Enable) */
}

/* =========================================================
   TIMER0_Enable
========================================================= */

void TIMER0_Enable(void)
{
    CLR_BIT(INTCON, T0IF_BIT);                 /* Clear flag before enabling */
    SET_BIT(INTCON, T0IE_BIT);                 /* Enable Timer0 overflow interrupt */
    SET_BIT(INTCON, GIE_BIT);                  /* Enable global interrupts */
}

/* =========================================================
   TIMER0_Disable
========================================================= */

void TIMER0_Disable(void)
{
    CLR_BIT(INTCON, T0IE_BIT);                 /* Disable Timer0 overflow interrupt */
    CLR_BIT(INTCON, T0IF_BIT);
}

/* =========================================================
   TIMER0_Reload
========================================================= */

void TIMER0_Reload(void)
{
    TMR0 = TIMER0_PRELOAD;
}

/* =========================================================
   TIMER0_GetValue
========================================================= */

u8 TIMER0_GetValue(void)
{
    return TMR0;
}

/* =========================================================
   TIMER0_SetCallback
========================================================= */

void TIMER0_SetCallback(void (*Callback)(void))
{
    if(Callback != 0)
    {
        TIMER0_Callback = Callback;
    }
}

/* =========================================================
   TIMER0_ISR  — called by Interrupt_Manager when T0IF=1
========================================================= */

void TIMER0_ISR(void)
{
    CLR_BIT(INTCON, T0IF_BIT);                 /* Clear overflow flag */
    TMR0 = TIMER0_PRELOAD;                     /* Reload for next period */

    if(TIMER0_Callback != 0)
    {
        TIMER0_Callback();
    }
}