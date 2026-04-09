#include "../MCAL/GPIO/GPIO_interface.h"

void GPIO_Test(void)
{
    unsigned long i;   // ? declare here

    /* Set pin as output */
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);

    while(1)
    {
        /* Turn LED ON */
        GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);

        for(i = 0; i < 50000; i++);   // delay

        /* Turn LED OFF */
        GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);

        for(i = 0; i < 50000; i++);   // delay
    }
}