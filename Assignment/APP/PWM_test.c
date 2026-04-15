#include "../MCAL/PWM/PWM_interface.h"

void PWM_Test(void)
{
    PWM_voidInit();

    while(1)
    {
        PWM_voidSetDutyCycle(25);
        Delay_ms(1000);

        PWM_voidSetDutyCycle(75);
        Delay_ms(1000);
    }
}