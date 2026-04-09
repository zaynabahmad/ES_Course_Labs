// ES_Drivers/MCAL/INTERRUPT_MANAGER/Interrupt_Manager.c
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../EXT_INT0/EXT_INT0_private.h"   // for INTCON register
#include "../TIMER0/TIMER0_interface.h"      // for TMR0IF, TMR0 
#include "../USART/USART_Private.h"          // for PIR1, RCREG, RCIF
#include "../../APP/ISR_Actions.h"

// Forward declarations of the low-level ISR handlers
// These ONLY touch registers and flags — no HAL calls
static void handle_uart_isr(void);
static void handle_extint_isr(void);
static void handle_timer0_isr(void);

void interrupt()
{
    // UART RX
    if (GET_BIT(PIR1, RCIF))
    {
        handle_uart_isr();
    }

    // External INT0
    if (GET_BIT(INTCON, INTF_BIT))
    {
        handle_extint_isr();
    }

    // Timer0
    if (GET_BIT(INTCON, TMR0IF))
    {
        handle_timer0_isr();
    }
}

// ---- Only register access and flag setting below ----

static void handle_uart_isr(void)
{
    g_uart_rx_byte = RCREG;      // must read to clear RCIF
    g_flag_uart_rx = 1;
    // RCIF clears automatically on RCREG read
}

static void handle_extint_isr(void)
{
    CLR_BIT(INTCON, INTF_BIT);   // clear flag
    g_flag_extint = 1;
}

static void handle_timer0_isr(void)
{
    TMR0 = 6;                     // preload
    CLR_BIT(INTCON, TMR0IF);     // clear flag
    g_flag_timer = 1;
}
