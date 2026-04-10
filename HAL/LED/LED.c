#include "LED_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void LED_Init(uint8 Port, uint8 Pin)
{
    GPIO_SetPinDirection(Port, Pin, GPIO_OUTPUT);
}

void LED_On(uint8 Port, uint8 Pin)
{
    GPIO_SetPinValue(Port, Pin, GPIO_HIGH);
}

void LED_Off(uint8 Port, uint8 Pin)
{
    GPIO_SetPinValue(Port, Pin, GPIO_LOW);
}

void LED_Toggle(uint8 Port, uint8 Pin)
{
    uint8 current = GPIO_GetPinValue(Port, Pin);

    if(current == GPIO_HIGH)
        GPIO_SetPinValue(Port, Pin, GPIO_LOW);
    else
        GPIO_SetPinValue(Port, Pin, GPIO_HIGH);
}