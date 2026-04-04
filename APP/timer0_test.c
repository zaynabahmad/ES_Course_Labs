/*
 * timer0_test.c
 * Tests the Timer0 MCAL driver: init, callback registration, enable, and
 * periodic LED toggling via the Timer0 overflow interrupt.
 * No direct register access — uses only TIMER_0_Interface.h API.
 */

#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "timer0_test.h"

/* LED that toggles every Timer0 overflow (~10 ms period) */
#define TIMER_LED_PORT  GPIO_PORTD
#define TIMER_LED_PIN   GPIO_PIN3

static u8 timer_led_state = GPIO_LOW;

/* Timer0 overflow callback — called from TIMER0_ISR() */
static void Timer0_Overflow_Callback(void)
{
    if(timer_led_state == GPIO_LOW)
    {
        timer_led_state = GPIO_HIGH;
    }
    else
    {
        timer_led_state = GPIO_LOW;
    }

    GPIO_SetPinValue(TIMER_LED_PORT, TIMER_LED_PIN, timer_led_state);
}

void TIMER0_Test(void)
{
    /* Configure indicator LED */
    GPIO_SetPinDirection(TIMER_LED_PORT, TIMER_LED_PIN, GPIO_OUTPUT);
    GPIO_SetPinValue(TIMER_LED_PORT, TIMER_LED_PIN, GPIO_LOW);

    /* Initialise Timer0 with prescaler and preload from config */
    TIMER0_Init();

    /* Register the overflow callback */
    TIMER0_SetCallback(Timer0_Overflow_Callback);

    /* Start Timer0 — LED will now toggle on each overflow */
    TIMER0_Enable();

    /*
     * The test function returns; the interrupt fires periodically.
     * main() keeps the MCU alive in a while(1) loop.
     */
}