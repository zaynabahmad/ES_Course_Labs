#include "LED_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void LED_Init(u8 Port, u8 Pin)
{
    GPIO_SetPinDirection(Port, Pin, OUTPUT);
}

void LED_On(u8 Port, u8 Pin)
{
    GPIO_WritePin(Port, Pin, HIGH);
}

void LED_Off(u8 Port, u8 Pin)
{
    GPIO_WritePin(Port, Pin, LOW);
}

void LED_Toggle(u8 Port, u8 Pin)
{
    u8 current = GPIO_ReadPin(Port, Pin);

    if (current == HIGH)
        GPIO_WritePin(Port, Pin, LOW);
    else
        GPIO_WritePin(Port, Pin, HIGH);
}