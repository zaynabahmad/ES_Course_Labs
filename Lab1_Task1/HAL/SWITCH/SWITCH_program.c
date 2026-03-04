#include "SWITCH_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void SWITCH_Init(uint8 port, uint8 pin)
{
    /* Configure pin as input - internal pull-up used (active LOW switch) */
    GPIO_SetPinDirection(port, pin, GPIO_INPUT);
}

uint8 SWITCH_Read(uint8 port, uint8 pin)
{
    return GPIO_ReadPin(port, pin);
}
