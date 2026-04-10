#include "TIMER_0_Interface.h"
#include "TIMER_0_Private.h"
#include "../../SERVICES/BIT_MATH.h"

static void (*TIMER0_Callback)(void) = NULL_PTR;

void TIMER0_Init(void)
{
    /* Select Internal Instruction Cycle Clock */
    CLR_BIT(OPTION_REG, T0CS);

    /* Assign Prescaler to Timer0 */
    CLR_BIT(OPTION_REG, PSA);

    /* Set Prescaler to 1:256 (Bits 0,1,2 = 111) */
    OPTION_REG |= 0x07;
}

void TIMER0_SetPreload(u8 Value)
{
    TMR0 = Value;
}

void TIMER0_EnableInterrupt(void)
{
    SET_BIT(INTCON, T0IE);
    SET_BIT(INTCON, GIE);
}

void TIMER0_SetCallback(void (*ptr)(void))
{
    if(ptr != NULL_PTR)
    {
        TIMER0_Callback = ptr;
    }
}
