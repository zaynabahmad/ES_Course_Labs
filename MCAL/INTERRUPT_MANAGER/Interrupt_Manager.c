#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

#include "../USART/USART_Interface.h"
#include "../EXT_INT/EXT_INT_Interface.h"
#include "../EXT_INT/EXT_INT_Private.h"
#include "../TIMER_0/TIMER_0_Interface.h"

/* PIR1 register and flags */
#define PIR1    (*((volatile u8*)0x0C))
#define RCIF    5
#define T0IF    2
#define INTF    1

void interrupt()
{
    if(GET_BIT(INTCON, T0IF))   /* Timer0 */
    {
        TIMER_0_ISR();
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