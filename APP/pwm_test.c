#include "pwm_test.h"
#include "../MCAL/PWM/PWM_interface.h"

void APP_PWM_Test(void)
{
    /* Variables declared at top for C89 compatibility */
    u8 duty = 0;
    u8 dir = 1;
    volatile u16 d;

    PWM_Init();

    /* Sweep duty 0→100→0 in Proteus oscilloscope / LED brightness */
    while (1)
    {
        PWM_SetDuty(duty);

        for (d = 0; d < 60000; d++)
            ; /* rough delay */

        if (dir)
        {
            duty++;
            if (duty >= 100)
                dir = 0;
        }
        else
        {
            duty--;
            if (duty == 0)
                dir = 1;
        }
    }
}