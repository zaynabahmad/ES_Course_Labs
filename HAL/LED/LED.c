#include "LED_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void LED_Init(char Port, char Pin)
{
    GPIO_SetPinDirection(Port, Pin, OUTPUT);
}

void LED_On(char Port, char Pin)
{
    GPIO_WritePin(Port, Pin, HIGH);
}

void LED_Off(char Port, char Pin)
{
    GPIO_WritePin(Port, Pin, LOW);
}

void LED_Toggle(char Port, char Pin)
{
    char current = GPIO_ReadPin(Port, Pin);

    if (current == HIGH)
        GPIO_WritePin(Port, Pin, LOW);
    else
        GPIO_WritePin(Port, Pin, HIGH);
}