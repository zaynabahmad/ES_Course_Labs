#include "timer0.h"
#include "bit_math.h"

void TIMER0_Init(void)
{
    CLR_BIT(OPTION_REG, 5);         /* T0CS = 0 ? internal clock         */
    CLR_BIT(OPTION_REG, 3);         /* PSA  = 0 ? prescaler to Timer0    */

    /* Set prescaler bits PS2:PS0 */
    if(TIMER0_PRESCALER & 0x04) SET_BIT(OPTION_REG, 2); else CLR_BIT(OPTION_REG, 2);
    if(TIMER0_PRESCALER & 0x02) SET_BIT(OPTION_REG, 1); else CLR_BIT(OPTION_REG, 1);
    if(TIMER0_PRESCALER & 0x01) SET_BIT(OPTION_REG, 0); else CLR_BIT(OPTION_REG, 0);

    TIMER0_Preload(TIMER0_PRELOAD);  /* Load starting value               */
    TIMER0_ClearFlag();              /* Clear any pending flag            */
    TIMER0_Start();                  /* Enable Timer0 interrupt           */
}

void TIMER0_Start(void)
{
    SET_BIT(INTCON, 5);              /* T0IE = 1 */
    SET_BIT(INTCON, 7);              /* GIE  = 1 */
}

void TIMER0_Stop(void)
{
    CLR_BIT(INTCON, 5);              /* T0IE = 0 */
}

void TIMER0_ClearFlag(void)
{
    CLR_BIT(INTCON, 2);              /* T0IF = 0 */
}

void TIMER0_Preload(uint8 value)
{
    TMR0 = value;                    /* Set counter start value */
}

uint8 TIMER0_GetFlag(void)
{
    return GET_BIT(INTCON, 2);
}

void TIMER0_Reload(uint8 value)
{
    TMR0 = value;
}