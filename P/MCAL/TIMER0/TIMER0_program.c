/* ============================================================
 * TIMER0_program.c  -  Timer0 driver implementation
 * Target : PIC16F877A  |  Compiler : mikroC Pro for PIC
 * ============================================================ */

#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "../../SERVICES/bit_math.h"

/* ------------------------------------------------------------ */
void TIMER0_Init(void)
{
    CLR_BIT(OPTION_REG, T0CS);              /* Internal clock (Fosc/4) */
    CLR_BIT(OPTION_REG, PSA);               /* Prescaler -> Timer0     */

    /* Prescaler 1:256  (PS2:PS1:PS0 = 111) */
    SET_BIT(OPTION_REG, PS2);
    SET_BIT(OPTION_REG, PS1);
    SET_BIT(OPTION_REG, PS0);

    SET_BIT(INTCON_REG, TMR0IE);            /* Enable Timer0 interrupt */
    SET_BIT(INTCON_REG, GIE);               /* Enable global interrupts */
}

/* ------------------------------------------------------------ */
void TIMER0_Start(void)
{
    TMR0_REG = 0;   /* Clear counter to start counting */
}

/* ------------------------------------------------------------ */
void TIMER0_Stop(void)
{
    /* Timer0 has no dedicated stop bit on PIC16.
     * To halt counting, disable the interrupt or use sleep mode. */
}
