#include "SWITCH_INTERFACE.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void SWITCH_Init(u8 Pin)
{
    GPIO_SetPinDirection(PortB, Pin, GPIO_INPUT);
}

u8 SWITCH_STATE(u8 Pin)
{
    u8 state = GPIO_GetPinValue(PortB, Pin);
    return state;
}