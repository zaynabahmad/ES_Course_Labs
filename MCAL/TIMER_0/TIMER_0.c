#include "TIMER_0_Interface.h"
#include "TIMER_0_Private.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

void (*TMR0_Callback)(void) = NULL_PTR;

void TMR0_Init(void)
{
    CLR_BIT(OPTION_REG, OPTION_T0CS);   /* Internal clock */
    CLR_BIT(OPTION_REG, OPTION_PSA);    /* Prescaler to TMR0 */

    /* Prescaler 1:256 → PS2:PS1:PS0 = 1:1:1 */
    SET_BIT(OPTION_REG, OPTION_PS2);
    SET_BIT(OPTION_REG, OPTION_PS1);
    SET_BIT(OPTION_REG, OPTION_PS0);

    TMR0 = TMR0_PRELOAD;
    CLR_BIT(INTCON, INTCON_T0IF);
}

void TMR0_Enable(void)
{
    SET_BIT(INTCON, INTCON_T0IE);
    SET_BIT(INTCON, INTCON_GIE);
}

void TMR0_Disable(void)
{
    CLR_BIT(INTCON, INTCON_T0IE);
}

void TMR0_SetCallback(void (*ptr)(void))
{
    TMR0_Callback = ptr;
}

// void interrupt()
// {
//     if (GET_BIT(INTCON, INTCON_T0IF) == 1)
//     {
//         /* Reload immediately for accuracy */
//         TMR0 = TMR0_PRELOAD;

//         /* Clear flag */
//         CLR_BIT(INTCON, INTCON_T0IF);

//         if (TMR0_Callback != NULL_PTR)
//         {
//             TMR0_Callback();
//         }
//     }
// }