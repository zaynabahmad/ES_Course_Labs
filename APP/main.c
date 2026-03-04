/*
* APPLICATION LAYER


*/
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void delay(void)
{
    unsigned int i;
    for(i = 0; i < 50000; i++);
}

void main()
{
    LED_Init(GPIO_PORTB, GPIO_PIN0);

    while(1)
    {
        LED_On(GPIO_PORTB, GPIO_PIN0);
        delay();

        LED_Off(GPIO_PORTB, GPIO_PIN0);
        delay(30);
    }
}