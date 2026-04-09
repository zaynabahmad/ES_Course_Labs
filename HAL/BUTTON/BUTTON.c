#include "BUTTON_interface.h"
#include "BUTTON_config.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void BUTTON_Init(u8 Port, u8 Pin)
{
    GPIO_SetPinDirection(Port, Pin, GPIO_INPUT);
}

u8 BUTTON_Read(u8 Port, u8 Pin)
{
    u8 pin_val = GPIO_GetPinValue(Port, Pin);

#if BUTTON_LOGIC == BUTTON_ACTIVE_LOW
    return (pin_val == GPIO_LOW) ? BUTTON_PRESSED : BUTTON_RELEASED;
#else
    return (pin_val == GPIO_HIGH) ? BUTTON_PRESSED : BUTTON_RELEASED;
#endif
}
