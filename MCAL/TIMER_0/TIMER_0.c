#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "TIMER_0_Interface.h"
#include "TIMER_0_Private.h"
#include "TIMER_0_Config.h"


static void (*TMR0_pvCallBackFunc)(void) = NULL;

void TMR0_voidInit(void)
{

    CLR_BIT(OPTION_REG, T0CS);
    CLR_BIT(OPTION_REG, PSA);
    OPTION_REG = (OPTION_REG & PRESCALER_MASK) | (TMR0_PRESCALER_VAL & 0x07);
    TMR0_REG = TMR0_PRELOAD_VAL;
    CLR_BIT(INTCON_REG, T0IF);
    CLR_BIT(INTCON_REG, T0IE);
}

void TMR0_voidEnableInterrupt(void)
{
    SET_BIT(INTCON_REG, GIE);
    SET_BIT(INTCON_REG, T0IE);
}

void TMR0_voidDisableInterrupt(void)
{
    CLR_BIT(INTCON_REG, T0IE);
}

void TMR0_voidSetCallback(void (*pvCallBackFunc)(void))
{
    if (pvCallBackFunc != NULL)
    {
        TMR0_pvCallBackFunc = pvCallBackFunc;
    }
}

void TMR0_ISR(void)
{

    CLR_BIT(INTCON_REG, T0IF);


    TMR0_REG = TMR0_PRELOAD_VAL;


    if (TMR0_pvCallBackFunc != NULL)
    {
        TMR0_pvCallBackFunc();
    }
}