/*
 * pwm_test.c
 * APP Layer - PWM Driver Test
 *
 * Test Description:
 *   - CCP1 on RC2: Fade LED from 0% to 100% and back
 *   - CCP2 on RC1: Fixed 50% duty cycle (motor/buzzer)
 *   - Uses 2kHz PWM frequency (Fosc=4MHz, Pre=4, PR2=124)
 */

#include "pwm_test.h"
#include "../MCAL/PWM/pwm.h"
#include "../MCAL/TIMER0/timer0.h"

void PWM_Test_Init(void)
{
    /*
     * Fpwm = Fosc / (4 * Prescaler * (PR2+1))
     *      = 4MHz  / (4 * 4 * 125)
     *      = 2000 Hz = 2kHz
     */
    PWM_Init(PWM_CHANNEL_1, PWM_PRESCALER_4, 124);
    PWM_Init(PWM_CHANNEL_2, PWM_PRESCALER_4, 124);

    /* Start at 0% */
    PWM_SetDutyPercent(PWM_CHANNEL_1, 0);
    PWM_SetDutyPercent(PWM_CHANNEL_2, 50);  /* CCP2 fixed at 50% */
}

void PWM_Test_FadeUp(void)
{
    u8 duty;
    for(duty = 0; duty <= 100; duty++)
    {
        PWM_SetDutyPercent(PWM_CHANNEL_1, duty);
        TIMER0_DelayMs(20);
    }
}

void PWM_Test_FadeDown(void)
{
    u8 duty;
    for(duty = 100; duty > 0; duty--)
    {
        PWM_SetDutyPercent(PWM_CHANNEL_1, duty);
        TIMER0_DelayMs(20);
    }
    PWM_SetDutyPercent(PWM_CHANNEL_1, 0);
}

void PWM_Test_Run(void)
{
    PWM_Test_Init();

    while(1)
    {
        PWM_Test_FadeUp();
        TIMER0_DelayMs(200);
        PWM_Test_FadeDown();
        TIMER0_DelayMs(200);
    }
}
