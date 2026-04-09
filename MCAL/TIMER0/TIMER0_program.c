#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"

// Callback pointer
void (*TIMER0_Callback)(void) = 0;

void TIMER0_Init(void)
{
    // Select internal clock (Fosc/4)
    CLR_BIT(OPTION_REG_REG, T0CS_BIT);

    // Assign prescaler to Timer0
    CLR_BIT(OPTION_REG_REG, PSA_BIT);

    // Set prescaler value
    OPTION_REG_REG &= 0xF8; // clear PS2:PS0
    OPTION_REG_REG |= TIMER0_PRESCALER;

    // Clear overflow flag
    CLR_BIT(INTCON_REG, T0IF_BIT);

    // Enable Timer0 interrupt
    SET_BIT(INTCON_REG, T0IE_BIT);

    // Enable global interrupt
    SET_BIT(INTCON_REG, GIE_BIT);
}

void TIMER0_Start(void)
{
    // Timer starts automatically when clock selected
}

void TIMER0_Stop(void)
{
    // Disable interrupt as a way to stop effect
    CLR_BIT(INTCON_REG, T0IE_BIT);
}

void TIMER0_SetPreload(u8 value)
{
    TMR0_REG = value;
}

void TIMER0_SetCallback(void (*ptr)(void))
{
    TIMER0_Callback = ptr;
}


