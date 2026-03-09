#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../SERVICES/STD_TYPES.h"

volatile u16 led1_counter_ms = 0;
volatile u16 led2_counter_ms = 0;

void APP_Timer0Callback(void)
{
    led1_counter_ms++;
    led2_counter_ms++;

    if (led2_counter_ms >= 1000)
    {
        LED_Toggle(GPIO_PORTB, GPIO_PIN2);   /* LED2 every 1 second */
        led2_counter_ms = 0;
    }

    if (led1_counter_ms >= 2000)
    {
        LED_Toggle(GPIO_PORTB, GPIO_PIN1);  
        led1_counter_ms = 0;
    }
}

void main(void)
{
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB, GPIO_PIN2);

    LED_Off(GPIO_PORTB, GPIO_PIN1);
    LED_Off(GPIO_PORTB, GPIO_PIN2);

    TIMER0_Init();
    TIMER0_SetPreload(6);           
    TIMER0_SetCallback(APP_Timer0Callback);
    TIMER0_EnableInterrupt();

    while(1)
    {
    }
}