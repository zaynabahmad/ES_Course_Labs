#include "SWITCH_interface.h"
#include "SWITCH_private.h"
#include "SWITCH_config.h"

void SWITCH_Init(u8 Port, u8 Pin)
{
    GPIO_SetPinDirection(Port, Pin, GPIO_INPUT);
}

u8 SWITCH_GetState(u8 Port, u8 Pin, u8 PullType)
{
    u8 Local_State = GPIO_GetPinValue(Port, Pin);
    u8 Result = SWITCH_RELEASED;
    
    if (PullType == SWITCH_PULL_UP)
    {
        if (Local_State == 0)
        {
            Result = SWITCH_PRESSED;
        }
    }
    else if (PullType == SWITCH_PULL_DOWN)
    {
        if (Local_State == 1)
        {
            Result = SWITCH_PRESSED;
        }
    }
    
    return Result;
}
