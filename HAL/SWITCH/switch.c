#include "switch.h"
#include "GPIO_interface.h"

void SWITCH_Init(u8 pin)
{
    GPIO_SetPinDirection(GPIO_PORTB, pin, GPIO_INPUT);
}