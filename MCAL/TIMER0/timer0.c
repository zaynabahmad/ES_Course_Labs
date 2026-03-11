#include "timer0_interface.h"
#include "timer0_private.h"
#include "../../SERVICES/BIT_MATH.h"

static void (*TIMER0_CallbackFptr)(void) = 0;

void TIMER0_Init(void)
{
    // Configure Timer0 with internal clock and no prescaler
    CLR_BIT(OPTION_REG, T0CS);  // Select internal clock
    CLR_BIT(OPTION_REG, PSA);  // Assign prescaler to Timer0
    // Set PS2, PS1, PS0 = 1,1,1 -> prescaler 1:256
    SET_BIT(OPTION_REG, PS0);
    SET_BIT(OPTION_REG, PS1);
    SET_BIT(OPTION_REG, PS2);
    CLR_BIT(INTCON, T0IF);  // Clear Timer0 interrupt flag
    TMR0 = 0;  // Clear Timer0 register    
}

void TIMER0_Start(u8 initialValue)
{
    TMR0 = initialValue;  // Load initial value into Timer0
}

void TIMER0_Stop(void)
{
    CLR_BIT(INTCON, T0IE);  // Disable Timer0 interrupt
    TMR0 = 0;  // Clear Timer0 register
}

void TIMER0_EnableInterrupt(void)
{
    SET_BIT(INTCON, T0IE);  // Enable Timer0 interrupt
    SET_BIT(INTCON, GIE);   // Enable global interrupts
}

void TIMER0_DisableInterrupt(void)
{
    CLR_BIT(INTCON, T0IE);  // Disable Timer0 interrupt
}

void TIMER0_SetCallback(void (*LocalFptr)(void))
{
    TIMER0_CallbackFptr = LocalFptr; //
}

void interrupt(void)
{
    if(GET_BIT(INTCON, T0IF) == 1)
    {
        CLR_BIT(INTCON, T0IF);
        TMR0 = 0;                    
        if(TIMER0_CallbackFptr != 0)
            TIMER0_CallbackFptr();
    }
}