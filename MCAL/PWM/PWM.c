#include "PWM_Interface.h"

void PWM_Init(void)
{
    /* Set RC2 (CCP1 pin) as output */
    CLR_BIT(TRISC, 2);

    /* Set PWM period */
    PR2 = (u8)PWM_PR2_VALUE;

    /* Configure CCP1 as PWM mode (1100) */
    SET_BIT(CCP1CON, CCP1M3);
    SET_BIT(CCP1CON, CCP1M2);
    CLR_BIT(CCP1CON, CCP1M3 - 1);  /* bit1 = 0 */
    CLR_BIT(CCP1CON, CCP1M2 - 2);  /* bit0 = 0 */

    /* CCP1CON = 0x0C (PWM mode) */
    CCP1CON = (CCP1CON & 0xF0) | 0x0C;

    /* Set prescaler */
    #if   PWM_PRESCALER == 1
        CLR_BIT(T2CON, T2CKPS1); CLR_BIT(T2CON, T2CKPS0);
    #elif PWM_PRESCALER == 4
        CLR_BIT(T2CON, T2CKPS1); SET_BIT(T2CON, T2CKPS0);
    #elif PWM_PRESCALER == 16
        SET_BIT(T2CON, T2CKPS1); SET_BIT(T2CON, T2CKPS0);
    #endif

    /* Start Timer2 */
    SET_BIT(T2CON, TMR2ON);
}

void PWM_SetDutyCycle(u8 DutyCyclePercent)
{
    u16 DutyValue;

    if (DutyCyclePercent > 100) DutyCyclePercent = 100;

    /* 10-bit duty = (duty% / 100) * 4 * (PR2 + 1) */
    DutyValue = ((u16)DutyCyclePercent * 4 * ((u16)PWM_PR2_VALUE + 1)) / 100;

    CCPR1L = (u8)(DutyValue >> 2);

    /* Load 2 LSBs into DC1B1:DC1B0 */
    CCP1CON = (CCP1CON & 0xCF) | ((u8)(DutyValue & 0x03) << 4);
}

void PWM_Stop(void)
{
    CCP1CON = 0x00;
}
