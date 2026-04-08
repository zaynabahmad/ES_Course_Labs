#include "PWM_Interface.h"

/* =========================================================
   PWM_Init
   - Sets up PR2 for frequency
   - Configures Timer2 prescaler
========================================================= */
void PWM_Init(void)
{
    /* Set PWM Period */
    PR2 = PWM_PR2_VALUE;

    /* Set Timer2 Prescaler */
#if PWM_TMR2_PRESCALER == 1
    CLR_BIT(T2CON, T2CKPS1_BIT);
    CLR_BIT(T2CON, T2CKPS0_BIT);
#elif PWM_TMR2_PRESCALER == 4
    CLR_BIT(T2CON, T2CKPS1_BIT);
    SET_BIT(T2CON, T2CKPS0_BIT);
#elif PWM_TMR2_PRESCALER == 16
    SET_BIT(T2CON, T2CKPS1_BIT);
    CLR_BIT(T2CON, T2CKPS0_BIT); /* Optional: 1x sets it to 16 */
#endif

    /* Clear CCP modules */
    CCP1CON = 0x00;
    CCP2CON = 0x00;
}

/* =========================================================
   PWM_Start
   - Enables Timer2
   - Configures CCPx as PWM and sets pin to output
========================================================= */
void PWM_Start(u8 Channel)
{
    if(Channel == PWM_CHANNEL_1)
    {
        CLR_BIT(TRISC, 2);                      /* Set RC2 as output */
        CCP1CON |= PWM_MODE_MASK;               /* Enable PWM mode */
    }
    else if(Channel == PWM_CHANNEL_2)
    {
        CLR_BIT(TRISC, 1);                      /* Set RC1 as output */
        CCP2CON |= PWM_MODE_MASK;               /* Enable PWM mode */
    }
    
    SET_BIT(T2CON, TMR2ON_BIT);                 /* Turn on Timer2 */
}

/* =========================================================
   PWM_Stop
========================================================= */
void PWM_Stop(u8 Channel)
{
    if(Channel == PWM_CHANNEL_1)
    {
        CCP1CON &= ~PWM_MODE_MASK;              /* Disable PWM mode */
    }
    else if(Channel == PWM_CHANNEL_2)
    {
        CCP2CON &= ~PWM_MODE_MASK;              /* Disable PWM mode */
    }
}

/* =========================================================
   PWM_SetDutyCycle
   - DutyPercent: 0 to 100
   - Uses the 10-bit resolution spread across CCPRxL and CCPxCON
========================================================= */
void PWM_SetDutyCycle(u8 Channel, u8 DutyPercent)
{
    u16 total_resolution;
    u16 duty_10bit;

    if(DutyPercent > 100) DutyPercent = 100;

    /* Total counts in period = (PR2 + 1) * 4 */
    total_resolution = (PR2 + 1) * 4;

    /* Calculate 10-bit duty cycle value */
    duty_10bit = ((u32)DutyPercent * total_resolution) / 100;

    if(Channel == PWM_CHANNEL_1)
    {
        /* Top 8 bits go into CCPR1L */
        CCPR1L = (u8)(duty_10bit >> 2);
        
        /* Bottom 2 bits go to bit 4 and 5 of CCP1CON */
        CCP1CON &= 0xCF; /* Clear bits 4 and 5 */
        CCP1CON |= ((duty_10bit & 0x03) << 4);
    }
    else if(Channel == PWM_CHANNEL_2)
    {
        /* Top 8 bits go into CCPR2L */
        CCPR2L = (u8)(duty_10bit >> 2);
        
        /* Bottom 2 bits go to bit 4 and 5 of CCP2CON */
        CCP2CON &= 0xCF; /* Clear bits 4 and 5 */
        CCP2CON |= ((duty_10bit & 0x03) << 4);
    }
}