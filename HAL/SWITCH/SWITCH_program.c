#include "SWITCH_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"


void SWITCH_Init(u8 pin)
{
    GPIO_SetPinDirection(GPIO_PORTB, pin, GPIO_INPUT);
}

u8 SWITCH_GetState(u8 pin)
{
    u8 value = GPIO_GetPinValue(GPIO_PORTB, pin);

    if (value == GPIO_LOW)
    {
        return SWITCH_PRESSED;
    }
    else
    {
        return SWITCH_RELEASED;
    }
}
