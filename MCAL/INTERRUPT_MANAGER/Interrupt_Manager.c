#include "../EXT_INT/EXT_INT_Interface.h"
#include "../TIMER_0/TIMER_0_Interface.h"
#include "../UART/UART_interface.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

/* PIR1 – needed for UART RX flag check */
#define PIR1         (*(volatile u8*)0x0C)
#define PIR1_RCIF     5

/* INTCON – shared interrupt control register */
#define ISR_INTCON   (*(volatile u8*)0x0B)
#define ISR_T0IF      2   /* Timer0 overflow flag  */
#define ISR_INTF      1   /* RB0 external int flag */

/* TMR0 register – reloaded inside ISR for accurate period */
#define ISR_TMR0     (*(volatile u8*)0x01)
#define TMR0_PRELOAD  131u   /* matches TIMER_0_Private.h: 8MHz, 1:256, ~16ms */

/* Callbacks defined inside each driver .c file */
extern void (*TMR0_Callback)(void);
extern void (*EXT_INT_Callback)(void);

void interrupt(void)
{
    /* ── Timer0 overflow ───────────────────────────────────────────── */
    if (GET_BIT(ISR_INTCON, ISR_T0IF))
    {
        ISR_TMR0 = TMR0_PRELOAD;          /* reload first for accuracy */
        CLR_BIT(ISR_INTCON, ISR_T0IF);    /* clear flag                */

        if (TMR0_Callback != NULL_PTR)
        {
            TMR0_Callback();
        }
    }

    /* ── External interrupt RB0 ────────────────────────────────────── */
    if (GET_BIT(ISR_INTCON, ISR_INTF))
    {
        EXT_INT_ISR();    /* clears INTF and calls registered callback  */
    }

    /* ── UART RX interrupt ─────────────────────────────────────────── */
/* ── UART RX interrupt ─────────────────────────────────────────── */
if (GET_BIT(PIR1, PIR1_RCIF))
{
    /* UART driver is polling-based — no ISR needed.
     * If interrupt-driven RX is required in the future,
     * add UART_ISR() to UART_program.c and declare it
     * in UART_interface.h first.                        */
}
}