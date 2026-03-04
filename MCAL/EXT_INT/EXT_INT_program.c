#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"
#include "EXT_INT_interface.h"
#include "EXT_INT_private.h"

static void (*EXTI0_CallBack)(void) = NULL_PTR;

void EXT_INT0_Init(void)
{
    /* Configure TRISB0 as input */
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);

    /* Configure INTEDG (Rising) */
    SET_BIT(OPTION_REG, INTEDG);

    /* Clear INTF */
    CLR_BIT(INTCON, INTF);
}

void EXT_INT0_Enable(void)
{
    /* Enable INTE and GIE */
    SET_BIT(INTCON, INTE);
    SET_BIT(INTCON, GIE);
}

void EXT_INT0_Disable(void)
{
    CLR_BIT(INTCON, INTE);
}

void EXT_INT0_SetEdge(u8 edge_type)
{
    if (edge_type == RISING_EDGE)
        SET_BIT(OPTION_REG, INTEDG);
    else
        CLR_BIT(OPTION_REG, INTEDG);
}

void EXT_INT0_SetCallback(void (*LocalPtr)(void))
{
    EXTI0_CallBack = LocalPtr;
}

/* ISR inside MCAL only, calls callback function only */
void __interrupt() ISR(void)
{
    if (GET_BIT(INTCON, INTF) == 1)
    {
        if (EXTI0_CallBack != NULL_PTR)
        {
            EXTI0_CallBack();
        }
        /* Clear INTF inside ISR */
        CLR_BIT(INTCON, INTF);
    }
}