#include "EXT_INT_Private.h"
#include "EXT_INT_Config.h"
#include "EXT_INT_Interface.h"
#include "../GPIO/GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"

/* Bit positions */
#define GIE_BIT     7
#define INTE_BIT    4
#define INTF_BIT    1
#define INTEDG_BIT  6

static void (*EXT_INT_Callback)(void) = 0;

void EXT_INT_Init(void)
{
    GPIO_SetPinDirection(EXT_INT_PORT, EXT_INT_PIN, GPIO_INPUT);
    EXT_INT_SetEdge(EXT_INT_FALLING_EDGE);
    CLR_BIT(INTCON, INTF_BIT);
    CLR_BIT(INTCON, INTE_BIT);
}

void EXT_INT_Enable(void)
{
    CLR_BIT(INTCON, INTF_BIT);
    SET_BIT(INTCON, INTE_BIT);
    SET_BIT(INTCON, GIE_BIT);
}

void EXT_INT_Disable(void)
{
    CLR_BIT(INTCON, INTE_BIT);
    CLR_BIT(INTCON, INTF_BIT);
}

void EXT_INT_SetEdge(u8 EdgeType)
{
    if (EdgeType == EXT_INT_RISING_EDGE)
        SET_BIT(OPTION_REG, INTEDG_BIT);
    else
        CLR_BIT(OPTION_REG, INTEDG_BIT);
}

void EXT_INT_SetCallback(void (*Callback)(void))
{
    if (Callback != 0)
        EXT_INT_Callback = Callback;
}

void EXT_INT_ISR(void)
{
    if (GET_BIT(INTCON, INTF_BIT))
    {
        CLR_BIT(INTCON, INTF_BIT);
        if (EXT_INT_Callback != 0)
            EXT_INT_Callback();
    }
}
