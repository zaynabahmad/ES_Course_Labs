#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

/* Include Interfaces for the ISR functions */
#include "../USART/USART_Interface.h"
#include "../EXT_INT/EXT_INT_interface.h"
#include "../TIMER_0/Timer0_interface.h"
#include "../SPI/SPI_interface.h"


/* Include Private headers so the manager can see INTCON, PIR1, T0IF_BIT, RCIF, etc. */
#include "../USART/USART_Private.h"
#include "../EXT_INT/EXT_INT_private.h"
#include "../TIMER_0/Timer0_private.h"
#include "../SPI/SPI_private.h"


extern void (*EXT_INT_Callback)(void);
extern void (*UART_Callback)(void);

/* This is the single, central Interrupt Service Routine for the entire project */
void interrupt() 
{
    /* --- External Interrupt 0 --- */
    /* Check the External Interrupt Flag */
    if(GET_BIT(INTCON, INTF_BIT) == 1)
    {
        /* Call the ISR handler from the EXT_INT driver */
        /* Note: EXT_INT_ISR() will clear its own flag */
        EXT_INT_ISR();
    }
    
    /* --- USART Receive Interrupt --- */
    /* Check the USART Receive Interrupt Flag */
    if(GET_BIT(PIR1, RCIF_BIT) == 1)
    {
        /* Call the ISR handler from the USART driver */
        UART_ISR();
    }
    
    /* --- Timer0 Overflow Interrupt --- */
    /* Check the Timer0 Overflow Interrupt Flag */
    if(GET_BIT(INTCON, T0IF_BIT) == 1)
    {
        /* Call the ISR handler from the TIMER_0 driver */
        /* Note: TMR0_ISR_Handler() will clear its own flag */
        TMR0_ISR_Handler(); 
    }

    // SPI (MSSP) interrupt
    if(GET_BIT(PIR1, SSPIF_BIT) == 1)
    {
        /* Note: SPI_ISR will clear its own flag */
        SPI_ISR();
    }
    
    /* Add other interrupt flag checks here as we add more drivers (e.g., ADC) */
}