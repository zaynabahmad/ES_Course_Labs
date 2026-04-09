#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "Timer0_test.h"

// Definitions for PORTC
#define LED1_PORT   GPIO_PORTC
#define LED1_PIN    GPIO_PIN0    // Toggles every 2 seconds
#define LED2_PORT   GPIO_PORTC
#define LED2_PIN    GPIO_PIN1    // Toggles every 1 second

// Global variables to track the interrupts
static u8 overflow_count = 0;
static u8 seconds_count = 0;

/* THE CALLBACK FUNCTION (Application Logic)
 * This runs automatically every time Timer0 hits 255 and overflows.
 */
static void APP_Timer0_Callback(void)
{
    u8 led1_state;
    u8 led2_state;

    // 30 full overflows + 1 partial overflow = 1 second
    if(overflow_count < 30)
    {
        TIMER0_SetPreload(0);
        overflow_count++;
    }
    else
    {
        TIMER0_SetPreload(124);
        overflow_count = 0;

        // --- Exactly 1 Second has passed at this point! ---
        seconds_count++;

        // 1. Toggle LED2 (It must toggle every 1 second)
        led2_state = GPIO_GetPinValue(LED2_PORT, LED2_PIN);
        if(led2_state == GPIO_HIGH) {
            GPIO_SetPinValue(LED2_PORT, LED2_PIN, GPIO_LOW);
        } else {
            GPIO_SetPinValue(LED2_PORT, LED2_PIN, GPIO_HIGH);
        }

        // 2. Toggle LED1 (It must toggle every 2 seconds)
        if(seconds_count % 2 == 0)
        {
            led1_state = GPIO_GetPinValue(LED1_PORT, LED1_PIN);
            if(led1_state == GPIO_HIGH) {
                GPIO_SetPinValue(LED1_PORT, LED1_PIN, GPIO_LOW);
            } else {
                GPIO_SetPinValue(LED1_PORT, LED1_PIN, GPIO_HIGH);
            }
        }

        // Reset seconds_count so it doesn't eventually overflow an 8-bit integer
        if(seconds_count >= 2)
        {
            seconds_count = 0;
        }
    }
}

void APP_TestTimer0(void)
{
    // Initialize GPIO with PORTC pins
    GPIO_Init();
    GPIO_SetPinDirection(LED1_PORT, LED1_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(LED2_PORT, LED2_PIN, GPIO_OUTPUT);

    // Initialize the Timer0 driver (This automatically sets TMR0 to 0!)
    TIMER0_Init();

    // Pass our application logic into the MCAL layer
    TIMER0_SetCallback(APP_Timer0_Callback);

    // Enable the Timer0 interrupt
    TIMER0_EnableInterrupt();

    // The infinite loop
    while(1)
    {
        // CPU is completely free! The LEDs toggle in the background.
    }
}