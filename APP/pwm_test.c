/*
 * pwm_test.c
 * Tests the PWM MCAL driver: init, start, and duty-cycle sweep from 0 to 100%.
 * Output on RC2 (CCP1 pin).
 * No direct register access — uses only PWM_Interface.h API.
 */

#include "../MCAL/PWM/PWM_Interface.h"
#include "pwm_test.h"

static void delay(void)
{
    unsigned int i;
    for(i = 0; i < 30000U; i++) { ; }
}

void PWM_Test(void)
{
    u8 duty;

    /* Initialise PWM at 8 kHz (from PWM_Config.h), duty 0%, Timer2 off */
    PWM_Init();

    /* Start Timer2 — PWM signal begins on RC2 */
    PWM_Start();

    /* Ramp duty cycle from 0% to 100% */
    for(duty = 0; duty <= 100U; duty += 10U)
    {
        PWM_SetDutyCycle(duty);
        delay();
    }

    /* Hold at 50% steady-state */
    PWM_SetDutyCycle(50);
    delay();
    delay();

    /* Fade out to 0% */
    for(duty = 100U; duty >= 10U; duty -= 10U)
    {
        PWM_SetDutyCycle(duty);
        delay();
    }
    PWM_SetDutyCycle(0);

    /* Stop PWM output */
    PWM_Stop();
}