#include "SWITCH_INTERFACE.h"
#include "../../MCAL/GPIO/GPIO_INTERFACE.h"

void switchInit(u8 port, u8 pin)
{
    GPIO_SetPinDirection(port, pin, GPIO_INPUT);
}

u8 switchGetState(u8 port, u8 pin)
{
    return GPIO_GetPinValue(port, pin);
}