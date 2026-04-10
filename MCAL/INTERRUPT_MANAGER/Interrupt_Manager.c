#include "../UART/UART_interface.h"
#include "../EXT_INT/EXT_INT_Interface.h"
#include "../../SERVICES/BIT_MATH.h"

/* Missing Hardware Register Definitions for UART Interrupts */
#ifndef PIR1
    #define PIR1 (*((volatile uint8*)0x0C))
#endif

#ifndef RCIF
    #define RCIF 5
#endif

extern void (*EXT_INT_Callback)(void);
extern void (*UART_Callback)(void);

/* Explicitly declare UART_ISR to prevent implicit declaration warnings */
extern void UART_ISR(void);

void interrupt()
{
    // UART RX interrupt
    if(GET_BIT(PIR1, RCIF))
    {
        UART_ISR();
    }

    // External interrupt flag
    // (INTCON and INTF_BIT are pulled from EXT_INT_Interface.h -> EXT_INT_Private.h)
    if(GET_BIT(INTCON, INTF_BIT))
    {
        EXT_INT_ISR();
    }
}