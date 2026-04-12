#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "Services/bit_math.h"

void EXTI_Init(unsigned char edge)
{
    if (edge == EXTI_RISING_EDGE)
        SET_BIT(OPTION_REG, INTEDG_BIT);
    else
        CLR_BIT(OPTION_REG, INTEDG_BIT);
}

void EXTI_Enable(void)
{
    CLR_BIT(INTCON_REG, INTF_BIT);    /* clear pending flag first */
    SET_BIT(INTCON_REG, INTE_BIT);
    SET_BIT(INTCON_REG, GIE_BIT);
}

void EXTI_Disable(void)
{
    CLR_BIT(INTCON_REG, INTE_BIT);
}