#ifndef MOTOR_CONFIG_H
#define MOTOR_CONFIG_H

#include "../../MCAL/GPIO/GPIO_interface.h"

/* L293D direction pins — IN1=HIGH / IN2=LOW → forward rotation
   Adjust these to match the actual wiring on your board.         */
#define MOTOR_IN1_PORT   GPIO_PORTC
#define MOTOR_IN1_PIN    GPIO_PIN0

#define MOTOR_IN2_PORT   GPIO_PORTC
#define MOTOR_IN2_PIN    GPIO_PIN1

#endif
