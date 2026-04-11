#include "../USART/USART_interface.h"
#include "../EXT_INT/EXT_INT_interface.h"
#include "../TIMER_0/TIMER_0_Interface.h"
#include "../../SERVICES/BIT_MATH.h"

/* External callbacks (already used) */
extern void (*EXT_INT_Callback)(void);
extern void (*UART_Callback)(void);

void interrupt()
{

    // ================= UART RX =================
    if(GET_BIT(PIR1 , RCIF))
    {
        UART_ISR();
    }

    // ================= External Interrupt =================
    if(GET_BIT(INTCON , INTF_BIT))
    {
        EXT_INT_ISR();
    }

    // ================= TIMER0 Interrupt =================
    if(GET_BIT(INTCON , T0IF))
    {
        TIMER0_ISR();
    }

}