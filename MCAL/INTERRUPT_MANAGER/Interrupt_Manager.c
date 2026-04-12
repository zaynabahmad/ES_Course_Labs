#include "../USART/USART_Interface.h"
#include "../EXT_INT/EXT_INT_Interface.h"
#include "../TIMER_0/TIMER_0_Interface.h"
#include "../../SERVICES/BIT_MATH.h"

extern void (*EXT_INT_Callback)(void);
extern void (*UART_Callback)(u8);
extern void (*TIMER0_Callback)(void);

void interrupt(void)
{
    /* UART RX interrupt */
    if(GET_BIT(PIR1, RCIF))
    {
        UART_ISR();
    }

    /* External interrupt (INT pin / RB0) */
    if(GET_BIT(INTCON, INTF_BIT))
    {
        EXT_INT_ISR();
    }

    /* Timer0 overflow interrupt */
    if(GET_BIT(INTCON, T0IF))
    {
        TIMER0_ISR();
    }
}
