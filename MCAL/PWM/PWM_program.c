#include "PWM_interface.h"

void PWM_Init(unsigned long freq_hz)
{
    TRISC.F2 = 0;      
    PWM1_Init(freq_hz);
}

void PWM_Start(void)
{
    PWM1_Start();
}

void PWM_Stop(void)
{
    PWM1_Stop();
}

void PWM_SetDutyPercent(u8 duty_percent)
{
    u16 duty_raw;

    if (duty_percent > 100)
        duty_percent = 100;

    duty_raw = ((u16)duty_percent * 255UL) / 100UL;
    PWM1_Set_Duty((u8)duty_raw);
}

void PWM_SetDutyRaw(u8 duty_raw)
{
    PWM1_Set_Duty(duty_raw);
}