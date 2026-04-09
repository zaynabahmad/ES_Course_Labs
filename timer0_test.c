#include "../SERVICES/types.h"
#include "timer0_test.h"
#include "../MCAL/TIMER0/timer0_interface.h"
#include "../HAL/LED/led_interface.h"
#include "../MCAL/GPIO/gpio_interface.h"

static volatile u16 overflow_count = 0;

static void TimerCallback(void)
{
    overflow_count++;
    if(overflow_count >= 30)
    {
        overflow_count = 0;
        Timer0_LoadCounter(124);
        LED_SwitchState(PORTB_ID, PIN0);
    }
}

void Timer0_Test_Runner(void)
{
    LED_Setup(PORTB_ID, PIN0);
    Timer0_Configure();
    Timer0_LoadCounter(124);
    Timer0_AttachCallback(TimerCallback);
    Timer0_Run();
    while(1);
}