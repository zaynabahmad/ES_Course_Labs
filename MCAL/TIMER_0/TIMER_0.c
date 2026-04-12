#include "TIMER_0_Interface.h"

/* ================= Global Callback Pointer ================= */

void (*TIMER0_Callback)(void) = 0;

/* ================= Initialization ================= */

void TIMER0_Init(void)
{
    /* Set internal clock source */
    CLR_BIT(OPTION_REG, T0CS);

    /* Assign prescaler to Timer0 */
    CLR_BIT(OPTION_REG, PSA);

    /* Set prescaler value */
    OPTION_REG &= 0xF8;                          /* Clear PS2:PS0 */
    OPTION_REG |= (TIMER0_PRESCALER_VALUE & 0x07);

    /* Clear Timer0 register */
    TMR0 = 0;

    /* Clear overflow flag */
    CLR_BIT(INTCON, T0IF);
}

/* ================= Set Preload Value ================= */

void TIMER0_SetPreload(u8 Preload)
{
    TMR0 = Preload;
}

/* ================= Start Timer ================= */

void TIMER0_Start(void)
{
    CLR_BIT(INTCON, T0IF);
    CLR_BIT(OPTION_REG, T0CS);      /* Internal clock = run */
}

/* ================= Stop Timer ================= */

void TIMER0_Stop(void)
{
    SET_BIT(OPTION_REG, T0CS);      /* External clock source = effectively stops counting */
}

/* ================= Blocking Delay in Milliseconds ================= */

void TIMER0_DelayMs(u16 Ms)
{
    u16 i;
    for(i = 0; i < Ms; i++)
    {
        /* Preload for 1ms at 4MHz, prescaler 1:1 (no prescaler trick) */
        TMR0 = 6;
        CLR_BIT(INTCON, T0IF);
        while(!GET_BIT(INTCON, T0IF));
    }
}

/* ================= Enable Interrupt ================= */

void TIMER0_EnableInterrupt(void)
{
    CLR_BIT(INTCON, T0IF);
    SET_BIT(INTCON, T0IE);
    SET_BIT(INTCON, GIE_BIT);
}

/* ================= Disable Interrupt ================= */

void TIMER0_DisableInterrupt(void)
{
    CLR_BIT(INTCON, T0IE);
}

/* ================= Set Callback ================= */

void TIMER0_SetCallback(void (*Callback)(void))
{
    if(Callback != 0)
    {
        TIMER0_Callback = Callback;
    }
}

/* ================= ISR Handler ================= */

void TIMER0_ISR(void)
{
    CLR_BIT(INTCON, T0IF);

    if(TIMER0_Callback != 0)
    {
        TIMER0_Callback();
    }
}
