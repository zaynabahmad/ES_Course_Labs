#include "TIMER_0_Interface.h"
#include "TIMER_0_Private.h"
#include "TIMER_0_Config.h"

#include "../../SERVICES/BIT_MATH.h"

static void (*TIMER0_Callback)(void) = NULL_PTR;

void TIMER0_Init(void)
{
	if (TIMER0_CLOCK_SOURCE == TIMER0_EXTERNAL_CLOCK)
	{
		SET_BIT(OPTION_REG, T0CS_BIT);
	}
	else
	{
		CLR_BIT(OPTION_REG, T0CS_BIT);
	}

	if (TIMER0_PRESCALER_ENABLE == TIMER0_PRESCALER_OFF)
	{
		SET_BIT(OPTION_REG, PSA_BIT);
	}
	else
	{
		CLR_BIT(OPTION_REG, PSA_BIT);
		OPTION_REG = (u8)((OPTION_REG & (u8)0xF8) | (TIMER0_PRESCALER_VALUE & (u8)0x07));
	}

	TMR0 = 0;
	CLR_BIT(INTCON, T0IF_BIT);
}

void TIMER0_Start(void)
{
	CLR_BIT(INTCON, T0IF_BIT);
}

void TIMER0_Stop(void)
{
	CLR_BIT(INTCON, T0IE_BIT);
}

void TIMER0_SetPreload(u8 Value)
{
	TMR0 = Value;
}

u8 TIMER0_GetValue(void)
{
	return TMR0;
}

void TIMER0_EnableInterrupt(void)
{
	CLR_BIT(INTCON, T0IF_BIT);
	SET_BIT(INTCON, T0IE_BIT);
	SET_BIT(INTCON, GIE_BIT);
}

void TIMER0_DisableInterrupt(void)
{
	CLR_BIT(INTCON, T0IE_BIT);
}

void TIMER0_SetCallback(void (*Callback)(void))
{
	if (Callback != NULL_PTR)
	{
		TIMER0_Callback = Callback;
	}
}

void TIMER0_ISR(void)
{
	CLR_BIT(INTCON, T0IF_BIT);

	if (TIMER0_Callback != NULL_PTR)
	{
		TIMER0_Callback();
	}
}
