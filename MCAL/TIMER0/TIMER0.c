#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "../../SERVICES/BIT_MATH.h"

void (*TIMER0_Callback)(void) = NULL_PTR;

void TIMER0_Init(void)
{
    CLR_BIT(OPTION_REG, T0CS);

    CLR_BIT(OPTION_REG, PSA);

    OPTION_REG = (OPTION_REG & 0xF8) | TIMER0_PRESCALER_VALUE;

    TMR0 = TIMER0_PRELOAD;

    CLR_BIT(INTCON, T0IF);

    SET_BIT(INTCON, T0IE);

    SET_BIT(INTCON, GIE);
}

void TIMER0_SetCallback(void (*callback)(void))
{
    TIMER0_Callback = callback;
}
