/**
 * @file    EXTI.c
 * @brief   External interrupt (INT0/RB0) driver implementation.
 *
 * @details The callback is stored in a single static pointer. The handler is
 *          split out from the chip's lone ISR so that the ISR itself owns no
 *          register knowledge -- it just calls each driver's handler in turn.
 */
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_cfg.h"
#include "../SERVICES/Macros.h"

/* RB0 lives on PORTB/TRISB -- needed only to set the pin as input. */
#define EXTI_REG_TRISB      ( *((volatile byte_t *)0x86u) )
#define EXTI_PIN_RB0        0u

/** Routine invoked on each accepted edge; NULL_PTR until registered. */
static pfEXTI_Callback_t pfEdgeAction = NULL_PTR;

void vEXTI_Init(void)
{
    BIT_HIGH(EXTI_REG_TRISB, EXTI_PIN_RB0);     /* INT pin must be an input. */
    vEXTI_SetEdge(EXTI_DEFAULT_EDGE);
    BIT_LOW(EXTI_REG_INTCON, EXTI_BIT_INTF);    /* discard any stale edge.   */
}

void vEXTI_Enable(void)
{
    BIT_LOW(EXTI_REG_INTCON, EXTI_BIT_INTF);    /* start from a clean flag.  */
    BIT_HIGH(EXTI_REG_INTCON, EXTI_BIT_INTE);   /* unmask the INT source.    */
    BIT_HIGH(EXTI_REG_INTCON, EXTI_BIT_GIE);    /* arm the global gate.      */
}

void vEXTI_Disable(void)
{
    BIT_LOW(EXTI_REG_INTCON, EXTI_BIT_INTE);
}

void vEXTI_SetEdge(eEdge_t eEdge)
{
    switch (eEdge)
    {
        case EXTI_EDGE_RISING:  BIT_HIGH(EXTI_REG_OPTION, EXTI_BIT_INTEDG); break;
        case EXTI_EDGE_FALLING: BIT_LOW(EXTI_REG_OPTION, EXTI_BIT_INTEDG);  break;
        default:                /* unknown edge -> leave hardware as-is */  break;
    }
}

void vEXTI_SetCallback(pfEXTI_Callback_t pfCallback)
{
    pfEdgeAction = pfCallback;
}

void vEXTI_IsrHandler(void)
{
    /* Two gates before acting: the source must be both enabled and pending,
     * otherwise this edge belongs to a different peripheral. */
    if (BIT_IS_RAISED(EXTI_REG_INTCON, EXTI_BIT_INTE) &&
        BIT_IS_RAISED(EXTI_REG_INTCON, EXTI_BIT_INTF))
    {
        BIT_LOW(EXTI_REG_INTCON, EXTI_BIT_INTF);    /* re-arm before callback. */

        if (pfEdgeAction != NULL_PTR)
        {
            pfEdgeAction();
        }
    }
}
