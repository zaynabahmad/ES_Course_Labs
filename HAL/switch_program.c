#include "D:/ES-Project-Lab/SERVICES/std_types.h"
#include "D:/ES-Project-Lab/MCAL/GPIO/gpio.h"
#include "switch_interface.h"

void SWITCH_Init(u8 port, u8 pin)
{
    GPIO_setPinDirection(port, pin, GPIO_INPUT);
}

u8 SWITCH_GetState(u8 port, u8 pin)
{
    return GPIO_getPinValue(port, pin);
}