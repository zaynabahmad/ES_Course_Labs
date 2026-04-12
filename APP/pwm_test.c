#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/PWM/PWM_Interface.h"
#include "../MCAL/TIMER_0/TIMER_0_Interface.h"

void PWM_Test(void)
{
    /* Initialize PWM on Channel 1 (RC2) */
    PWM_Init(PWM_CHANNEL_1);

    /* Set 50% duty cycle */
    PWM_SetDutyCycle(PWM_CHANNEL_1, 50);

    /* Start PWM output */
    PWM_Start(PWM_CHANNEL_1);

    /* Vary duty cycle: 25% -> 75% -> 0% -> 100% */
    TIMER0_Init();
    TIMER0_DelayMs(500);
    PWM_SetDutyCycle(PWM_CHANNEL_1, 25);

    TIMER0_DelayMs(500);
    PWM_SetDutyCycle(PWM_CHANNEL_1, 75);

    TIMER0_DelayMs(500);
    PWM_SetDutyCycle(PWM_CHANNEL_1, 0);

    TIMER0_DelayMs(500);
    PWM_SetDutyCycle(PWM_CHANNEL_1, 100);
}
