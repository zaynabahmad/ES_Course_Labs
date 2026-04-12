#include "PWM_interface.h"

static void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 200; j++);
}

void test_PWM(void)
{
    unsigned int duty;

    PWM_Init();

    for (duty = 0; duty <= 1023u; duty += 102u)
    {
        PWM_SetDuty(duty);
        delay_ms(200);
    }

    PWM_SetDuty(0);   /* off at end */
}
