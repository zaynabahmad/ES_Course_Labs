#include "MCAL\TIMER_0\TIMER_0_Interface.h"
#include "MCAL\TIMER_0\TIMER_0_Private.h"
#include "MCAL\TIMER_0\TIMER_0_Config.h"
#include "SERVICES\BIT_MATH.h"

/* ── Private callback pointer ── */
static void (*TIMER0_Callback)(void) = 0;

/* ────────────────────────────────
   TIMER0_Init
   Internal clock, prescaler assigned to Timer0
───────────────────────────────── */
void TIMER0_Init(u8 prescaler)
{
    CLR_BIT(OPTION_REG, T0CS);   /* Internal instruction clock          */
    CLR_BIT(OPTION_REG, T0SE);   /* Rising edge (irrelevant for internal)*/
    CLR_BIT(OPTION_REG, PSA);    /* Assign prescaler to Timer0           */

    /* Write PS2:PS0 */
    if (prescaler & (1 << 2)) SET_BIT(OPTION_REG, PS2); else CLR_BIT(OPTION_REG, PS2);
    if (prescaler & (1 << 1)) SET_BIT(OPTION_REG, PS1); else CLR_BIT(OPTION_REG, PS1);
    if (prescaler & (1 << 0)) SET_BIT(OPTION_REG, PS0); else CLR_BIT(OPTION_REG, PS0);

    TMR0 = 0;
    CLR_BIT(INTCON, T0IF);
}

/* ────────────────────────────────
   TIMER0_SetPreload
───────────────────────────────── */
void TIMER0_SetPreload(u8 preload)
{
    TMR0 = preload;
}

/* ────────────────────────────────
   TIMER0_DelayMs  (polling, Fosc=4MHz, prescaler=256)
   Each overflow = 256 * 256 * (4/Fosc) = 65.536 ms @ 4MHz/256
   → 1 ms ≈ 1 overflow with preload = 256 - (Fosc/(4*prescaler*1000))
───────────────────────────────── */
void TIMER0_DelayMs(u16 ms)
{
    u16 i;
    /*
     * With Fosc=4MHz, prescaler=256:
     *   tick period = 256 * (1/Fosc) * 4 = 256 us
     *   counts for 1 ms = 1000/256 ≈ 4 → preload = 256 - 4 = 252
     */
    for (i = 0; i < ms; i++)
    {
        TMR0 = 252;
        CLR_BIT(INTCON, T0IF);
        while (!GET_BIT(INTCON, T0IF));  /* Wait for overflow */
    }
}

/* ────────────────────────────────
   Interrupt-driven interface
───────────────────────────────── */
void TIMER0_EnableOverflowInterrupt(void)
{
    CLR_BIT(INTCON, T0IF);
    SET_BIT(INTCON, T0IE);
    SET_BIT(INTCON, GIE);
}

void TIMER0_DisableOverflowInterrupt(void)
{
    CLR_BIT(INTCON, T0IE);
    CLR_BIT(INTCON, T0IF);
}

void TIMER0_SetCallback(void (*Callback)(void))
{
    if (Callback != 0)
    {
        TIMER0_Callback = Callback;
    }
}

void TIMER0_ISR(void)
{
    CLR_BIT(INTCON, T0IF);
    if (TIMER0_Callback != 0)
    {
        TIMER0_Callback();
    }
}