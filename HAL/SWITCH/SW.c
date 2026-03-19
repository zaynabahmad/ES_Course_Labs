#include "SW_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"


void SW_Init(u8 Port, u8 Pin)
{
    GPIO_SetPinDirection(Port, Pin, GPIO_INPUT);
}

u8 SW_GetState(u8 Port, u8 Pin)
{
    u8 value = GPIO_GetPinValue(Port, pin);

    if (value == GPIO_HIGH)
    {
        return SW_PRESSED;
    }
    else
    {
        return SW_RELEASED;
    }
}