#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"

#include "../../SERVICES/BIT_MATH.h"

static void (*TIMER0_Callback)(void) = 0;

void TIMER0_Init(void)
{
    /* Select internal clock */
    CLR_BIT(OPTION_REG, T0CS);

    /* Assign prescaler to Timer0 */
    CLR_BIT(OPTION_REG, PSA);

    /* Set prescaler value */
    OPTION_REG &= 0xF8;
    OPTION_REG |= TIMER0_PRESCALER;

    /* Enable Timer0 interrupt */
    SET_BIT(INTCON, T0IE);

    /* Enable global interrupt */
    SET_BIT(INTCON, GIE);
}

void TIMER0_Start(void)
{
    CLR_BIT(INTCON, T0IF);
}

void TIMER0_Stop(void)
{
    CLR_BIT(INTCON, T0IE);
}

void TIMER0_SetPreload(u8 value)
{
    TMR0 = value;
}

void TIMER0_SetCallback(void (*ptr)(void))
{
    TIMER0_Callback = ptr;
}
void TIMER0_ISR(void)
{
    if(TIMER0_Callback != 0)
    {
        TIMER0_Callback();
    }

    CLR_BIT(INTCON, T0IF);
}