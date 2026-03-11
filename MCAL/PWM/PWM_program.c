#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"

#include "../../SERVICES/BIT_MATH.h"

void PWM_Init(void)
{
    /* RC2 as output (CCP1) */
    CLR_BIT(TRISC, 2);

    /* Set PWM period */
    PR2 = PWM_PR2_VALUE;

    /* Set PWM mode */
    CCP1CON = 0x0C;

    /* Start Timer2 with prescaler */
    T2CON = 0x06;
}

void PWM_SetDuty(u16 duty)
{
    CCPR1L = duty >> 2;

    CCP1CON &= 0xCF;
    CCP1CON |= (duty & 0x03) << 4;
}