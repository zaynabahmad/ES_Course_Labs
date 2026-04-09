#include "PWM_Interface.h"
#include "PWM_Private.h"
#include "PWM_Config.h"

#include "../../SERVICES/BIT_MATH.h"

void PWM_Init(void)
{
    /* Initialize PR2 for Period setup */
    PR2 = PWM_PR2_VALUE;

    /* Initialize Timer2 Prescaler using Configuration */
#if (PWM_PRESCALER == 1)
    /* 1:1 Prescaler */
    CLR_BIT(T2CON, 0);
    CLR_BIT(T2CON, 1);
#elif (PWM_PRESCALER == 4)
    /* 1:4 Prescaler */
    SET_BIT(T2CON, 0);
    CLR_BIT(T2CON, 1);
#elif (PWM_PRESCALER == 16)
    /* 1:16 Prescaler */
    SET_BIT(T2CON, 0);
    SET_BIT(T2CON, 1);
#else
    /* Default to 1:1 Prescaler */
    CLR_BIT(T2CON, 0);
    CLR_BIT(T2CON, 1);
#endif

    /* Clear Duty Cycle Registers */
    CCPR1L = 0;
    CCPR2L = 0;

    /* Turn Timer2 ON */
    SET_BIT(T2CON, TMR2ON);
}

void PWM_SetDutyCycle(u8 Channel, u8 DutyCycle_Percent)
{
    u16 DutyCycle_Steps = 0;

    if (DutyCycle_Percent > 100)
    {
        DutyCycle_Percent = 100;
    }

    /* Total steps per period = (PR2 + 1) * 4 */
    DutyCycle_Steps = (u16)(((u32)DutyCycle_Percent * (PWM_PR2_VALUE + 1) * 4) / 100);

    if (Channel == PWM_CCP1)
    {
        /* Set upper 8 bits */
        CCPR1L = (u8)(DutyCycle_Steps >> 2);

        /* Set lower 2 bits into CCP1CON bits 5:4 */
        CCP1CON = (CCP1CON & 0xCF) | ((u8)(DutyCycle_Steps & 0x03) << 4);
    }
    else if (Channel == PWM_CCP2)
    {
        /* Set upper 8 bits */
        CCPR2L = (u8)(DutyCycle_Steps >> 2);

        /* Set lower 2 bits into CCP2CON bits 5:4 */
        CCP2CON = (CCP2CON & 0xCF) | ((u8)(DutyCycle_Steps & 0x03) << 4);
    }
}

void PWM_Start(u8 Channel)
{
    if (Channel == PWM_CCP1)
    {
        /* Set PWM mode in CCP1CON (<3:0> = 11xx -> 1100) */
        SET_BIT(CCP1CON, CCPxM3);
        SET_BIT(CCP1CON, CCPxM2);
        CLR_BIT(CCP1CON, CCPxM1);
        CLR_BIT(CCP1CON, CCPxM0);
    }
    else if (Channel == PWM_CCP2)
    {
        /* Set PWM mode in CCP2CON (<3:0> = 11xx -> 1100) */
        SET_BIT(CCP2CON, CCPxM3);
        SET_BIT(CCP2CON, CCPxM2);
        CLR_BIT(CCP2CON, CCPxM1);
        CLR_BIT(CCP2CON, CCPxM0);
    }
}

void PWM_Stop(u8 Channel)
{
    if (Channel == PWM_CCP1)
    {
        /* Disable CCP1 */
        CLR_BIT(CCP1CON, CCPxM3);
        CLR_BIT(CCP1CON, CCPxM2);
        CLR_BIT(CCP1CON, CCPxM1);
        CLR_BIT(CCP1CON, CCPxM0);
    }
    else if (Channel == PWM_CCP2)
    {
        /* Disable CCP2 */
        CLR_BIT(CCP2CON, CCPxM3);
        CLR_BIT(CCP2CON, CCPxM2);
        CLR_BIT(CCP2CON, CCPxM1);
        CLR_BIT(CCP2CON, CCPxM0);
    }
}
