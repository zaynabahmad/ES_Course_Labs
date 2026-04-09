#include "LED.h"
#include "D:\Timer-week3/MCAL/GPIO/GPIO_interface.h"

void LED_Init(u8 Port, u8 Pin)
{
    GPIO_SetPinDirection(Port, Pin, GPIO_OUTPUT);
    GPIO_SetPinValue(Port, Pin, GPIO_LOW); // Initialize to OFF
}

void LED_On(u8 Port, u8 Pin)
{
    GPIO_SetPinValue(Port, Pin, GPIO_HIGH);
}

void LED_Off(u8 Port, u8 Pin)
{
    GPIO_SetPinValue(Port, Pin, GPIO_LOW);
}

void LED_Toggle(u8 Port, u8 Pin)
{
    GPIO_TogglePinValue(Port, Pin);
}