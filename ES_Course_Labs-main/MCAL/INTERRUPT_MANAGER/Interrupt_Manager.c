#include "../USART/USART_interface.h"
#include "../EXT_INT/EXT_INT_interface.h"
#include "../TIMER_0/TIMER_0_Interface.h"
#include "../TIMER_0/TIMER_0_Private.h"
#include "../../SERVICES/BIT_MATH.h"

extern void (*EXT_INT_Callback)(void);
extern void (*UART_Callback)(void);

void interrupt()
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

    // timer0 interrupt flag
    if(GET_BIT(INTCON , TMR0IF))
    {
        TIMER0_ISR();
    }

}
