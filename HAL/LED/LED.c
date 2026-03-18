#include "LED_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void LED_Init(u8 Port, u8 Pin)
{
    GPIO_SetPinDirection(Port, Pin, GPIO_OUTPUT);
}

void LED_On(u8 Port, u8 Pin)
{
    GPIO_SetPinValue(Port, Pin, GPIO_HIGH);
}

void LED_Off(u8 Port, u8 Pin)
{
    GPIO_SetPinValue(Port, Pin, GPIO_LOW);
}
static u8 LED_State = GPIO_LOW;
void LED_Toggle(u8 Port, u8 Pin)
{
    if(LED_State == GPIO_LOW)
    {
        LED_State = GPIO_HIGH;
    }
    else
    {
        LED_State = GPIO_LOW;
    }
    GPIO_SetPinValue(Port, Pin, LED_State);
}