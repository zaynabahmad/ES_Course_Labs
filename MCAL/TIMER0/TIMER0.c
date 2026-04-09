#include "TIMER0_Interface.h"

static u8 TIMER0_Preload = 0;
void (*TIMER0_Callback)(void) = 0;

void TIMER0_Init(void)
{
    /* Clock source select */
    #if TIMER0_CLK_SRC == TIMER0_INTERNAL_CLK
        CLR_BIT(OPTION_REG, T0CS_BIT);
    #else
        SET_BIT(OPTION_REG, T0CS_BIT);
        CLR_BIT(OPTION_REG, T0SE_BIT);  /* Rising edge on T0CKI */
    #endif

    /* Prescaler configuration */
    #if TIMER0_PRESCALER == TIMER0_PRESCALER_OFF
        SET_BIT(OPTION_REG, PSA_BIT);   /* Prescaler -> WDT (1:1 for TMR0) */
    #else
        CLR_BIT(OPTION_REG, PSA_BIT);   /* Prescaler -> TMR0 */
        /* Clear PS2:PS0 then set desired ratio */
        OPTION_REG &= 0xF8;
        OPTION_REG |= (TIMER0_PRESCALER & 0x07);
    #endif

    /* Set preload */
    TIMER0_Preload = TIMER0_PRELOAD;
    TMR0 = TIMER0_Preload;

    /* Clear overflow flag */
    CLR_BIT(INTCON, T0IF_BIT);
}

void TIMER0_SetPreload(u8 Value)
{
    TIMER0_Preload = Value;
    TMR0 = Value;
}

u8 TIMER0_GetCount(void)
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
    CLR_BIT(INTCON, T0IF_BIT);
}

void TIMER0_SetCallback(void (*Callback)(void))
{
    if(Callback != 0)
        TIMER0_Callback = Callback;
}

void TIMER0_ISR(void)
{
    CLR_BIT(INTCON, T0IF_BIT);
    TMR0 = TIMER0_Preload;

    if(TIMER0_Callback != 0)
        TIMER0_Callback();
}
