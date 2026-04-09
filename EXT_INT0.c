#include "EXT_INT0.h"


static ExtInt0_CallbackFunc_t g_ExtInt0_AppCallback = 0;

void EXT_INT0_Initialize(void)
{

    TRISB.F0 = 1;


    INTCON.INTE = 0;
    INTCON.INTF = 0;
}

void EXT_INT0_SetTriggerEdge(ExtInt0_EdgeType_t edge)
{

    OPTION_REG.INTEDG = edge;
}

void EXT_INT0_EnableInterrupt(void)
{

    INTCON.INTF = 0;
    INTCON.INTE = 1;
    INTCON.GIE = 1;
}

void EXT_INT0_DisableInterrupt(void)
{
    INTCON.INTE = 0;
}

void EXT_INT0_RegisterCallback(ExtInt0_CallbackFunc_t callbackFunc)
{

    if (callbackFunc != 0)
    {
        g_ExtInt0_AppCallback = callbackFunc;
    }
}

void interrupt()
{

    if (INTCON.INTF == 1)
    {

        if (g_ExtInt0_AppCallback != 0)
        {
            g_ExtInt0_AppCallback();
        }


        INTCON.INTF = 0;
    }
}