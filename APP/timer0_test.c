#include "../SERVICES/STD_TYPES.h"
#include "timer0_test.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

static u16 overflow_counter = 0;

static void Timer0_Callback(void)
{
    overflow_counter++;
    if (overflow_counter >= 59)
    {
        overflow_counter = 0;
        TIMER0_SetPreload(124);
        LED_Toggle(GPIO_PORTB, GPIO_PIN0);
    }
}

void TIMER0_TEST_Run(void)
{
    LED_Init(GPIO_PORTB, GPIO_PIN0);
    TIMER0_Init();
    TIMER0_SetPreload(124);
    TIMER0_SetCallback(Timer0_Callback);
    TIMER0_Start();
    while (1);
}