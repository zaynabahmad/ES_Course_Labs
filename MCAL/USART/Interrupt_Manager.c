#include "../USART/USART_Interface.h"
#include "../EXT_INT/EXT_INT_Interface.h"
#include "../TIMER_0/TIMER_0_Interface.h"
#include "../../SERVICES/BIT_MATH.h"

extern void (*EXT_INT_Callback)(void);
extern void (*UART_Callback)(void);
extern void (*TIMER0_Callback)(void);

void interrupt()
{

    if(GET_BIT(PIR1 , RCIF))
    {
        UART_ISR();
    }

    if(GET_BIT(INTCON , INTF_BIT))
    {
        EXT_INT_ISR();
    }

    if(GET_BIT(INTCON , 2))
    {
        TIMER0_ISR();
    }

}
