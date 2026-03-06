#include "SWITCH.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

/* Manual Register Definition for PORTB Direction */

/* Initializes a specific pin on PORTB as an input switch */
void SWITCH_Init(uint8 pin)
{
    /* Set the specific pin as Input (1) */
    GPIO_SetPinDirection(GPIO_PORTB, pin, 1);
}