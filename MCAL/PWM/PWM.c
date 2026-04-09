#include "PWM_Interface.h"

void PWM_Init(u8 Channel)
{
    PR2 = 249;
    
    T2CON = 0x05;
    
    if(Channel == PWM_CHANNEL_1)
    {
        CCP1CON = 0x0C;
    }
    else if(Channel == PWM_CHANNEL_2)
    {
        CCP2CON = 0x0C;
    }
}

void PWM_SetDutyCycle(u8 Channel, u8 DutyCycle)
{
    u16 duty = (u16)((DutyCycle * 1000UL) / 100);
    
    if(Channel == PWM_CHANNEL_1)
    {
        CCPR1L = (u8)(duty >> 2);
        CCP1CON &= 0xCF;
        CCP1CON |= ((duty & 0x03) << 4);
    }
    else if(Channel == PWM_CHANNEL_2)
    {
        CCPR2L = (u8)(duty >> 2);
        CCP2CON &= 0xCF;
        CCP2CON |= ((duty & 0x03) << 4);
    }
}

void PWM_Start(u8 Channel)
{
    SET_BIT(T2CON, TMR2ON);
    
    if(Channel == PWM_CHANNEL_1)
    {
        CCP1CON |= 0x0C;
    }
    else if(Channel == PWM_CHANNEL_2)
    {
        CCP2CON |= 0x0C;
    }
}

void PWM_Stop(u8 Channel)
{
    if(Channel == PWM_CHANNEL_1)
    {
        CCP1CON &= 0xF0;
    }
    else if(Channel == PWM_CHANNEL_2)
    {
        CCP2CON &= 0xF0;
    }
}
