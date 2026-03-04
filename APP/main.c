/*
 * APPLICATION LAYER - TASK 1
 * LED Sequences Controlled by Switches

 */

#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

/* Delay functions for different blink speeds */
void delay_short(void)
{
    unsigned int i;
    for(i = 0; i < 20000; i++);
}

void delay_long(void)
{
    unsigned int i;
    for(i = 0; i < 50000; i++);
}

void short_sequence(void)
{

    LED_On(GPIO_PORTB, GPIO_PIN0);
    LED_On(GPIO_PORTB, GPIO_PIN1);
    delay_short();

    LED_Off(GPIO_PORTB, GPIO_PIN0);
    LED_Off(GPIO_PORTB, GPIO_PIN1);
    delay_short();
}

void long_sequence(void)
{

    LED_On(GPIO_PORTB, GPIO_PIN0);
    LED_On(GPIO_PORTB, GPIO_PIN1);
    delay_long();

    LED_Off(GPIO_PORTB, GPIO_PIN0);
    LED_Off(GPIO_PORTB, GPIO_PIN1);
    delay_long();
}

void main(void)
{
    u8 switch1_state, switch2_state;

    /* Initialize LEDs */
    LED_Init(GPIO_PORTB, GPIO_PIN0);
    LED_Init(GPIO_PORTB, GPIO_PIN1);

    /* Initialize Switches */
    SWITCH_Init(GPIO_PORTA, GPIO_PIN0);
    SWITCH_Init(GPIO_PORTA, GPIO_PIN1);

    while(1)
    {
        /* Read switch states */
        switch1_state = SWITCH_GetState(GPIO_PORTA, GPIO_PIN0);
        switch2_state = SWITCH_GetState(GPIO_PORTA, GPIO_PIN1);


        if(switch1_state == SWITCH_PRESSED)
        {
            short_sequence();
        }

        else if(switch2_state == SWITCH_PRESSED)
        {
            long_sequence();
        }

        else
        {
            LED_Off(GPIO_PORTB, GPIO_PIN0);
            LED_Off(GPIO_PORTB, GPIO_PIN1);
        }
    }
}
