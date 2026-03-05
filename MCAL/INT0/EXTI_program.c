#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/* Global pointer to function to store the application's callback address */
static void (*EXTI_CallBack)(void) = NULL_PTR;

void EXTI_voidInit(void)
{
    /* 1. Select the interrupt edge based on the configuration file */
#if EXTI_SENSE_CONTROL == EXTI_RISING_EDGE
    SET_BIT(OPTION_REG, OPTION_REG_INTEDG);
#elif EXTI_SENSE_CONTROL == EXTI_FALLING_EDGE
    CLR_BIT(OPTION_REG, OPTION_REG_INTEDG);
#endif

    /* 2. Clear the interrupt flag to ensure no pending interrupts trigger immediately */
    CLR_BIT(INTCON, INTCON_INTF);
}

void EXTI_voidSetEdge(u8 Copy_u8Edge)
{
    if(Copy_u8Edge == EXTI_RISING_EDGE)
    {
        SET_BIT(OPTION_REG, OPTION_REG_INTEDG);
    }
    else if(Copy_u8Edge == EXTI_FALLING_EDGE)
    {
        CLR_BIT(OPTION_REG, OPTION_REG_INTEDG);
    }
}

void EXTI_voidEnable(void)
{
    SET_BIT(INTCON, INTCON_INTE);
}

void EXTI_voidDisable(void)
{
    CLR_BIT(INTCON, INTCON_INTE);
}

void EXTI_voidClearFlag(void)
{
    CLR_BIT(INTCON, INTCON_INTF);
}

void EXTI_voidEnableGlobalInterrupt(void)
{
    SET_BIT(INTCON, INTCON_GIE);
}

void EXTI_voidDisableGlobalInterrupt(void)
{
    CLR_BIT(INTCON, INTCON_GIE);
}

void EXTI_voidSetCallBack(void (*Copy_pVoidCallBack)(void))
{
    if(Copy_pVoidCallBack != NULL_PTR)
    {
        EXTI_CallBack = Copy_pVoidCallBack;
    }
}

/* * Interrupt Service Routine (ISR)
 * Note: `__interrupt()` is typical syntax for the XC8 compiler.
 */
void interrupt(void)
{
    /* Check if the interrupt occurred due to INT0 (External Interrupt) */
    if(GET_BIT(INTCON, INTCON_INTF) == 1)
    {
        /* Important Note Requirement: Always clear INTF inside ISR */
        CLR_BIT(INTCON, INTCON_INTF);

        /* Execute the callback function if it has been assigned */
        if(EXTI_CallBack != NULL_PTR)
        {
            EXTI_CallBack();
        }
    }
}