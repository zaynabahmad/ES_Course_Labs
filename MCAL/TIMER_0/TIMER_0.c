#include "TIMER_0_Interface.h"
#include "TIMER_0_Private.h"
#include "../../SERVICES/BIT_MATH.h"

static void (*TIMER0_Callback)(void) = 0;
static u8 TIMER0_PreloadShadow = 0;

void TIMER0_Init(TIMER0_ConfigType *ConfigPtr)
{
    if (ConfigPtr == 0)
    {
        return;
    }

    TIMER0_PreloadShadow = ConfigPtr->PreloadValue;
    TMR0 = ConfigPtr->PreloadValue;

    if (ConfigPtr->Mode == TIMER0_COUNTER_MODE)
    {
        SET_BIT(OPTION_T0, T0CS_BIT);
    }
    else
    {
        CLR_BIT(OPTION_T0, T0CS_BIT);
    }

    if (ConfigPtr->EdgeSelect == TIMER0_HIGH_TO_LOW_EDGE)
    {
        SET_BIT(OPTION_T0, T0SE_BIT);
    }
    else
    {
        CLR_BIT(OPTION_T0, T0SE_BIT);
    }

    if (ConfigPtr->PrescalerAssignment == TIMER0_PRESCALER_TO_WDT)
    {
        SET_BIT(OPTION_T0, PSA_BIT);
    }
    else
    {
        CLR_BIT(OPTION_T0, PSA_BIT);
        OPTION_T0 &= (u8)~0x07;
        OPTION_T0 |= (ConfigPtr->PrescalerValue & 0x07);
    }

    CLR_BIT(INTCON_T0, TMR0IF_BIT);

    if (ConfigPtr->InterruptEnable != 0)
    {
        SET_BIT(INTCON_T0, TMR0IE_BIT);
        SET_BIT(INTCON_T0, GIE_BIT);
    }
}

void TIMER0_Start(void)
{
    CLR_BIT(OPTION_T0, T0CS_BIT);
}

void TIMER0_Stop(void)
{
    SET_BIT(OPTION_T0, T0CS_BIT);
}

void TIMER0_WriteValue(u8 Value)
{
    TIMER0_PreloadShadow = Value;
    TMR0 = Value;
}

u8 TIMER0_ReadValue(void)
{
    return TMR0;
}

void TIMER0_SetCallback(void (*Callback)(void))
{
    TIMER0_Callback = Callback;
}

void TIMER0_ISR(void)
{
    CLR_BIT(INTCON_T0, TMR0IF_BIT);
    TMR0 = TIMER0_PreloadShadow;

    if (TIMER0_Callback != 0)
    {
        TIMER0_Callback();
    }
}
