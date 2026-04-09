#include "../MCAL/PWM/PWM_interface.h"
#include "pwm_test.h"

void pwm_test_run(void)
{
    PWM_Init();

    /* 25% duty cycle */
    PWM_SetDutyCycle(250);

    /* Counted delay ~100 ms (at 4 MHz, 1 iteration ≈ 4 cycles → 100000 iters) */
    {
        volatile u32 i;
        for (i = 0; i < 100000UL; i++) {}
    }

    /* 50% duty cycle */
    PWM_SetDutyCycle(500);

    {
        volatile u32 i;
        for (i = 0; i < 100000UL; i++) {}
    }

    /* 75% duty cycle */
    PWM_SetDutyCycle(750);

    {
        volatile u32 i;
        for (i = 0; i < 100000UL; i++) {}
    }

    /* Stop PWM */
    PWM_Stop();
}
