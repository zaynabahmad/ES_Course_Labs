#include "../USART/USART_Interface.h"
#include "../EXT_INT/EXT_INT_Interface.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/COMPILER_COMPAT.h"

extern void (*EXT_INT_Callback)(void);
extern void (*UART_Callback)(void);

// Use the macro instead of hardcoding 'void interrupt()'
GLOBAL_INTERRUPT()
{
    //UART RX interrupt
    if(GET_BIT(PIR1 , RCIF))
    {
        UART_ISR();
    }

    // external interrupt flag
    if(GET_BIT(INTCON , INTF_BIT))
    {
        EXT_INT_ISR();
    }
}
