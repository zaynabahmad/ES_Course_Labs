#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H
#include "PWM_private.h"
#include "../GPIO/GPIO_interface.h"
#define CCPxX_bit 5
#define CCPxY_bit 4
#define TMR2ON_BIT 2
#define PRESCALE_BIT0 0
#define PRESCALE_BIT1 1
#define PWM_MODE 0b00001100
#define CCP1_PIN GPIO_PIN2
void PWM_voidInit(void);
void PWM_SetDutyCycle(u16 Copy_u8DutyCycle);
void PWM_setprescaler(u8 Copy_u8Prescaler);
void PWM_setfrequency(u16 Copy_u16Frequency);
void PWM_enable(void);

#endif