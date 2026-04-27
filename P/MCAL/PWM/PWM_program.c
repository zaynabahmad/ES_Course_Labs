/* ============================================================
 * PWM_program.c  -  PWM (CCP1/Timer2) driver implementation
 * Target : PIC16F877A  |  Compiler : mikroC Pro for PIC
 * ============================================================ */

#include "PWM_interface.h"
#include "PWM_private.h"
#include "../../SERVICES/bit_math.h"

/* ------------------------------------------------------------ */
void PWM_Init(void)
{
    CLR_BIT(TRISC_REG, 2);                     /* RC2/CCP1 = output    */

    SET_BIT(CCP1CON_REG, CCP1M3);              /* PWM mode:            */
    SET_BIT(CCP1CON_REG, CCP1M2);              /* CCP1M = 1100         */

    PR2_REG    = 255;                           /* PWM period           */
    T2CON_REG  = 0x04;                          /* Timer2 ON, prescale 1*/
}

/* ------------------------------------------------------------ */
void PWM_SetDuty(unsigned int duty)
{
    CCPR1L_REG = (unsigned char)(duty >> 2);    /* Upper 8 of 10 bits   */
}
