#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

#include "../USART/USART_Interface.h"
#include "../EXT_INT/EXT_INT_Interface.h"
#include "../EXT_INT/EXT_INT_Private.h"

/* PIR1 register and flags */
#define PIR1    (*((volatile u8*)0x0C))
#define RCIF    5
#define T0IF    2
#define INTF    1

void interrupt()
{
    if(GET_BIT(INTCON, T0IF))   /* Timer0 - not implemented yet */
    {
        /* TIMER0_ISR(); will later be implemented*/
    }

    if(GET_BIT(INTCON, INTF))   /* External interrupt RB0 */
    {
        EXT_INT_ISR();
    }

    if(GET_BIT(PIR1, RCIF))     /* UART RX */
    {
        UART_ISR();
    }
}