#include "C:\Users\engfa\OneDrive\Desktop\Embedded CIE 349\EmbeddedLab2\LabTask - External Interrupt (INT0) driver\INT0_Folders\MCAL\EXIT_INT0 .h"

static void (*EXT_INT0_Callback)(void);

void EXT_INT0_Init(void)
{
    TRISB.F0 = 1;            // RB0 input
    INTCON.INTE = 0;         // Disable first
    INTCON.INTF = 0;         // Clear flag
}

void EXT_INT0_SetEdge(unsigned char edge_type)
{
    OPTION_REG.INTEDG = edge_type;
}

void EXT_INT0_Enable(void)
{
    INTCON.INTF = 0;
    INTCON.INTE = 1;
    INTCON.GIE  = 1;
}

void EXT_INT0_Disable(void)
{
    INTCON.INTE = 0;
}

void EXT_INT0_SetCallback(void (*ptr)(void))
{
    EXT_INT0_Callback = ptr;
}

void interrupt()
{
    if(INTCON.INTF)
    {
        if(EXT_INT0_Callback != 0)
        {
            EXT_INT0_Callback();   // Call application function
        }

        INTCON.INTF = 0;           // Clear flag
    }
}