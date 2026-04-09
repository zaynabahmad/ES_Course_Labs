#include "switch_interface.h"
#include "../../MCAL/GPIO/gpio_interface.h"

void Switch_Setup(u8 port, u8 pin)
{
    GPIO_ConfigPin(port, pin, DIR_IN);
}

u8 Switch_ReadState(u8 port, u8 pin)
{
    return GPIO_ReadPin(port, pin);
}