#include "Interrupt_Manager.h"
#include "../EXT_INT/EXT_INT_Private.h"
#include "../TIMER_0/TIMER_0_Private.h"
#include "../UART/UART_Private.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../EXT_INT/EXT_INT_Interface.h"
#include "../TIMER_0/TIMER_0_Interface.h"
#include "../UART/UART_Interface.h"

void interrupt(void)
{
    if ((GET_BIT(PIR1_U, RCIF_BIT) != 0) && (GET_BIT(PIE1_U, RCIE_BIT) != 0))
    {
        UART_ISR();
    }

    if ((GET_BIT(INTCON, INTF_BIT) != 0) && (GET_BIT(INTCON, INTE_BIT) != 0))
    {
        EXT_INT_ISR();
    }

    if ((GET_BIT(INTCON_T0, TMR0IF_BIT) != 0) && (GET_BIT(INTCON_T0, TMR0IE_BIT) != 0))
    {
        TIMER0_ISR();
    }
}
