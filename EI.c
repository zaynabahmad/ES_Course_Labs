#include "EI.h"

static void (*EI_Callback)(void);

void EI_Init(void)
{
    INTCON.INTE = 0;
    INTCON.INTF = 0;
    TRISB.F0 = 1;
}
void EI_SetEdge(unsigned char edge_type)
{
    OPTION_REG.INTEDG = edge_type;
}
void EI_SetCallback(void (*ptr)(void))
{
    EI_Callback = ptr;
}
void EI_Enable(void)
{
    INTCON.INTF = 0;
    INTCON.INTE = 1;
    INTCON.GIE  = 1;
}
void EI_Disable(void)
{
    INTCON.INTE = 0;
}

void interrupt()
{
    if(INTCON.INTF)
    {
        if(EI_Callback != 0)
        {
            EI_Callback();   // Call application function
        }

        INTCON.INTF = 0;           // Clear flag
    }
}