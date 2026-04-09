#include "EXT_INT_Interface.h"
#include "EXT_INT_Config.h"
#include "EXT_INT_Private.h"

#include "../GPIO/GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"


void EXT_INT_Init(void)
{
    GPIO_SetPinDirection(EXT_INT_PORT, EXT_INT_PIN, GPIO_INPUT);

    EXT_INT_SetEdge(EXT_INT_FALLING_EDGE);

    CLR_BIT(INTCON, INTF_BIT);
    CLR_BIT(INTCON, INTE_BIT);

}

void EXT_INT_Enable(void)
{
    SET_BIT(INTCON, INTE_BIT);
    SET_BIT(INTCON, GIE_BIT);

    CLR_BIT(INTCON, INTF_BIT);
}

void EXT_INT_Disable(void)
{
    CLR_BIT(INTCON, INTF_BIT);
    CLR_BIT(INTCON, INTE_BIT);

}

void EXT_INT_SetEdge(u8 EdgeType)
{
    if (EdgeType == EXT_INT_RISING_EDGE)
    {
        SET_BIT(OPTION_REG, INTEDGE_BIT);
    }
    else if (EdgeType == EXT_INT_FALLING_EDGE)
    {
        CLR_BIT(OPTION_REG, INTEDGE_BIT);
    }
}

static void (*EXT_INT_Callback)(void) = NULL_PTR;

void EXT_INT_SetCallback(void (*ptr)(void)) {
    if (ptr != NULL_PTR) {
        EXT_INT_Callback = ptr;
    }
}

void EXT_INT_ISR(void)
{

    CLR_BIT(INTCON , INTF_BIT);

    if(EXT_INT_Callback != NULL_PTR)
    {
        EXT_INT_Callback();
    }

}