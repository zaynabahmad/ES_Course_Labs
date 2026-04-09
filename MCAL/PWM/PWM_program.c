#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"

#include "../../SERVICES/BIT_MATH.h"

void PWM_Init(void)
{
    /* Set RC2 as output */
    CLR_BIT(TRISC, 2);

    /* Set PWM mode (CCP1) */
    SET_BIT(CCP1CON, 2);
    SET_BIT(CCP1CON, 3);

    /* Set frequency */
    PR2 = PWM_PR2_VALUE;

    /* Set initial duty */
    PWM_SetDutyCycle(PWM_INITIAL_DUTY);

    /* Timer2 ON + prescaler = 1 */
    SET_BIT(T2CON, 2);   // TMR2ON
}

void PWM_SetDutyCycle(u16 duty)
{
    /* 10-bit duty cycle */

    CCPR1L = (u8)(duty >> 2);           // upper 8 bits
    CCP1CON &= 0xCF;
    CCP1CON |= ((duty & 0x03) << 4);    // lower 2 bits
}