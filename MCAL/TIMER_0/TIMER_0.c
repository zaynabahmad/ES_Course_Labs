#include "TIMER_0_Interface.h"
#include "TIMER_0_Private.h"
#include "TIMER_0_Config.h"
#include "../../SERVICES/BIT_MATH.h"

static void (*TIMER0_Callback)(void) = NULL_PTR;

void TIMER0_Init(void)
{
#if TIMER0_MODE == TIMER0_TIMER_MODE
    CLR_BIT(OPTION_REG, T0CS);
#elif TIMER0_MODE == TIMER0_COUNTER_MODE
    SET_BIT(OPTION_REG, T0CS);

#if TIMER0_COUNTER_EDGE == 0
    CLR_BIT(OPTION_REG, T0SE);
#else
    SET_BIT(OPTION_REG, T0SE);
#endif
#endif

    /* Assign prescaler */
    CLR_BIT(OPTION_REG, PSA);

    /* Set prescaler value */
    OPTION_REG = (OPTION_REG & 0xF8) | TIMER0_PRESCALER_VAL;

    /* Enable interrupts */
    SET_BIT(INTCON, TMR0IE);
    SET_BIT(INTCON, GIE);
}

void TIMER0_SetPreload(u8 Value)
{
    TMR0 = Value;
}

void TIMER0_SetCallback(void (*Callback)(void))
{
    if (Callback != NULL_PTR)
    {
        TIMER0_Callback = Callback;
    }
}

/* Driver ISR */
void TIMER0_ISR(void)
{
    if (GET_BIT(INTCON, TMR0IF))
    {
        CLR_BIT(INTCON, TMR0IF);

        if (TIMER0_Callback != NULL_PTR)
        {
            TIMER0_Callback();
        }
    }
}