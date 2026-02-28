#include "LED_interface.h"
#include "C:\Users\engfa\OneDrive\Desktop\Embedded CIE 349\Embedded_Project\MCAL\GPIO\GPIO_INTERFACE.h"

void LED_Init(unsigned char Port, unsigned char Pin)
{
    GPIO_SetPinDirection(Port, Pin, GPIO_OUTPUT);
}

void LED_On(unsigned char Port, unsigned char Pin)
{
    GPIO_SetPinValue(Port, Pin, GPIO_HIGH);
}

void LED_Off(unsigned char Port, unsigned char Pin)
{
    GPIO_SetPinValue(Port, Pin, GPIO_LOW);
}

void LED_Toggle(unsigned char Port, unsigned char Pin)
{
    unsigned char current = GPIO_GetPinValue(Port, Pin);

    if(current == GPIO_HIGH)
        GPIO_SetPinValue(Port, Pin, GPIO_LOW);
    else
        GPIO_SetPinValue(Port, Pin, GPIO_HIGH);
}