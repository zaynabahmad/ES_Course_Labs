#include "PWM_Interface.h"

/* ================= Initialization ================= */

void PWM_Init(u8 Channel)
{
    u8 PR2_Value;

    /* Calculate PR2 for desired frequency */
    /* PR2 = (FOSC / (4 * Prescaler * PWM_FREQUENCY)) - 1 */
    PR2_Value = (u8)((FOSC / (4UL * PWM_PRESCALER * PWM_FREQUENCY)) - 1);
    PR2 = PR2_Value;

    /* Configure Timer2 prescaler and turn it on */
    T2CON = 0x00;

#if   PWM_PRESCALER == 1
    CLR_BIT(T2CON, T2CKPS0);
    CLR_BIT(T2CON, T2CKPS1);
#elif PWM_PRESCALER == 4
    SET_BIT(T2CON, T2CKPS0);
    CLR_BIT(T2CON, T2CKPS1);
#elif PWM_PRESCALER == 16
    CLR_BIT(T2CON, T2CKPS0);
    SET_BIT(T2CON, T2CKPS1);
#endif

    /* Enable Timer2 */
    SET_BIT(T2CON, TMR2ON);

    if(Channel == PWM_CHANNEL_1)
    {
        /* Set RC2 (CCP1) as output */
        CLR_BIT(TRISC, 2);

        /* Clear CCP1CON and duty cycle */
        CCP1CON = 0x00;
        CCPR1L  = 0x00;

        /* Set PWM mode on CCP1: CCP_MODE = 1100 */
        SET_BIT(CCP1CON, CCP_MODE3);
        SET_BIT(CCP1CON, CCP_MODE2);
        CLR_BIT(CCP1CON, CCP_MODE1);
        CLR_BIT(CCP1CON, CCP_MODE0);
    }
    else if(Channel == PWM_CHANNEL_2)
    {
        /* Set RC1 (CCP2) as output */
        CLR_BIT(TRISC, 1);

        /* Clear CCP2CON and duty cycle */
        CCP2CON = 0x00;
        CCPR2L  = 0x00;

        /* Set PWM mode on CCP2 */
        SET_BIT(CCP2CON, CCP_MODE3);
        SET_BIT(CCP2CON, CCP_MODE2);
        CLR_BIT(CCP2CON, CCP_MODE1);
        CLR_BIT(CCP2CON, CCP_MODE0);
    }
}

/* ================= Set Duty Cycle (0-100%) ================= */

void PWM_SetDutyCycle(u8 Channel, u8 DutyCycle)
{
    u16 DutyCycleValue;

    if(DutyCycle > 100) DutyCycle = 100;

    /* DutyCycleValue = DutyCycle% * (PR2 + 1) * 4 */
    DutyCycleValue = (u16)((u32)DutyCycle * (PR2 + 1) * 4) / 100;

    if(Channel == PWM_CHANNEL_1)
    {
        CCPR1L = (u8)(DutyCycleValue >> 2);
        CCP1CON &= 0xCF;
        CCP1CON |= (u8)((DutyCycleValue & 0x03) << 4);
    }
    else if(Channel == PWM_CHANNEL_2)
    {
        CCPR2L = (u8)(DutyCycleValue >> 2);
        CCP2CON &= 0xCF;
        CCP2CON |= (u8)((DutyCycleValue & 0x03) << 4);
    }
}

/* ================= Start PWM Output ================= */

void PWM_Start(u8 Channel)
{
    if(Channel == PWM_CHANNEL_1)
    {
        SET_BIT(CCP1CON, CCP_MODE3);
        SET_BIT(CCP1CON, CCP_MODE2);
    }
    else if(Channel == PWM_CHANNEL_2)
    {
        SET_BIT(CCP2CON, CCP_MODE3);
        SET_BIT(CCP2CON, CCP_MODE2);
    }
}

/* ================= Stop PWM Output ================= */

void PWM_Stop(u8 Channel)
{
    if(Channel == PWM_CHANNEL_1)
    {
        CCP1CON = 0x00;
    }
    else if(Channel == PWM_CHANNEL_2)
    {
        CCP2CON = 0x00;
    }
}
