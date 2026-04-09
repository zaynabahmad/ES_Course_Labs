#include "TIMER0_interface.h"
#include "TIMER0_private.h"

void TIMER0_Init(void)
{
    // Timer mode (internal clock)
    OPTION_REG &= ~(1 << T0CS);

    // Prescaler assigned to Timer0
    OPTION_REG &= ~(1 << PSA);

    // Prescaler = 1:256
    OPTION_REG |= (1 << PS0) | (1 << PS1) | (1 << PS2);

    // Enable interrupt
    INTCON_REG |= (1 << TMR0IE);
    INTCON_REG |= (1 << GIE);
}

void TIMER0_Start(void)
{
    TMR0_REG = 0;
}

void TIMER0_Stop(void)
{
    // ?? ????? stop ???? ???
}