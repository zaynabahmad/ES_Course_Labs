#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"

static void (*EXTI0_Callback)(void) = 0;

void EXT_INT0_SetCallback(void (*ptr)(void))
{
    EXTI0_Callback = ptr;
}

void EXT_INT0_SetEdge(u8 edge_type)
{
    if(edge_type == EXTI_RISING_EDGE)
        SET_BIT(OPTION_REG, INTEDG_BIT);
    else
        CLR_BIT(OPTION_REG, INTEDG_BIT);
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

void EXT_INT0_Init(void)
{
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);

    EXT_INT0_SetEdge(EXTI_FALLING_EDGE);

    CLR_BIT(INTCON, INTF_BIT);

    EXT_INT0_Enable();
}

void interrupt(void)
{
    if(GET_BIT(INTCON, INTF_BIT))
    {
        CLR_BIT(INTCON, INTF_BIT);

        if(EXTI0_Callback != 0)
            EXTI0_Callback();
    }
}