#include "switch_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"

void SWITCH_voidInit(u8 Port, u8 Pin)
{
    // Implementation for initializing the switch
    GPIO_SetPinDirection(Port, Pin, GPIO_INPUT);
}

u8 SWITCH_u8GetState(u8 Port, u8 Pin)
{
    // Implementation for getting switch state
    return GPIO_GetPinValue(Port, Pin);
}