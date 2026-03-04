#include "EXTI_interface.h"
#include "EXTI_private.h"
 
 
#include "../../SERVICES/BIT_MATH.h"



void EXT_INT0_Init(void)
{
    SET_BIT(TRISB, 0);
    CLR_BIT(INTCON, 1); // INTF
    CLR_BIT(INTCON, 4); // INTE
    SET_BIT(INTCON, 7); // GIE
    SET_BIT(OPTION_REG, 6);   // INTEGD -> Falling




}

void EXT_INT0_Enable(void)
{
    CLR_BIT(INTCON, 1); // INTF
    SET_BIT(INTCON, 4); // INTE
}

void EXT_INT0_Disable(void)
{
    CLR_BIT(INTCON, 4);
}

void EXT_INT0_SetEdge(u8 edge_type)
{
    if(edge_type == RISING_EDGE) {
        SET_BIT(OPTION_REG, 6);   // INTEGD -> Rising
    } else {
        CLR_BIT(OPTION_REG, 6);   // INTEGD -> Falling
    }
}

static void (*EXT_INT0_Callback)(void) = 0;

void EXT_INT0_SetCallback(void (*ptr)(void))
{
    EXT_INT0_Callback = ptr;
}


void interrupt()
{
    if(GET_BIT(INTCON, 1)) {
        CLR_BIT(INTCON, 1);
        if(EXT_INT0_Callback) {
            EXT_INT0_Callback();
        }
    }
}