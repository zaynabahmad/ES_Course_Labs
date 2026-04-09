#include "../USART/USART_Interface.h"
#include "../EXT_INT/EXT_INT_Interface.h"
#include "../TIMER_0/TIMER_0_Interface.h"

/* Each ISR checks its own flag internally before executing */
void interrupt(void)
{
    UART_ISR();
    EXT_INT_ISR();
    TIMER0_ISR();
}
