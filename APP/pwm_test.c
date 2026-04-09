#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/MOTOR/MOTOR_interface.h"

#define MOTOR_PORT      GPIO_PORTC
#define MOTOR_PIN1      GPIO_PIN0
#define MOTOR_PIN2      GPIO_PIN2
#define MOTOR_PWM_CH    PWM_CHANNEL_1

void PWM_Test(void)
{
    GPIO_Init();
    MOTOR_Init(MOTOR_PORT, MOTOR_PIN1, MOTOR_PIN2, MOTOR_PWM_CH);

    while(1) {
        MOTOR_Stop();
        for(u16 i = 0; i < 20000; i++);

        MOTOR_Forward(25);
        for(u16 i = 0; i < 20000; i++);

        MOTOR_Forward(50);
        for(u16 i = 0; i < 20000; i++);

        MOTOR_Forward(75);
        for(u16 i = 0; i < 20000; i++);

        MOTOR_Forward(100);
        for(u16 i = 0; i < 20000; i++);

        MOTOR_Backward(50);
        for(u16 i = 0; i < 20000; i++);
    }
}
