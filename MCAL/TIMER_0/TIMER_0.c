#include "TIMER_0_Private.h"
#include "TIMER_0_Config.h"
#include "TIMER_0_Interface.h"
#include "../../SERVICES/BIT_MATH.h"

static void (*TIMER0_Callback)(void) = 0;
static u8 TIMER0_Preload = TIMER0_DEFAULT_PRELOAD;

void TIMER0_Init(void)
{
    /* Internal clock source (Fosc/4) */
    CLR_BIT(OPTION_REG, T0CS_BIT);

    /* Assign prescaler to TMR0 */
    CLR_BIT(OPTION_REG, PSA_BIT);

    /* Set prescaler bits */
    if (TIMER0_PS_BITS & (1U << 0)) SET_BIT(OPTION_REG, PS0_BIT); else CLR_BIT(OPTION_REG, PS0_BIT);
    if (TIMER0_PS_BITS & (1U << 1)) SET_BIT(OPTION_REG, PS1_BIT); else CLR_BIT(OPTION_REG, PS1_BIT);
    if (TIMER0_PS_BITS & (1U << 2)) SET_BIT(OPTION_REG, PS2_BIT); else CLR_BIT(OPTION_REG, PS2_BIT);

    /* Load preload value */
    TMR0 = TIMER0_Preload;

    /* Clear overflow flag */
    CLR_BIT(INTCON, TMR0IF_BIT);
}

void TIMER0_Start(void)
{
    TMR0 = TIMER0_Preload;
    CLR_BIT(INTCON, TMR0IF_BIT);
    SET_BIT(INTCON, TMR0IE_BIT);
    SET_BIT(INTCON, GIE_BIT);
}

void TIMER0_Stop(void)
{
    CLR_BIT(INTCON, TMR0IE_BIT);
    CLR_BIT(INTCON, TMR0IF_BIT);
}

void TIMER0_SetPreload(u8 Preload)
{
    TIMER0_Preload = Preload;
}

void TIMER0_SetCallback(void (*Callback)(void))
{
    if (Callback != 0)
        TIMER0_Callback = Callback;
}

void TIMER0_ISR(void)
{
    if (GET_BIT(INTCON, TMR0IF_BIT))
    {
        CLR_BIT(INTCON, TMR0IF_BIT);
        TMR0 = TIMER0_Preload;
        if (TIMER0_Callback != 0)
            TIMER0_Callback();
    }
}
