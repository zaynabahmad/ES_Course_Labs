#ifndef MOTOR_INTERFACE_H
#define MOTOR_INTERFACE_H
#include "../MCAL/PWM/PWM_interface.h"
#include "STD_TYPES.h"

#define MOTOR_PORT PWM_PORT
#define MOTOR_PIN PWM_PIN


//Initalizes pin for motor control 
void MOTOR_Init();




#endif