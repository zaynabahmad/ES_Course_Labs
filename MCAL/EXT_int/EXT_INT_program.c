
#include "EXT_INT_interface.h"
#include "EXT_INT_private.h"
#include "EXT_INT_config.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

void (*EXT_INT0_Callback)(void) = NULL_PTR;


#if EXT_INT0_DEBOUNCE_EN == 1
static void Debounce_Delay(void)
{
    u16 i, j;
    /* ~1 ms per outer iteration at 8 MHz */
    for (i = 0; i < EXT_INT0_DEBOUNCE_MS; i++)
    {
        for (j = 0; j < 800u; j++) 
        { 
        }
    }
}
#endif


void EXT_INT0_Init(void)
{
    SET_BIT(TRISB,TRISB0);

    CLR_BIT(OPTION_REG, OPTION_nRBPU);

    EXT_INT0_SetEdge(EXT_INT0_EDGE);

    CLR_BIT(INTCON, INTCON_INTF);

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
    {
        SET_BIT(OPTION_REG, OPTION_INTEDG);
    }
    else  /* EXT_INT_FALLING_EDGE */
    {
        CLR_BIT(OPTION_REG, OPTION_INTEDG);
    }
}


void EXT_INT0_SetCallback(void (*ptr)(void))
{
    EXT_INT0_Callback = ptr;
}


/*void interrupt()
{
    if (GET_BIT(INTCON, INTCON_INTF) == 1)
    {
        CLR_BIT(INTCON, INTCON_INTF);

        #if EXT_INT0_DEBOUNCE_EN == 1
            Debounce_Delay();
        #endif

        if (EXT_INT0_Callback != NULL_PTR)
        {
            EXT_INT0_Callback();
        }
    }
}*/