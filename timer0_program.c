#include "timer0_interface.h"
#include "timer0_private.h"
#include "timer0_config.h"
#include "../../SERVICES/bit_ops.h"

static void (*timer0_callback)(void) = NULL_POINTER;

void Timer0_Configure(void)
{
    /* Internal instruction clock */
    BIT_CLEAR(OPTION_REG_REG, T0CS);
    /* Assign prescaler to Timer0 */
    BIT_CLEAR(OPTION_REG_REG, PSA);
    /* Mask and set prescaler bits */
    OPTION_REG_REG &= 0xF8;
    OPTION_REG_REG |= SELECTED_PRESCALER;

    BIT_SET(INTCON_REG, T0IE);
    BIT_SET(INTCON_REG, GIE);
}

void Timer0_Run(void)
{
    BIT_CLEAR(INTCON_REG, T0IF);
}

void Timer0_Halt(void)
{
    BIT_CLEAR(INTCON_REG, T0IE);
}

void Timer0_LoadCounter(u8 value)
{
    TMR0_REG = value;
}

void Timer0_AttachCallback(void (*cb)(void))
{
    timer0_callback = cb;
}

void Timer0_ISR_Handler(void)
{
    if(timer0_callback != NULL_POINTER)
    {
        timer0_callback();
    }
    BIT_CLEAR(INTCON_REG, T0IF);
}