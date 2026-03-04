
/*
* LAB 1 - LED Sequences
*/

#include "lab1.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void delay_short(void)
{
    unsigned int i;
    for(i = 0; i < 50000; i++);
}

void delay_long(void)
{
    unsigned int i;
    for(i = 0; i < 125000; i++);
}

void short_sequence(void)
{
    unsigned int i;
    for(i = 0; i < 5; i++)
    {
        LED_On(GPIO_PORTB, GPIO_PIN0);
        LED_On(GPIO_PORTB, GPIO_PIN1);
        delay_short();

        LED_Off(GPIO_PORTB, GPIO_PIN0);
        LED_Off(GPIO_PORTB, GPIO_PIN1);
        delay_short();
    }
}

void long_sequence(void)
{
    unsigned int i;
    for(i = 0; i < 5; i++)
    {
        LED_On(GPIO_PORTB, GPIO_PIN0);
        LED_On(GPIO_PORTB, GPIO_PIN1);
        delay_long();

        LED_Off(GPIO_PORTB, GPIO_PIN0);
        LED_Off(GPIO_PORTB, GPIO_PIN1);
        delay_long();
    }
}

void lab1_init(void)
{
    LED_Init(GPIO_PORTB, GPIO_PIN0);
    LED_Init(GPIO_PORTB, GPIO_PIN1);
}

void lab1_run(void)
{
    u8 switch1_state, switch2_state;

    switch1_state = GPIO_GetPinValue(GPIO_PORTA, GPIO_PIN0);
    switch2_state = GPIO_GetPinValue(GPIO_PORTA, GPIO_PIN1);

    if(switch1_state == GPIO_HIGH)
    {
        short_sequence();
    }
    else if(switch2_state == GPIO_HIGH)
    {
        long_sequence();
    }
    else
    {
        LED_Off(GPIO_PORTB, GPIO_PIN0);
        LED_Off(GPIO_PORTB, GPIO_PIN1);
    }
}
