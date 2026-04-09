#include "../USART/USART_interface.h"
#include "../EXT_INT/EXT_INT_interface.h"
#include "../TIMER_0/TIMER_0_Interface.h" 
#include "../../SERVICES/BIT_MATH.h"

extern void (*EXT_INT_Callback)(void);
extern void (*UART_Callback)(void);

// T0IF (Timer0 Interrupt Flag) is Bit 2 of INTCON
#define T0IF_BIT 2

void interrupt()
{
    // UART RX interrupt
    if(GET_BIT(PIR1 , RCIF))
    {
        UART_ISR();
    }

    // External interrupt flag
    if(GET_BIT(INTCON , INTF_BIT))
    {
        EXT_INT_ISR();
    }

    // ADDED: Timer0 interrupt flag
    if(GET_BIT(INTCON, T0IF_BIT))
    {
        TIMER0_ISR();
    }
}