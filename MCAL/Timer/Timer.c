#include "TIMER_INTERFACE.h"

static void (*g_timer0Handler)(void) = 0;

void T0_Init(void)
{
    OPTION_REG |= 0x07;
    CLR_BIT(OPTION_REG, 3);
    CLR_BIT(OPTION_REG, 5);
    CLR_BIT(INTCON, 2);
    TMR0 = 0;
}

void T0_EnableInterrupt(void)
{
    SET_BIT(INTCON, 5);
    SET_BIT(INTCON, 7);
}

void T0_DisableInterrupt(void)
{
    CLR_BIT(INTCON, 5);
}

void T0_RegisterCallback(void (*userHandler)(void))
{
    g_timer0Handler = userHandler;
}

void T0_ResetCounter(void)
{
    TMR0 = 0;
}

void T0_WriteCounter(u8 preloadValue)
{
    TMR0 = preloadValue;
}

u8 T0_ReadOverflowFlag(void)
{
    return GET_BIT(INTCON, 2);
}

void T0_SetOverflowFlag(void)
{
    SET_BIT(INTCON, 2);
}

void T0_ClearOverflowFlag(void)
{
    CLR_BIT(INTCON, 2);
}

void interrupt()
{
    if (GET_BIT(INTCON, 2))
    {
        CLR_BIT(INTCON, 2);

        if (g_timer0Handler != 0)
        {
            g_timer0Handler();
        }
    }
}