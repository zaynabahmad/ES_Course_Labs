/* ============================================================
 * EXTI_program.c  -  External Interrupt driver implementation
 * Target : PIC16F877A  |  Compiler : mikroC Pro for PIC
 * ============================================================ */

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "../../SERVICES/bit_math.h"

/* ------------------------------------------------------------ */
void EXTI_Init(unsigned char edge)
{
    if (edge == RISING_EDGE)
        SET_BIT(OPTION_REG, INTEDG);
    else
        CLR_BIT(OPTION_REG, INTEDG);
}

/* ------------------------------------------------------------ */
void EXTI_Enable(void)
{
    SET_BIT(INTCON_REG, INTE);  /* Enable INT0              */
    SET_BIT(INTCON_REG, GIE);   /* Enable global interrupts */
}

/* ------------------------------------------------------------ */
void EXTI_Disable(void)
{
    CLR_BIT(INTCON_REG, INTE);  /* Disable INT0 */
}
