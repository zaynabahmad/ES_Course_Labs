#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

void (*TIMER0_Callback)(void) = NULL_PTR;

void TIMER0_Init(u8 Mode, u8 PrescalerEnable, u8 PrescalerValue)
{
    CLR_BIT(OPTION_REG, T0CS); // internal clock

    if(PrescalerEnable) CLR_BIT(OPTION_REG, PSA);
    else SET_BIT(OPTION_REG, PSA);

    OPTION_REG &= 0xF8;
    OPTION_REG |= (PrescalerValue & 0x07);

    TMR0 = 0;
    T0IE_bit = 0; // disable interrupt
}

void TIMER0_Start(void)
{
    T0IE_bit = 1; // enable interrupt
}

void TIMER0_Stop(void)
{
    T0IE_bit = 0; // disable interrupt
}

void TIMER0_SetValue(u8 Value)
{
    TMR0 = Value;
}

u8 TIMER0_GetValue(void)
{
    return TMR0;
}

void TIMER0_SetCallback(void (*Callback)(void))
{
    TIMER0_Callback = Callback;
}

