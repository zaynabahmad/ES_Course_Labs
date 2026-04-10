#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "TIMER_0_interface.h"
#include "TIMER_0_config.h"
#include "TIMER_0_private.h"

static void (*TIMER0_Callback)(void) = 0;

void Timer0_Init(void) 
{
    /* 1. Select Clock Source */
    #if TIMER0_CLK_SOURCE == TIMER0_INTERNAL_CLK
        CLR_BIT(OPTION_REG, T0CS);  
    #else
        SET_BIT(OPTION_REG, T0CS);   
    #endif

    /* 2. Assign Prescaler to Timer0 (Clear PSA bit) */
    CLR_BIT(OPTION_REG, PSA);      

    /* 3. Set Prescaler Value (Clear PS2:PS0 bits, then OR the new value) */
    OPTION_REG &= 0xF8;           
    OPTION_REG |= TIMER0_PRESCALER;

    /* 4. Set Preload Value */
    TMR0 = TIMER0_PRELOAD_VALUE;
}

/* Matches skeleton line 98 */
void Timer0_EnableInterrupt(void) 
{
    SET_BIT(INTCON, TMR0IE);
    SET_BIT(INTCON, GIE);
}

void Timer0_DisableInterrupt(void) 
{
    CLR_BIT(INTCON, TMR0IE);
}

/* Matches skeleton line 106 - Called by SW2 */
void Timer0_Reset(void) 
{
    /* Reset the timer back to the preload value to restart the 50ms count */
    TMR0 = TIMER0_PRELOAD_VALUE; 
}

void Timer0_SetCallback(void (*ptr)(void))
{
    if (ptr != 0)
    {
        TIMER0_Callback = ptr;
    }
}

void TIMER0_ISR(void)
{
    /* 1. Preload Timer (if you are aiming for a specific frequency like 1ms) */
    TMR0 = 6; 

    /* 2. Clear the Flag */
    CLR_BIT(INTCON, TMR0IF);

    /* 3. Execute Callback */
    if (TIMER0_Callback != 0)
    {
        TIMER0_Callback();
    }
}

void Timer0_EnableGlobalInterrupts(void)
{
    SET_BIT(INTCON, GIE);
    SET_BIT(INTCON, PEIE);
}