#include "PWM_interface.h"
#include "PWM_private.h"

void PWM_Init(void)
{
    // RC2 output
    TRISC_REG &= ~(1 << 2);

    // PWM mode
    CCP1CON_REG |= (1 << CCP1M3) | (1 << CCP1M2);

    // Timer2 config
    PR2_REG = 255;          // period
    T2CON_REG = 0x04;       // Timer2 ON, prescaler 1

}

void PWM_SetDuty(unsigned int duty)
{
    CCPR1L_REG = duty >> 2; // high 8 bits
}