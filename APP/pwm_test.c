#include "D:/ES-Project-Lab/SERVICES/std_types.h"
#include "D:/ES-Project-Lab/MCAL/PWM/pwm_interface.h"

void app_pwm_test(void)
{
    u8 duty = 0;
    u16 delayValue = 0;

    PWM_Init();

    while(1)
    {
        for(duty = 0; duty <= 100; duty += 10)
        {
            PWM_SetDutyPercent(duty);

            for(delayValue = 0; delayValue < 10000; delayValue++)
            {
                ;
            }
        }

        for(duty = 100; duty >= 10; duty -= 10)
        {
            PWM_SetDutyPercent(duty);

            for(delayValue = 0; delayValue < 10000; delayValue++)
            {
                ;
            }
        }
    }
}