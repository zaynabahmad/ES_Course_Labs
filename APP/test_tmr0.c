/**
 * @file    test_tmr0.c
 * @brief   Timer0 exercise -- application layer, no register access.
 *
 * @details The timer overflows faster than a visible blink, so the callback
 *          counts overflows and only toggles the LED once a target number
 *          have elapsed. Doing the counting in the application keeps the MCAL
 *          driver generic -- it knows nothing about "blink rate".
 */
#include "test_tmr0.h"
#include "../MCAL/TMR0_interface.h"
#include "../HAL/LED.h"

/** Overflow interval requested from the timer, in microseconds. */
#define TEST_TMR0_TICK_US       3000u

/** Overflows to accumulate before one LED toggle (sets the visible rate). */
#define TEST_TMR0_TICKS_PER_BLINK   80u

/** Running overflow tally, updated only from interrupt context. */
static word_t u16OverflowCount = 0u;

/**
 * @brief  Overflow handler -- counts ticks and toggles the LED on schedule.
 */
static void vOnOverflow(void)
{
    u16OverflowCount++;

    if (u16OverflowCount >= TEST_TMR0_TICKS_PER_BLINK)
    {
        u16OverflowCount = 0u;
        vLED_Toggle(LED_STATUS);
    }

    /* Reload so the next interval matches the first one. */
    vTMR0_SetPreload(TEST_TMR0_TICK_US);
}

void vTest_Tmr0(void)
{
    vLED_Init(LED_STATUS);

    vTMR0_Init();
    vTMR0_SetPreload(TEST_TMR0_TICK_US);
    vTMR0_SetCallback(&vOnOverflow);
    vTMR0_Start();

    while (1)
    {
        /* Empty -- the blink is produced entirely by the timer interrupt. */
    }
}
