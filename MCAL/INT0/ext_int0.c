#include "ext_int0.h"

void (*INT0_Callback)(void) = 0;

void EXT_INT0_Init(void)
{
    TRISB.F0 = 1;
    OPTION_REG.F6 = 1;
    INTCON.F1 = 0;
}

void EXT_INT0_Enable(void)
{
    INTCON.F7 = 1;
    INTCON.F4 = 1;
}

void EXT_INT0_Disable(void)
{
    INTCON.F4 = 0;
}

void EXT_INT0_SetEdge(u8 edge_type)
{
    OPTION_REG.F6 = edge_type;
}

void EXT_INT0_SetCallback(void (*ptr)(void))
{
    INT0_Callback = ptr;
}

void interrupt()
{
    if (INTCON.F1 == 1)
    {
        INTCON.F1 = 0;
        if (INT0_Callback != 0)
        {
            INT0_Callback();
        }
    }
}