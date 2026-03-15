#include "PWM.h"

void PWM_Set_Conditions(u16 Copy_u16DutyCycle, u16 Copy_u16Frequency, u8 Copy_u8Prescaler)
{

    PWM_SetDutyCycle(Copy_u16DutyCycle);
    PWM_setfrequency(Copy_u16Frequency);
    PWM_setprescaler(Copy_u8Prescaler);
}
void PWM_Start(void)
{
    PWM_enable();
}