#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "Services/bit_math.h"

void TIMER0_Init(void)
{
    CLR_BIT(OPTION_REG, T0CS_BIT);   /* internal clock source */
    CLR_BIT(OPTION_REG, PSA_BIT);    /* prescaler assigned to timer0 */

    /* prescaler 1:256 */
    SET_BIT(OPTION_REG, PS0_BIT);
    SET_BIT(OPTION_REG, PS1_BIT);
    SET_BIT(OPTION_REG, PS2_BIT);

    SET_BIT(INTCON_REG, TMR0IE_BIT);
    SET_BIT(INTCON_REG, GIE_BIT);
}

void TIMER0_Start(void)
{
    TMR0_REG = 0;
    SET_BIT(INTCON_REG, TMR0IE_BIT);
}

void TIMER0_Stop(void)
{
    /* switch to external clock source to halt counting */
    SET_BIT(OPTION_REG, T0CS_BIT);
    CLR_BIT(INTCON_REG, TMR0IE_BIT);
}