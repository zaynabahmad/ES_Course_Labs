#include "ext_int_interface.h"
#include "ext_int_private.h"
#include "../../SERVICES/bit_ops.h"
#include "../GPIO/gpio_interface.h"

static void (*extint_callback)(void) = NULL_POINTER;

void EXTINT_Setup(void)
{
    /* Configure RB0 as digital input */
    GPIO_ConfigPin(PORTB_ID, PIN0, DIR_IN);
}

void EXTINT_Activate(void)
{
    BIT_SET(INTCON_REG, INTE_BIT);
    BIT_SET(INTCON_REG, GIE_BIT);
}

void EXTINT_Deactivate(void)
{
    BIT_CLEAR(INTCON_REG, INTE_BIT);
}

void EXTINT_SetTriggerEdge(u8 edge)
{
    if(edge == EDGE_RISING)
        BIT_SET(OPTION_REG_REG, INTEDG_BIT);
    else
        BIT_CLEAR(OPTION_REG_REG, INTEDG_BIT);
}

void EXTINT_RegisterCallback(void (*callback)(void))
{
    extint_callback = callback;
}

void EXTINT_ClearFlag(void)
{
    BIT_CLEAR(INTCON_REG, INTF_BIT);
}

/* ISR called from main interrupt dispatcher */
void EXTINT_ISR_Handler(void)
{
    if(extint_callback != NULL_POINTER)
    {
        extint_callback();
    }
    BIT_CLEAR(INTCON_REG, INTF_BIT);
}