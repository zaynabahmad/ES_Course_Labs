#include "Switch_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"


void Switch_Init(u8 Port, u8 Pin)
{
    GPIO_SetPinDirection(Port, Pin, GPIO_INPUT);
}

u8 Switch_GetState(u8 Port, u8 Pin)
{
    u8 Local_PinValue = 0;
    u8 Result = SWITCH_NOT_PRESSED;

    Local_PinValue = GPIO_GetPinValue(Port, Pin);


    if (Local_PinValue == 0)
    {
        Result = SWITCH_PRESSED;
    }
    else
    {
        Result = SWITCH_NOT_PRESSED;
    }

    return Result;
}