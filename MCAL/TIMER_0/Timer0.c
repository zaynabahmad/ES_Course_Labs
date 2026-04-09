#include "Timer0_interface.h"
#include "Timer0_private.h"
#include "Timer0_config.h"
#include "../../SERVICES/BIT_MATH.h"

/* Global Pointer to Callback Function */
static void (*TMR0_Callback)(void) = NULL;

void TIMER0_Init(void)
{
    /* Set Initial Value */
    TMR0 = TMR0_INIT_VAL;

    /* Configure Clock Source */
    #if TMR0_CLOCK_SOURCE == INTERNAL
        CLR_BIT(OPTION_REG, T0CS_BIT);
    #else
        SET_BIT(OPTION_REG, T0CS_BIT);
        /* Configure Edge */
        #if TMR0_EXT_EDGE == HIGH2LOW
            SET_BIT(OPTION_REG, T0SE_BIT);
        #else
            CLR_BIT(OPTION_REG, T0SE_BIT);
        #endif
    #endif

    /* Configure Prescaler Assignment and Rate */
    #if TMR0_PRESCALER_ASSIGN == PSA_LOW
        CLR_BIT(OPTION_REG, PSA_BIT);
        /* Clear the lower 3 bits, then apply the chosen rate */
        OPTION_REG = (OPTION_REG & 0xF8) | TMR0_PRESCALER_RATE;
    #else
        SET_BIT(OPTION_REG, PSA_BIT);
    #endif
}

void TIMER0_EnableInterrupt(void)
{
    SET_BIT(INTCON, T0IE_BIT);
    SET_BIT(INTCON, GIE_BIT);
}

void TIMER0_DisableInterrupt(void)
{
    CLR_BIT(INTCON, T0IE_BIT);
}

void TIMER0_SetRegister(u8 val)
{
    TMR0 = val;
}

u8 TIMER0_GetRegister(void)
{
    return TMR0;
}

void TIMER0_SetCallback(void (*ptr)(void))
{
    if (ptr != NULL) 
    {
        TMR0_Callback = ptr;
    }
}

void TMR0_ISR_Handler(void)
{
    /* Reload the timer initial value */
    TMR0 = TMR0_INIT_VAL;
    
    CLR_BIT(INTCON, T0IF_BIT); 
    /* Use direct mikroC register access to clear the flag (to make sure) */
    T0IF_bit = 0;
    /* Execute the callback if it is set */
    if (TMR0_Callback != NULL)
    {
        TMR0_Callback();
    }
}