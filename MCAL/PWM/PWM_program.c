#include "PWM_interface.h"
#include "PWM_private.h"
#include "Services/bit_math.h"

void PWM_Init(void)
{
    CLR_BIT(TRISC_REG, 2);   /* rc2/ccp1 as output */

    /* pwm mode: CCP1M[3:2] = 11 */
    SET_BIT(CCP1CON_REG, CCP1M3_BIT);
    SET_BIT(CCP1CON_REG, CCP1M2_BIT);

    PR2_REG    = 0xFF;        /* period register */
    T2CON_REG  = 0x04;        /* timer2 on, prescaler 1:1 */
}

void PWM_SetDuty(unsigned int duty)
{
    /* duty is 10-bit: bits[9:2] -> CCPR1L, bits[1:0] -> CCP1CON[5:4] */
    CCPR1L_REG  = (unsigned char)(duty >> 2);
    CCP1CON_REG = (CCP1CON_REG & 0xCFu) | (unsigned char)((duty & 0x03u) << DC1B_SHIFT);
}