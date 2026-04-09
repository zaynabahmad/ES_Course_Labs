#ifndef MOTOR_CONFIG_H
#define MOTOR_CONFIG_H

#include "../../MCAL/GPIO/GPIO_interface.h"

/* DC motor direction pins (IN1, IN2) connected to an H-bridge (e.g. L293D)
 * IN1=HIGH, IN2=LOW  → clockwise
 * IN1=LOW,  IN2=HIGH → counter-clockwise
 * IN1=LOW,  IN2=LOW  → brake/stop
 */
#define MOTOR_IN1_PORT   GPIO_PORTC
#define MOTOR_IN1_PIN    GPIO_PIN0

#define MOTOR_IN2_PORT   GPIO_PORTC
#define MOTOR_IN2_PIN    GPIO_PIN1

/* Speed controlled via PWM on CCP1 (RC2) — configured in PWM_config.h */

#endif
