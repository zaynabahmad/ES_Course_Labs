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

void main(void)
{
    unsigned char port = GPIO_PORTB;
    unsigned char pin  = GPIO_PIN0;

    // Initialize LED
    LED_Init(port, pin);

    while(1)
    {
        // Blink LED
        LED_On(port, pin);
        delay();
        LED_Off(port, pin);
        delay();
    }
}