/*
 * 
 * LED1 (PORTB, PIN1) toggles every 2 seconds
 * LED2 (PORTB, PIN2) toggles every 1 second
 */

#include "lab3.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"

static volatile u16 led1_counter = 0;
static volatile u16 led2_counter = 0;

void Timer0_Tick(void)
{
    led1_counter++;
    led2_counter++;

    if(led1_counter >= 200)    /* 200 * 10ms = 2 seconds */
    {
        LED_Toggle(GPIO_PORTB, GPIO_PIN1);
        led1_counter = 0;
    }

    if(led2_counter >= 100)     /* 100 * 10ms = 1 second */
    {
        LED_Toggle(GPIO_PORTB, GPIO_PIN2);
        led2_counter = 0;
    }
}

void lab3_init(void)
{
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB, GPIO_PIN2);

    TIMER0_SetCallback(&Timer0_Tick);
    TIMER0_Init();
}
