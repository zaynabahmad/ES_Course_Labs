#include "SWITCH_Interface.h"
#include "SWITCH_Config.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void SWITCH_Init(u8 Port, u8 Pin)
{
    GPIO_SetPinDirection(Port, Pin, GPIO_INPUT);
}

u8 SWITCH_Read(u8 Port, u8 Pin)
{
    u8 first_read = GPIO_GetPinValue(Port, Pin);
    Delay_ms(SWITCH_DEBOUNCE_MS); /* MikroC built-in — software debounce */
    u8 second_read = GPIO_GetPinValue(Port, Pin);

    if (first_read == second_read)
        return first_read; /* stable reading */
    else
        return SWITCH_RELEASED; /* still bouncing → treat as released */
}