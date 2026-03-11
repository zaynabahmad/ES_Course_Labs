#include "../SERVICES/std_types.h"
#include "../MCAL/TIMER/timer_interface.h"
#include "../HAL/LED/LED_interface.h"

static u16 counter_led1 = 0;
static u16 counter_led2 = 0;

/* Timer interrupt callback */
void Timer_Task(void)
{
    counter_led1++;
    counter_led2++;

    /* LED2 toggles every 1 second */
    if(counter_led2 >= 10)
    {
        LED_Toggle(_PORTC,0);
        counter_led2 = 0;
    }

    /* LED1 toggles every 2 seconds */
    if(counter_led1 >= 20)
    {
        LED_Toggle(_PORTC,1);
        counter_led1 = 0;
    }
}

void main()
{
    /* Initialize LEDs */
    LED_Init(_PORTC,0);
    LED_Init(_PORTC,1);

    /* Timer setup */
    TIMER0_SetCallback(Timer_Task);
    TIMER0_Init();

    while(1)
    {
        /* Main loop does nothing */
    }
}