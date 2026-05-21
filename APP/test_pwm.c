/**
 * @file    test_pwm.c
 * @brief   PWM exercise -- application layer, no register access.
 *
 * @details The application only ever speaks in "percent duty" and "hertz".
 *          All the PR2 / CCPR1L arithmetic is the driver's concern, which is
 *          why this file can ramp brightness without a single SFR reference.
 */
#include "test_pwm.h"
#include "../MCAL/PWM_interface.h"

/** Carrier frequency for the demo, in hertz. */
#define TEST_PWM_FREQ_HZ        2000uL

/** Pause between duty steps, in milliseconds. */
#define TEST_PWM_STEP_MS        20u

/** Duty increment per step, in percent. */
#define TEST_PWM_STEP_PCT       5u

void vTest_Pwm(void)
{
    byte_t u8Duty;

    vPWM_Init();
    vPWM_SetFreq(TEST_PWM_FREQ_HZ);
    vPWM_Start();

    while (1)
    {
        /* Ramp up: 0 % -> 100 %. */
        for (u8Duty = 0u; u8Duty <= 100u; u8Duty += TEST_PWM_STEP_PCT)
        {
            vPWM_SetDuty(u8Duty);
            Delay_ms(TEST_PWM_STEP_MS);
        }

        /* Ramp down: 100 % -> 0 %. Loop on a guard value because an unsigned
         * counter cannot go below zero to terminate the loop. */
        for (u8Duty = 100u; u8Duty > 0u; u8Duty -= TEST_PWM_STEP_PCT)
        {
            vPWM_SetDuty(u8Duty);
            Delay_ms(TEST_PWM_STEP_MS);
        }
    }
}
