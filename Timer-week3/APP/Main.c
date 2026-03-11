#include "D:\Timer-week3/HAL/LED.h"
#include "D:\Timer-week3/MCAL/GPIO/GPIO_interface.h"
#include "D:\Timer-week3/TIMER/TIMER_interface.h"

// Callback for LED2 (Every 1 Second)
void Toggle_LED2_1Sec(void)
{
    LED_Toggle(GPIO_PORTB, GPIO_PIN2);
}

// Callback for LED1 (Every 2 Seconds)
void Toggle_LED1_2Sec(void)
{
    LED_Toggle(GPIO_PORTB, GPIO_PIN1);
}

void main()
{
    // 1. Initialize LEDs as outputs
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB, GPIO_PIN2);

    // 2. Map the Timer Interrupts to our LED functions
    TIMER0_SetCallback_1Sec(Toggle_LED2_1Sec);
    TIMER0_SetCallback_2Sec(Toggle_LED1_2Sec);

    // 3. Start the Timer (Global Interrupts are enabled inside)
    TIMER0_Init();

    // 4. Infinite loop - Free for other non-blocking tasks
    while(1)
    {
        // Everything is handled by the Timer0 ISR in the background!
    }
}