#include "ext_int0.h"
#include "ext_int0_private.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"

/* Private callback pointer */
static void (*EXT_INT0_CallbackFptr)(void) = 0;

void EXT_INT0_Init(void)
{
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
    CLR_BIT(INTCON, INTF);
}

void EXT_INT0_SetEdge(u8 Edge)
{
    if(Edge == EXT_INT0_RISING_EDGE)
        SET_BIT(OPTION_REG, INTEDG);
    else
        CLR_BIT(OPTION_REG, INTEDG);
}

void EXT_INT0_SetCallback(void (*LocalFptr)(void))
{
    EXT_INT0_CallbackFptr = LocalFptr;
}

void EXT_INT0_Enable(void)
{
    SET_BIT(INTCON, INTE);
    SET_BIT(INTCON, GIE);
}

void EXT_INT0_Disable(void)
{
    CLR_BIT(INTCON, INTE);
}

void interrupt(void)
{
    if(GET_BIT(INTCON, INTF) == 1)
    {
        CLR_BIT(INTCON, INTF);
        if(EXT_INT0_CallbackFptr != 0)
            EXT_INT0_CallbackFptr();
    }
}