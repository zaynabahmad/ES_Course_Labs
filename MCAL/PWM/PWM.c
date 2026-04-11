#include "PWM_Interface.h"
#include "PWM_Private.h"
#include "PWM_Config.h"
#include "../../SERVICES/BIT_MATH.h"

/* Registers */
#define CCP1CON   *((volatile u8*)0x17)
#define CCPR1L    *((volatile u8*)0x15)

#define T2CON     *((volatile u8*)0x12)
#define PR2       *((volatile u8*)0x92)

/* ============================= */

void PWM_Init(void)
{
    /* Set PWM mode (CCP1) */
    SET_BIT(CCP1CON , CCP1M2);
    SET_BIT(CCP1CON , CCP1M3);

    /* Timer2 configuration */
    PR2 = PWM_PR2_VALUE;

    /* Prescaler = 16 */
    SET_BIT(T2CON , 1);
    SET_BIT(T2CON , 0);

    /* Enable Timer2 */
    SET_BIT(T2CON , 2);
}

/* ============================= */

void PWM_SetDuty(u8 duty)
{
    u16 duty_val;

    if(duty > 100) duty = 100;

    /* Convert % to 10-bit value */
    duty_val = ((u32)duty * (PWM_PR2_VALUE + 1) * 4) / 100;

    /* Load duty */
    CCPR1L = duty_val >> 2;

    CCP1CON &= 0xCF; // Clear DC1B bits
    CCP1CON |= (duty_val & 0x03) << 4;
}