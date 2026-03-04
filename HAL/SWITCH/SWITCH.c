#include "SWITCH_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void SWITCH_Init(u8 Port, u8 Pin)
{
    /* Configure pin as input (switch with pull-up) */
    GPIO_SetPinDirection(Port, Pin, GPIO_INPUT);
}

u8 SWITCH_GetState(u8 Port, u8 Pin)
{
    /* Read the pin value */
    return GPIO_GetPinValue(Port, Pin);
}
