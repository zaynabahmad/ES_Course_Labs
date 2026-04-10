#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "../../SERVICES/BIT_MATH.h"

/* Global pointer to function to hold the callback address */
static void (*TIMER0_CallbackFunc)(void) = NULL;

void TIMER0_Init(void) 
{
    /* 1. Set Timer/Counter Mode */
    #if TIMER0_MODE == TIMER0_TIMER_MODE
        CLR_BIT(OPTION_REG, T0CS_BIT); /* Internal instruction cycle clock */
    #elif TIMER0_MODE == TIMER0_COUNTER_MODE
        SET_BIT(OPTION_REG, T0CS_BIT); /* Transition on T0CKI pin */
    #endif

    /* 2. Configure Prescaler */
    #if PRESCALER_ASSIGNMENT == PRESCALER_ASSIGNED_TO_TIMER0
        CLR_BIT(OPTION_REG, PSA_BIT); /* Assign prescaler to Timer0 */
        
        /* Apply Prescaler value (Bits 0-2) */
        OPTION_REG &= 0xF8; /* Clear the lower 3 bits (1111 1000) */
        OPTION_REG |= (TIMER0_PRESCALER_VALUE & 0x07); /* Set new value */
    #else
        SET_BIT(OPTION_REG, PSA_BIT); /* Assign prescaler to WDT */
    #endif
}

void TIMER0_SetPreload(uint8 value) 
{
    TMR0 = value;
}

void TIMER0_EnableInterrupt(void) 
{
    SET_BIT(INTCON, TMR0IE_BIT); /* Enable Timer0 Interrupt */
    SET_BIT(INTCON, GIE_BIT);    /* Enable Global Interrupts */
}

void TIMER0_DisableInterrupt(void) 
{
    CLR_BIT(INTCON, TMR0IE_BIT); /* Disable Timer0 Interrupt */
}

void TIMER0_SetCallback(void (*ptr_to_func)(void)) 
{
    if (ptr_to_func != NULL) 
    {
        TIMER0_CallbackFunc = ptr_to_func;
    }
}

/* * MikroC Interrupt Service Routine (ISR)
 * All interrupts jump here, so we must check which flag caused it.
 */
/* * MikroC Interrupt Service Routine (ISR)
 * All interrupts jump here, so we must check which flag caused it.
 */
void interrupt() 
{
    /* Check if Timer0 Interrupt Flag is set */
    if (GET_BIT(INTCON, TMR0IF_BIT) == 1) 
    {
        /* Clear the flag so it doesn't trigger again immediately */
        CLR_BIT(INTCON, TMR0IF_BIT);
        
        /* Execute the Application layer callback function */
        if (TIMER0_CallbackFunc != NULL) 
        {
            TIMER0_CallbackFunc();
        }
    }
}