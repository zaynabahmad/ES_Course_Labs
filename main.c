#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"

volatile unsigned int counter1 = 0;
volatile unsigned int counter2 = 0;

void Timer_Task(void)
{

    counter1++;
    counter2++;

    /* LED1 every 2 seconds */

    if(counter1 >= 40)
    {
        LED_Toggle(GPIO_PORTB , GPIO_PIN1);
        counter1 = 0;
    }

    /* LED2 every 1 second */

    if(counter2 >= 20)
    {
        LED_Toggle(GPIO_PORTB , GPIO_PIN2);
        counter2 = 0;
    }

}

void main()
{

    LED_Init(GPIO_PORTB , GPIO_PIN1);
    LED_Init(GPIO_PORTB , GPIO_PIN2);

    TIMER0_Init();

    TIMER0_SetPreload(6);
    TIMER0_SetCallback(Timer_Task);

    while(1)
    {

    }

}