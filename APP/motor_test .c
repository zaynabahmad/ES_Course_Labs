#include "D:/ES-Project-Lab/SERVICES/std_types.h"
#include "D:/ES-Project-Lab/HAL/motor_interface.h"
#include "D:\ES-Project-Lab\MCAL\GPIO\gpio.h"
void app_motor_test(void)
{
    u16 delayValue = 0;

    MOTOR_Init(GPIO_PORTD, GPIO_PIN0, GPIO_PORTD, GPIO_PIN1);

    while(1)
    {
        MOTOR_Forward(GPIO_PORTD, GPIO_PIN0, GPIO_PORTD, GPIO_PIN1);
        for(delayValue = 0; delayValue < 20000; delayValue++) { ; }

        MOTOR_Stop(GPIO_PORTD, GPIO_PIN0, GPIO_PORTD, GPIO_PIN1);
        for(delayValue = 0; delayValue < 10000; delayValue++) { ; }

        MOTOR_Reverse(GPIO_PORTD, GPIO_PIN0, GPIO_PORTD, GPIO_PIN1);
        for(delayValue = 0; delayValue < 20000; delayValue++) { ; }

        MOTOR_Stop(GPIO_PORTD, GPIO_PIN0, GPIO_PORTD, GPIO_PIN1);
        for(delayValue = 0; delayValue < 10000; delayValue++) { ; }
    }
}