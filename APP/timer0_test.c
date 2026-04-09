#include "timer0_test.h"
#include "../MCAL/TIMER0/TIMER0.h"
#include "../MCAL/GPIO/GPIO_interface.h"

// 1. Add a volatile flag for the timer
volatile unsigned char timerFiredFlag = 0;
static u8 tmr_led = 0;

void TIMER0_ToggleLED(void)
{
    // 2. STOP! Don't touch the hardware here.
    // Just set the flag and get out of the ISR.
    timerFiredFlag = 1;
}

void APP_TIMER0_Test(void)
{
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);
    TIMER0_SetCallback(TIMER0_ToggleLED);
    TIMER0_Init();
    TIMER0_EnableInterrupt();

    while (1)
    {
        // 3. Handle the flag in the main loop
        if (timerFiredFlag == 1)
        {
            tmr_led ^= 1;
            GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, tmr_led);

            // 4. Reset the flag
            timerFiredFlag = 0;
        }
    }
}