#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

#include "../USART/USART_Interface.h"
#include "../USART/USART_Private.h"
#include "../EXT_INT/EXT_INT_Interface.h"
#include "../EXT_INT/EXT_INT_Private.h"
#include "../TIMER_0/TIMER_0_Interface.h"
#include "../TIMER_0/TIMER_0_Private.h"

#define RCIF    5

void interrupt()
{
    if(GET_BIT(INTCON, T0IF_BIT))   // Timer0
    {
        TIMER_0_ISR();
    }

    if(GET_BIT(INTCON, INTF_BIT))   // External interrupt RB0
    {
        EXT_INT_ISR();
    }

    if(GET_BIT(PIR1, RCIF))     // UART RX
    {
        UART_ISR();
    }
}