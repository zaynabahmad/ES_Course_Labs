#include "APP_Tests.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/TIMER_0/TIMER_0_Interface.h"

#define TIMER_LED_PORT GPIO_PORTD
#define TIMER_LED_PIN  GPIO_PIN0

static u16 overflow_count = 0;

/* This function runs automatically every time Timer0 overflows */
static void Timer0_Callback_Test(void)
{
    overflow_count++;
    if(overflow_count >= 15) // Approx delay for visibility at 4MHz
    {
        LED_Toggle(TIMER_LED_PORT, TIMER_LED_PIN);
        overflow_count = 0;
    }
}

void APP_Test_TIMER0(void)
{
    // 1. Initialize the LED
    LED_Init(TIMER_LED_PORT, TIMER_LED_PIN);

    // 2. Initialize Timer0
    TIMER0_Init();

    // 3. Set what happens when it overflows
    TIMER0_SetCallback(Timer0_Callback_Test);

    // 4. Turn on the interrupts
    TIMER0_EnableInterrupt();
}
