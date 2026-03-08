#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"

#define PWM_PORT GPIO_PORTC
#define PWM_PIN GPIO_PIN2



//Initalizes pin for motor control 
void PWM_inti();
//Set Duty Cycle of PWM
void PWM_setDutyCycle(u8);
//Sets frequency of PWM
void PWM_setFrequency(u32);




#endif