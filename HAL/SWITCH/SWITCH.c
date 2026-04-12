#include "SWITCH_interface.h"
#include "SWITCH_Config.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void SWITCH_Init(u8 Port, u8 Pin)
{
    GPIO_SetPinDirection(Port, Pin, GPIO_INPUT);
}

u8 SWITCH_Read(u8 Port, u8 Pin)
{
    u8 PinLevel;

    PinLevel = GPIO_GetPinValue(Port, Pin);

    if(SWITCH_DEFAULT_ACTIVE_LEVEL == SWITCH_ACTIVE_LOW)
    {
        if(PinLevel == GPIO_LOW)
            return 1;
        else
            return 0;
    }
    else
    {
        if(PinLevel == GPIO_HIGH)
            return 1;
        else
            return 0;
    }
}
