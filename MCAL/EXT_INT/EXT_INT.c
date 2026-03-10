#include "EXT_INT_interface.h"
#include "EXT_INT_private.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"

static void (*EXT_INT0_Callback)(void) = NULL_PTR;

void EXT_INT0_Init(void)
{
    /* Configure RB0 as input (TRISB0 = 1) */
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);

    /* Default: falling edge (button press pulls RB0 low) */
    CLR_BIT(OPTION_REG, OPTION_INTEDG);

    /* Clear INT0 flag before enabling */
    CLR_BIT(INTCON, INTCON_INTF);

    /* Enable INT0 and global interrupts */
    SET_BIT(INTCON, INTCON_INTE);
    SET_BIT(INTCON, INTCON_GIE);
}

void EXT_INT0_Enable(void)
{
    SET_BIT(INTCON, INTCON_INTE);
    SET_BIT(INTCON, INTCON_GIE);
}

void EXT_INT0_Disable(void)
{
    CLR_BIT(INTCON, INTCON_INTE);
}

void EXT_INT0_SetEdge(u8 edge_type)
{
    if (edge_type == EXT_INT_RISING_EDGE)
        SET_BIT(OPTION_REG, OPTION_INTEDG);
    else
        CLR_BIT(OPTION_REG, OPTION_INTEDG);
}

void EXT_INT0_SetCallback(void (*ptr)(void))
{
    EXT_INT0_Callback = ptr;
}

/* IRQ handler — called from the unified interrupt() dispatcher in APP/main.c.
   Checks its own flag internally so the dispatcher can call it unconditionally. */
void EXT_INT0_IRQHandler(void)
{
    if (!GET_BIT(INTCON, INTCON_INTF))
        return;                         /* not an EXT_INT0 interrupt */

    if (EXT_INT0_Callback != NULL_PTR)
        EXT_INT0_Callback();

    CLR_BIT(INTCON, INTCON_INTF);
}
