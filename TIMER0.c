#include "TIMER0_INTERFACE.h"
#include "TIMER0_PRIVATE.h"
#include "TIMER0_CONFIG.h"
#include "../SERVICES/BIT_MATH.h"

static void (*TIMER0_Callback)(void) = NULL_PTR;

void TIMER0_Init(void)
{
#if TIMER0_CLK_SOURCE == TIMER0_CLK_INTERNAL
    CLR_BIT(OPTION_REG, T0CS);
#else
    SET_BIT(OPTION_REG, T0CS);
#endif

#if TIMER0_PRESCALER == TIMER0_PRESCALER_ON
    CLR_BIT(OPTION_REG, PSA);
    OPTION_REG = (OPTION_REG & 0xF8) | (TIMER0_PRESCALER_VAL & 0x07);
#else
    SET_BIT(OPTION_REG, PSA);
#endif

    TMR0 = 0;
    CLR_BIT(INTCON, T0IF);
}

void TIMER0_SetPreload(u8 preload)
{
    TMR0 = preload;
}

u8 TIMER0_GetValue(void)
{
    return TMR0;
}

void TIMER0_EnableInterrupt(void)
{
    SET_BIT(INTCON, T0IE);
    SET_BIT(INTCON, GIE);
}

void TIMER0_DisableInterrupt(void)
{
    CLR_BIT(INTCON, T0IE);
}

void TIMER0_ClearFlag(void)
{
    CLR_BIT(INTCON, T0IF);
}

u8 TIMER0_GetFlag(void)
{
    return GET_BIT(INTCON, T0IF);
}

void TIMER0_SetCallback(void (*ptr)(void))
{
    TIMER0_Callback = ptr;
}

void TIMER0_HandleISR(void)
{
    if(GET_BIT(INTCON, T0IF) == 1)
    {
        if(TIMER0_Callback != NULL_PTR)
        {
            TIMER0_Callback();
        }
        CLR_BIT(INTCON, T0IF);
    }
}
