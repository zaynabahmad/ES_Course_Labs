#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Timer 2 Registers for PWM */
#define PR2         (*((volatile uint8*)0x92))
#define T2CON       (*((volatile uint8*)0x12))

/* CCP1 Registers for PWM */
#define CCPR1L      (*((volatile uint8*)0x15))
#define CCP1CON     (*((volatile uint8*)0x17))

#endif /* PWM_PRIVATE_H */