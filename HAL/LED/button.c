
#include "button-interface.h"
#include "../MCAL/GPIO/gpio-interface.h"

/* This implementation assumes ACTIVE-LOW buttons:
   - Pressed  => pin reads 0
   - Released => pin reads 1 (via pull-up)
*/
void BUTTON_Init(u8 Port, u8 Pin)
{
    GPIO_SetPinDirection(Port, Pin, GPIO_INPUT);

    /* If using PORTB, enable internal pull-ups once in system init */
}

u8 BUTTON_IsPressed(u8 Port, u8 Pin)
{
    u8 val = GPIO_GetPinValue(Port, Pin);
    return (val == 0u) ? 1u : 0u;  /* active-low */
}