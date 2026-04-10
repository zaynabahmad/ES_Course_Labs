#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/PWM/PWM_interface.h"

void PWM_Test(void)
{
    u8 DutyCycle;
    u16 i;

    PWM_Init();
    PWM_Start(PWM_CHANNEL1);

    // Ramp up: 0% to 100%
    for (DutyCycle = 0; DutyCycle <= 100; DutyCycle += 20)
    {
        PWM_SetDutyCycle(PWM_CHANNEL1, DutyCycle);

        for (i = 0; i < 10000; i++);  // Delay for observation
    }

    // Ramp down: 100% to 0%
    for (DutyCycle = 100; DutyCycle > 0; DutyCycle -= 20)
    {
        PWM_SetDutyCycle(PWM_CHANNEL1, DutyCycle);

        for (i = 0; i < 10000; i++);
    }

    // Set to 50%
    PWM_SetDutyCycle(PWM_CHANNEL1, 50);
    for (i = 0; i < 20000; i++);

    PWM_Stop(PWM_CHANNEL1);
}
