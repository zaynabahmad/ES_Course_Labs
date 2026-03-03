#include "switch.h"
#include "../../SERVICES/BIT_MATH.h"

/* Manual Register Definition for PORTB Direction */
#define TRISB_REG (*((volatile uint8 *)0x86))

/* Initializes a specific pin on PORTB as an input switch */
void SWITCH_Init(uint8 pin)
{
    /* Set the specific pin as Input (1) */
    SET_BIT(TRISB_REG, pin);
}