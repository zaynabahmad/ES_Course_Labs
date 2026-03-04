#include "interrupt_Interface.h"
#include "interrupt_private.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_private.h" 

// Global Pointer to Function (Your Callback)
static void (*EXT_INT0_Callback)(void) = NULL;

void EXT_INT0_Init(void)
{
    // Your logic: Set RB0 as Input
    SET_BIT(TRISB, 0);
}

void EXT_INT0_Enable(void)
{
    // Your logic to clear flag and enable
    CLR_BIT(INTCON, INTF_BIT);
    SET_BIT(INTCON, INTE_BIT);
    SET_BIT(INTCON, GIE_BIT);
}

void EXT_INT0_Disable(void)
{
    // Your logic to disable
    CLR_BIT(INTCON, INTE_BIT);
    CLR_BIT(INTCON, GIE_BIT);
}

void EXT_INT0_SetEdge(u8 edge_type)
{
    // Your logic with fixed switch case syntax
    switch (edge_type)
    {
    case RISE:
        SET_BIT(OPTION_REG, INTEDG_BIT);
        break;
    case FALL:
        CLR_BIT(OPTION_REG, INTEDG_BIT);
        break;
    default: break;
    }
}

void EXT_INT0_SetCallback(void(*ptr)(void))
{
    EXT_INT0_Callback = ptr;
}

// ISR Implementation (Required by MCAL rules)
void __interrupt() ISR(void)
{
    if (GET_BIT(INTCON, INTF_BIT) == 1)
    {
        if (EXT_INT0_Callback != NULL)
        {
            EXT_INT0_Callback();
        }
        CLR_BIT(INTCON, INTF_BIT);
    }
}