#include "../MCAL/PWM/PWM_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void PWM_Test(void)
{
    unsigned long i;

    /* CCP1 ? RC2 */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN2, GPIO_OUTPUT);

    PWM_Init();

    PWM_Start(PWM_CHANNEL_1);

    while(1)
    {
        /* 25% */
        PWM_SetDutyCycle(PWM_CHANNEL_1, 25);
        for(i = 0; i < 50000; i++);

        /* 50% */
        PWM_SetDutyCycle(PWM_CHANNEL_1, 50);
        for(i = 0; i < 50000; i++);

        /* 75% */
        PWM_SetDutyCycle(PWM_CHANNEL_1, 75);
        for(i = 0; i < 50000; i++);
    }
}