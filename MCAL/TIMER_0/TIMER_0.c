#include "TIMER_0_Interface.h"

void (*TIMER0_Callback)(void) = 0;

void TIMER0_Init(u8 Prescaler)
{
    CLR_BIT(OPTION_REG, T0CS);
    
    CLR_BIT(OPTION_REG, PSA);
    
    OPTION_REG &= 0xF8;
    OPTION_REG |= (Prescaler & 0x07);
    
    TMR0 = 0;
}

void TIMER0_Start(void)
{
    CLR_BIT(OPTION_REG, T0CS);
}

void TIMER0_Stop(void)
{
    SET_BIT(OPTION_REG, T0CS);
}

void TIMER0_SetValue(u8 Value)
{
    TMR0 = Value;
}

u8 TIMER0_GetValue(void)
{
    return TMR0;
}

void TIMER0_EnableInterrupt(void)
{
    SET_BIT(INTCON, TMR0IE);
    SET_BIT(INTCON, 7);
    CLR_BIT(INTCON, TMR0IF);
}

void TIMER0_DisableInterrupt(void)
{
    CLR_BIT(INTCON, TMR0IE);
    CLR_BIT(INTCON, TMR0IF);
}

void TIMER0_SetCallback(void (*Callback)(void))
{
    if(Callback != 0)
    {
        TIMER0_Callback = Callback;
    }
}

void TIMER0_ISR(void)
{
    CLR_BIT(INTCON, TMR0IF);
    
    if(TIMER0_Callback != 0)
    {
        TIMER0_Callback();
    }
}
