#include "timer_test.h"
#include "../MCAL/TIMER0_INTERFACE.h"
#include "../HAL/LED_INTERFACE.h"
#include "../MCAL/GPIO_INTERFACE.h"

static void Timer0_Callback(void)
{
    /* Reload preload for consistent period, toggle LED */
    TIMER0_SetPreload(6);
    LED_Toggle(GPIO_PORTC, GPIO_PIN2);
}

void TIMER_Test_Init(void)
{
    LED_Init(GPIO_PORTC, GPIO_PIN2);
    TIMER0_Init();
    TIMER0_SetPreload(6);          /* Preload for ~250 ms overflow at Fosc=4MHz, prescale=256 */
    TIMER0_SetCallback(Timer0_Callback);
    TIMER0_EnableInterrupt();
}

void TIMER_Test_Run(void)
{
    /* Interrupt-driven: nothing to poll in the super-loop */
}
