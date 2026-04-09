#include "TIMER0_private.h"
#include "TIMER0_interface.h"

// Initialize Timer0 (Normal mode)
void TIMER0_Init()
{
    // Normal mode
    TCCR0 = 0x00;

    // Prescaler = 64
    TCCR0 |= (1 << 0) | (1 << 1);
}

// Simple delay using overflow
void TIMER0_DelayMs(unsigned int time)
{
    unsigned int i;

    for (i = 0; i < time; i++)
    {
        TCNT0 = 0;

        // wait overflow
        while (!(TIFR & (1 << 0)));

        // clear flag
        TIFR |= (1 << 0);
    }
}