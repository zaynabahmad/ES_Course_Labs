// Purpose: Lists PWM (brightness/speed control) functions

#ifndef PWM_H
#define PWM_H

#include "std_types.h"
#include "pic_config.h"

void PWM_Init(void);                  // Setup PWM
void PWM_SetDutyCycle(uint8 duty);    // 0=off, 255=full on, 128=half
void PWM_Start(void);                 // Begin PWM output
void PWM_Stop(void);                  // Stop PWM output

#endif