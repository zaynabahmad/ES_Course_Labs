#include "../../MCAL/PWM/PWM_Interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void main(void)
{
    u8 duty = 0;

    /* RC2 = CCP1 output */
    GPIO_Init(PORTC , PIN2 , OUTPUT);

    PWM_Init();

    while(1)
    {
        /* Increase brightness تدريجي */
        for(duty = 0; duty <= 100; duty++)
        {
            PWM_SetDuty(duty);

            for(u16 i = 0; i < 5000; i++); // delay
        }

        /* Decrease brightness */
        for(duty = 100; duty > 0; duty--)
        {
            PWM_SetDuty(duty);

            for(u16 i = 0; i < 5000; i++); // delay
        }
    }
}