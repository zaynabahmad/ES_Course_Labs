#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "../../SERVICES/BIT_MATH.h"

void EXTI_Init(void)
{
    /* Set edge trigger from config */
    #if EXTI_TRIGGER == EXTI_RISING_EDGE
        SET_BIT(OPTION_REG, INTEDG);
    #else
        CLR_BIT(OPTION_REG, INTEDG);
    #endif

    /* Clear flag before enabling */
    CLR_BIT(INTCON, INTF);

    /* Enable INT0 */
    SET_BIT(INTCON, INTE);

    /* Enable Global Interrupts */
    SET_BIT(INTCON, GIE);
}

void EXTI_Enable(void)
{
    SET_BIT(INTCON, INTE);
    SET_BIT(INTCON, GIE);
}

void EXTI_Disable(void)
{
    CLR_BIT(INTCON, INTE);
}

void EXTI_ClearFlag(void)
{
    CLR_BIT(INTCON, INTF);
}