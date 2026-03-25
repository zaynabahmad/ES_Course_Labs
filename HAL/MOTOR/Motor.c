#include "../../MCAL/MCAL_PWM/MCAL_PWM_INTERFACE.h"
#include "../../HAL/MOTOR/MOTOR_INTERFACE.h"
#include "../../MCAL/GPIO/GPIO_interface.h"


void Motor_Init(void ){
      PWM_Init();
      GPIO_SetPinDirection(GPIO_PORTB , GPIO_PIN1, GPIO_OUTPUT);
      GPIO_SetPinDirection(GPIO_PORTB , GPIO_PIN2 , GPIO_OUTPUT);
}
void ForwardMotor(unsigned char speed ){
     GPIO_SetPinValue(GPIO_PORTB , GPIO_PIN2 , GPIO_HIGH);
     GPIO_SetPinValue(GPIO_PORTB , GPIO_PIN1 , GPIO_LOW);
     PWM_SetDutyCycle(speed);
}
void BackwardMotor(unsigned char speed) {
     GPIO_SetPinDirection(GPIO_PORTB , GPIO_PIN2 , GPIO_LOW);
     GPIO_SetPinValue(GPIO_PORTB , GPIO_PIN1 , GPIO_HIGH);
     PWM_SetDutyCycle(speed);
}
void StopMotor(void){
     GPIO_SetPinDirection(GPIO_PORTB , GPIO_PIN2 , GPIO_HIGH);
     GPIO_SetPinValue(GPIO_PORTB , GPIO_PIN1 , GPIO_HIGH);
}

