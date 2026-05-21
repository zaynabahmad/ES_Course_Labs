#include "PWM_Interface.h"

void PWM_Init(void)
{
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN2, GPIO_OUTPUT);

    PR2 = PWM_PR2_VALUE;

    CCPR1L = 0;
    CLR_BIT(CCP1CON, DC1B0_BIT);
    CLR_BIT(CCP1CON, DC1B1_BIT);

    CCP1CON = (CCP1CON & 0xF0) | CCP1_PWM_MODE;

    T2CON = (T2CON & 0xF8) | (PWM_T2_PRESCALER & 0x03);
    CLR_BIT(T2CON, TMR2ON_BIT);
}

void PWM_SetDutyCycle(u8 duty)
{
    u16 duty_count;

    if(duty > 100) { duty = 100; }

    duty_count = (u16)(((u16)(PR2 + 1U) * 4U * (u16)duty) / 100U);

    CCPR1L = (u8)(duty_count >> 2);

    if(GET_BIT(duty_count, 0)) { SET_BIT(CCP1CON, DC1B0_BIT); }
    else                        { CLR_BIT(CCP1CON, DC1B0_BIT); }

    if(GET_BIT(duty_count, 1)) { SET_BIT(CCP1CON, DC1B1_BIT); }
    else                        { CLR_BIT(CCP1CON, DC1B1_BIT); }
}

void PWM_Start(void)
{
    SET_BIT(T2CON, TMR2ON_BIT);
}

void PWM_Stop(void)
{
    CLR_BIT(T2CON, TMR2ON_BIT);
}
