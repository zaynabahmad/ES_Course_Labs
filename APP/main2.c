#include "../HAL/DCMOTOR/DCMOTOR_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "../SERVICES/STD_TYPES.h"

#define MOTOR_PORT   GPIO_PORTB
#define MOTOR_IN1    GPIO_PIN4
#define MOTOR_IN2    GPIO_PIN5

volatile u8 button_event = 0;
volatile u8 duty_index = 0;

const u8 duty_table[4] = {25, 50, 75, 100};

void APP_ButtonCallback(void)
{
    button_event = 1;
}

void main(void)
{
    DCMOTOR_Init(MOTOR_PORT, MOTOR_IN1, MOTOR_IN2);
    DCMOTOR_Forward(MOTOR_PORT, MOTOR_IN1, MOTOR_IN2);

    PWM_Init(5000);                         
    PWM_Start();
    PWM_SetDutyPercent(duty_table[duty_index]);

    EXT_INT0_Init();
    EXT_INT0_SetCallback(APP_ButtonCallback);

    while(1)
    {
        if (button_event)
        {
            Delay_ms(50);   
            if (GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN0) == GPIO_LOW)
            {
                duty_index++;
                if (duty_index >= 4)
                    duty_index = 0;

                PWM_SetDutyPercent(duty_table[duty_index]);

                while (GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN0) == GPIO_LOW);
            }

            button_event = 0;
        }
    }
}