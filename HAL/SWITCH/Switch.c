#include "Switch_interface.h"

/* =========================================================
   Switch_Init
========================================================= */

void Switch_Init(u8 port, u8 pin, u8 active)
{
    (void)active;                               /* active polarity is stateless */
    GPIO_SetPinDirection(port, pin, GPIO_INPUT);
}

/* =========================================================
   Switch_GetState
   Returns SWITCH_PRESSED or SWITCH_RELEASED
========================================================= */

u8 Switch_GetState(u8 port, u8 pin, u8 active)
{
    u8 raw = GPIO_GetPinValue(port, pin);

    if(active == SWITCH_ACTIVE_LOW)
    {
        /* Pin low → pressed */
        return (raw == GPIO_LOW) ? SWITCH_PRESSED : SWITCH_RELEASED;
    }
    else
    {
        /* Pin high → pressed */
        return (raw == GPIO_HIGH) ? SWITCH_PRESSED : SWITCH_RELEASED;
    }
}

/* =========================================================
   Switch_IsPressed
========================================================= */

u8 Switch_IsPressed(u8 port, u8 pin, u8 active)
{
    return (Switch_GetState(port, pin, active) == SWITCH_PRESSED) ? 1U : 0U;
}