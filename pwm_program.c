#include "pwm_interface.h"
#include "pwm_private.h"
#include "pwm_config.h"
#include "../../SERVICES/bit_ops.h"

void PWM_Setup(void)
{
    /* RC2 as output for CCP1 */
    BIT_CLEAR(TRISC_REG, 2);

    PR2_REG = PWM_PERIOD_REG_VAL;

    /* Set PWM mode (bits 3-0 = 1100) */
    CCP1CON_REG = 0x0C;

    /* Timer2 on, prescaler */
    T2CON_REG = 0x06;
}

void PWM_UpdateDuty(u16 duty_cycle)
{
    CCPR1L_REG = duty_cycle >> 2;

    CCP1CON_REG &= 0xCF;
    CCP1CON_REG |= (duty_cycle & 0x03) << 4;
}