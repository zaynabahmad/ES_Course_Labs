#include "EXT_interface.h"
#include "EXT_private.h"
#include "EXT_config.h" 
#include "../../SERVICES/BIT_MATH.h"

static void (*EXT_INT0_Callback)(void) = NULL;

void EXT_INT0_Init(void)
{
    SET_BIT(TRISB,  TRISB0_BIT);  


    #if EXT_INT0_DEFAULT_EDGE == EXT_INT0_RISING_EDGE
        SET_BIT(OPTION_REG, INTEDG_BIT);
    #elif EXT_INT0_DEFAULT_EDGE == EXT_INT0_FALLING_EDGE
        CLR_BIT(OPTION_REG, INTEDG_BIT);
    #endif

    CLR_BIT(INTCON, INTF_BIT);    
}

void EXT_INT0_Enable(void)
{
    SET_BIT(INTCON, INTE_BIT);     
    SET_BIT(INTCON, GIE_BIT);      
}

void EXT_INT0_Disable(void)
{
    CLR_BIT(INTCON, INTE_BIT);     
}

void EXT_INT0_SetEdge(uint8 edge_type)
{
    if(edge_type == EXT_INT0_RISING_EDGE)
        SET_BIT(OPTION_REG, INTEDG_BIT);  
    else
        CLR_BIT(OPTION_REG, INTEDG_BIT);  
}

void EXT_INT0_SetCallback(void (*ptr)(void))
{
    EXT_INT0_Callback = ptr;
}

void interrupt(void)
{
    if(GET_BIT(INTCON, INTF_BIT))
    {
        CLR_BIT(INTCON, INTF_BIT);        

        if(EXT_INT0_Callback != NULL)
        {
            EXT_INT0_Callback();
        }
    }
}