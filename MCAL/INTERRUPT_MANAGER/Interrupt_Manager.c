#include "../USART/USART_Interface.h"
#include "../EXT_INT/EXT_INT_Interface.h"
#include "../TIMER_0/TIMER_0_Interface.h"
#include "../../SERVICES/BIT_MATH.h"

#define INTCON_MGR  (*((volatile unsigned char*)0x0B))
#define PIR1_MGR    (*((volatile unsigned char*)0x0C))

#define RCIF_BIT    5
#define INTF_BIT_M  1
#define T0IF_BIT_M  2
#define T0IE_BIT_M  5

void interrupt()
{
    if(GET_BIT(PIR1_MGR, RCIF_BIT))
    {
        UART_ISR();
    }

    if(GET_BIT(INTCON_MGR, INTF_BIT_M))
    {
        EXT_INT_ISR();
    }

    if(GET_BIT(INTCON_MGR, T0IF_BIT_M) && GET_BIT(INTCON_MGR, T0IE_BIT_M))
    {
        TIMER0_ISR();
    }

}
