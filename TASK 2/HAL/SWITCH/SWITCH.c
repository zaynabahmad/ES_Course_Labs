#include "../../MCAL/GPIO/GPIO_interface.h"
#include "SWITCH_interface.h"

void SWITCH_Init(char port, char pin)
{
    GPIO_SetPinDirection(port, pin, INPUT);
}

char SWITCH_Read(char port, char pin)
{
    return GPIO_ReadPin(port, pin);
}