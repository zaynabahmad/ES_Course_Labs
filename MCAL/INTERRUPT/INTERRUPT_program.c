#include "INTERRUPT_private.h"
#include "INTERRUPT_interface.h"

#include "../../SERVICES/BIT_MATH.h"

void interrupt()
{
    /* External Interrupt */

    if (GET_BIT(INTCON, INTF))
    {
        EXT_INT0_ISR();
    }

    /* Timer0 Interrupt */

    if (GET_BIT(INTCON, T0IF))
    {
        TIMER0_ISR();
    }
}