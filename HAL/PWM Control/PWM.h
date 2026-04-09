#ifndef PWM_WRAPPER_H_
#define PWM_WRAPPER_H_

#include "../../MCAL/PWM/PWM_interface.h"
#include "../../SERVICES/STD_TYPES.h"
void PWM_Set_Conditions(u16 Copy_u16DutyCycle, u16 Copy_u16Frequency, u8 Copy_u8Prescaler);
void PWM_Start(void);

#endif