#include "PWM_Interface.h"

void PWM_Init(u8 Channel)
{
    /* 1. Set PR2 for PWM period */
    PR2 = PWM_PR2_VALUE;

    /* 2. Set CCP pin as output */
    if(Channel == PWM_CCP1)
    {
        CLR_BIT(TRISC, CCP1_PIN);
        /* Set PWM mode: CCP1M3:CCP1M0 = 11xx */
        CCP1CON |= 0x0C;
        CCPR1L = 0;
    }
    else if(Channel == PWM_CCP2)
    {
        CLR_BIT(TRISC, CCP2_PIN);
        CCP2CON |= 0x0C;
        CCPR2L = 0;
    }

    /* 3. Configure Timer2 prescaler */
    T2CON &= 0xFC;  /* Clear T2CKPS bits */
    #if PWM_T2_PRESCALER == PWM_T2_PRE_1
        /* bits already 00 */
    #elif PWM_T2_PRESCALER == PWM_T2_PRE_4
        SET_BIT(T2CON, T2CKPS0_BIT);
    #elif PWM_T2_PRESCALER == PWM_T2_PRE_16
        SET_BIT(T2CON, T2CKPS0_BIT);
        SET_BIT(T2CON, T2CKPS1_BIT);
    #endif
}

void PWM_Start(u8 Channel)
{
    /* Enable Timer2 */
    SET_BIT(T2CON, TMR2ON_BIT);
}

void PWM_Stop(u8 Channel)
{
    if(Channel == PWM_CCP1)
        CCP1CON = 0x00;
    else if(Channel == PWM_CCP2)
        CCP2CON = 0x00;
}

void PWM_SetDuty(u8 Channel, u16 DutyValue)
{
    /* 10-bit duty: upper 8 bits -> CCPRxL, lower 2 bits -> DCxB1:DCxB0 */
    u8 upper = (u8)(DutyValue >> 2);
    u8 lower = (u8)(DutyValue & 0x03);

    if(Channel == PWM_CCP1)
    {
        CCPR1L = upper;
        CCP1CON &= 0xCF;               /* Clear DC1B1:DC1B0 */
        CCP1CON |= (lower << 4);       /* Set lower 2 bits */
    }
    else if(Channel == PWM_CCP2)
    {
        CCPR2L = upper;
        CCP2CON &= 0xCF;
        CCP2CON |= (lower << 4);
    }
}

void PWM_SetDutyPercent(u8 Channel, u8 Percent)
{
    /* Max 10-bit value = 4*(PR2+1) */
    u16 maxDuty = (u16)4 * ((u16)PWM_PR2_VALUE + 1);
    u16 dutyVal = (u16)((u32)Percent * maxDuty / 100);
    PWM_SetDuty(Channel, dutyVal);
}
