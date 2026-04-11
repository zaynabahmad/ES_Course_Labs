#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"

static void (*EXTI0_Callback)(void) = NULL_PTR;

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

    EXT_INT0_SetEdge(EXTI0_EDGE);

    CLR_BIT(INTCON, INTF_BIT);

    EXT_INT0_Enable();
}

void EXT_INT0_HandleInterrupt(void)
{
    if(GET_BIT(INTCON, INTE_BIT) && GET_BIT(INTCON, INTF_BIT))
    {
        CLR_BIT(INTCON, INTF_BIT);

        if(EXTI0_Callback != NULL_PTR)
            EXTI0_Callback();
    }
}

//void __interrupt() ISR(void)
//{
  //  EXT_INT0_HandleInterrupt();
//}