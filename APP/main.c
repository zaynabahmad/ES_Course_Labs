/*
* APPLICATION LAYER


*/
#include "C:\Users\engfa\OneDrive\Desktop\Embedded CIE 349\Embedded_Project\HAL\LED_INTERFACE.h"
#include "C:\Users\engfa\OneDrive\Desktop\Embedded CIE 349\Embedded_Project\MCAL\GPIO\GPIO_INTERFACE.h"

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
        delay();
    }
}