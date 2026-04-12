#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"
#include "../../SERVICES/BIT_MATH.h"

static u8 PWM_DutyCycle[2] = {PWM_CHANNEL1_INIT_DUTY, PWM_CHANNEL2_INIT_DUTY};

void PWM_Init(void)
{
    u8 Prescaler_Bits;

    PR2 = 99;
    Prescaler_Bits = (PWM_PRESCALER == 1) ? 0x00 : (PWM_PRESCALER == 4) ? 0x01 : 0x02;
    T2CON = Prescaler_Bits | 0x04;
    CCPCON = 0x0C;

    PWM_SetDutyCycle(PWM_CHANNEL1, PWM_CHANNEL1_INIT_DUTY);
    PWM_SetDutyCycle(PWM_CHANNEL2, PWM_CHANNEL2_INIT_DUTY);
}

void PWM_SetDutyCycle(u8 Channel, u8 DutyCycle)
{
    u16 PWM_Value;

    if (DutyCycle > PWM_DUTY_MAX)
        DutyCycle = PWM_DUTY_MAX;

    if (Channel < 2)
        PWM_DutyCycle[Channel] = DutyCycle;

    PWM_Value = ((u16)DutyCycle * (4 * (PR2 + 1))) / 100;

    if (Channel == PWM_CHANNEL1)
    {
        CCPR1L = (u8)(PWM_Value >> 2);
        CCPR1H = (u8)(PWM_Value & 0x03);
    }
    else if (Channel == PWM_CHANNEL2)
    {
        CCPR2L = (u8)(PWM_Value >> 2);
    }
}

u8 PWM_GetDutyCycle(u8 Channel)
{
    if (Channel < 2)
        return PWM_DutyCycle[Channel];
    return 0;
}

void PWM_Start(u8 Channel)
{
    if (Channel == PWM_CHANNEL1)
        SET_BIT(CCPCON, 2);
}

void PWM_Stop(u8 Channel)
{
    if (Channel == PWM_CHANNEL1)
        CLR_BIT(CCPCON, 2);
}

void PWM_SetFrequency(u16 FrequencyHz)
{
    u32 PR2_Calc = (20000000UL / (FrequencyHz * 4 * PWM_PRESCALER)) - 1;

    if (PR2_Calc > 255)
        PR2_Calc = 255;

    PR2 = (u8)PR2_Calc;
}
