/*
 * timer0.c
 * MCAL - Timer0 Driver Implementation for PIC16F877A
 * Fosc = 4MHz assumed -> Tcy = 1us
 */

#include "timer0.h"
#include "timer0_private.h"

/* Preload stored for DelayMs use */
static u8 _preload = 0;

void TIMER0_Init(TIMER0_ClkSrc_t clkSrc, TIMER0_Prescaler_t prescaler)
{
    /* Clear prescaler bits and clock source bits first */
    OPTION_REG &= 0b11000000;  /* Keep upper 2 bits (RBPU, INTEDG), clear rest */

    if(clkSrc == TIMER0_CLK_EXTERNAL)
    {
        OPTION_REG |= (1 << OPTION_T0CS);
    }
    /* else internal: T0CS=0 already cleared */

    if(prescaler == TIMER0_NO_PRESCALER)
    {
        OPTION_REG |= (1 << OPTION_PSA);    /* Prescaler to WDT */
    }
    else
    {
        OPTION_REG &= ~(1 << OPTION_PSA);   /* Prescaler to TMR0 */
        OPTION_REG |= (prescaler & 0x07);
    }

    /* Clear Timer0 flag */
    INTCON_REG &= ~(1 << INTCON_T0IF);
    TMR0_REG = 0;
}

void TIMER0_Start(void)
{
    INTCON_REG &= ~(1 << INTCON_T0IF);
    INTCON_REG |= (1 << INTCON_T0IE);
    INTCON_REG |= (1 << INTCON_GIE);
}

void TIMER0_Stop(void)
{
    INTCON_REG &= ~(1 << INTCON_T0IE);
}

void TIMER0_SetPreload(u8 preload)
{
    _preload = preload;
    TMR0_REG = preload;
}

u8 TIMER0_Read(void)
{
    return TMR0_REG;
}

void TIMER0_ClearFlag(void)
{
    INTCON_REG &= ~(1 << INTCON_T0IF);
}

u8 TIMER0_GetFlag(void)
{
    return (INTCON_REG >> INTCON_T0IF) & 0x01;
}

/* =====================================================
 * Blocking Delay
 * Fosc=4MHz, Tcy=1us, Prescaler=1:256
 * Each tick = 256us
 * For 1ms: need ~3.9 ticks (preload = 256 - 4 = 252)
 * We use: preload = 131 for ~32ms @ 256 prescaler
 * For simpler 1ms: use prescaler=8 -> 2us/tick
 *   256-125=131 -> 125 ticks * 8us = 1000us = 1ms
 * ===================================================== */
void TIMER0_DelayMs(u16 ms)
{
    u16 i;
    /* Reinit with prescaler 1:8 for 1ms resolution at 4MHz */
    TIMER0_Init(TIMER0_CLK_INTERNAL, TIMER0_PRESCALER_8);

    for(i = 0; i < ms; i++)
    {
        /* Preload: 256 - 125 = 131  (125 ticks * 8us = 1ms) */
        TMR0_REG = 131;
        /* Clear overflow flag */
        INTCON_REG &= ~(1 << INTCON_T0IF);
        /* Wait for overflow */
        while(!((INTCON_REG >> INTCON_T0IF) & 0x01));
    }
    INTCON_REG &= ~(1 << INTCON_T0IF);
}
