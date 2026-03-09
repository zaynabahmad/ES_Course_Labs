#include "SWITCH_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void SWITCH_Init(u8 port, u8 pin)
{
    GPIO_SetPinDirection(port, pin, GPIO_INPUT);
}