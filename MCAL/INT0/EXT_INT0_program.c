#include "EXT_INT0_interface.h"
#include "EXT_INT0_private.h"
#include "EXT_INT0_config.h"

// Callback pointer
void (*EXT_INT0_Callback)(void) = 0;

void EXT_INT0_Init(void)
{
    // Set RB0 as input
     SET_BIT(TRISB_REG, 0);

    // Set edge
    EXT_INT0_SetEdge(EXT_INT0_EDGE);

    // Clear flag
    INTF_bit = 0;

    // Enable interrupt
    EXT_INT0_Enable();
}

void EXT_INT0_Enable(void)
{
    INTE_bit = 1;
    GIE_bit = 1;
}

void EXT_INT0_Disable(void)
{
    INTE_bit = 0;
}

void EXT_INT0_SetEdge(u8 edge_type)
{
    if(edge_type == RISING_EDGE)
        INTEDG_bit = 1;
    else
        INTEDG_bit = 0;
}

void EXT_INT0_SetCallback(void (*ptr)(void))
{
    EXT_INT0_Callback = ptr;
}