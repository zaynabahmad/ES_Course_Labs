#include "TIMER_0_interface.h"
#include "TIMER_0_private.h"
#include "TIMER_0_config.h"
#include "../../SERVICES/BIT_MATH.h"

// Callback pointer to store the APP layer function
static void (*TIMER0_Callback)(void) = 0;

void TIMER0_Init(void)
{
    // 1. Select Clock Source  
    #if TIMER0_CLOCK_SOURCE == 0
        CLR_BIT(OPTION_REG, T0CS);
    #else
        SET_BIT(OPTION_REG, T0CS);
    #endif

    // 2. Assign Prescaler 
    #if TIMER0_PRESCALER_ASSIGN == 0
        CLR_BIT(OPTION_REG, PSA);

        // 3. Set Prescaler Rate by clearing the first 3 bits, then applying the config 
        OPTION_REG = (OPTION_REG & 0xF8) | TIMER0_PRESCALER_RATE;
    #else
        SET_BIT(OPTION_REG, PSA);
    #endif

    // Clear the Timer Register 
    TMR0 = 0;

    // Clear Interrupt Flag 
    CLR_BIT(INTCON, T0IF);
}

void TIMER0_SetPreload(u8 Preload)
{
    TMR0 = Preload;
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
    if(Callback != 0)
    {
        TIMER0_Callback = Callback;
    }
}

void TIMER0_ISR(void)
{
    // Clear the interrupt flag 
    CLR_BIT(INTCON, T0IF);

    // Execute the callback
    if(TIMER0_Callback != 0)
    {
        TIMER0_Callback();
    }
}