#include "EXTI_private.h"
#include "EXTI_interface.h"

static void (*EXTI_Callback)(void) = 0;

// Initialize interrupt sense
void EXTI_Init(char sense)
{
    // Clear first
    MCUCR &= ~((1 << 0) | (1 << 1));

    if (sense == RISING_EDGE)
    {
        MCUCR |= (1 << 0) | (1 << 1);
    }
    else if (sense == FALLING_EDGE)
    {
        MCUCR |= (1 << 1);
    }
    else if (sense == LOW_LEVEL)
    {
        // already cleared
    }
}

// Enable INT0
void EXTI_Enable()
{
    GICR |= (1 << 6); // INT0 enable
    SREG |= (1 << 7); // Global interrupt enable
}

// Set callback function
void EXTI_SetCallback(void (*ptr)(void))
{
    EXTI_Callback = ptr;
}

// ISR for INT0
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if (EXTI_Callback != 0)
    {
        EXTI_Callback();
    }
}