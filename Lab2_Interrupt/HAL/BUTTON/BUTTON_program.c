#include "BUTTON_interface.h"
#include "../../MCAL/INTERRUPT/EXT_INT_interface.h"

/* -------------------------------------------------------
 * HAL - Button Driver
 * Wraps the MCAL External Interrupt driver.
 * The application only talks to this HAL layer.
 * ------------------------------------------------------- */

void BUTTON_Init(void)
{
    EXT_INT0_Init();                              /* Configure RB0 as input, clear flag */
    EXT_INT0_SetEdge(EXT_INT_FALLING_EDGE);       /* Trigger on button press (LOW) */
    EXT_INT0_Enable();                            /* Enable INT0 + GIE */
}

void BUTTON_SetCallback(void (*ptr)(void))
{
    EXT_INT0_SetCallback(ptr);                    /* Pass callback down to MCAL */
}
