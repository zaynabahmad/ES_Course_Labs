#include "PWM_Interface.h"
#include "PWM_Private.h"
#include "PWM_Config.h"

#include "../../SERVICES/BIT_MATH.h"

static u8 PWM_Pr2Cached = 0;

void PWM_Init(u16 FrequencyHz)
{
    u32 Local_PR2;

    if (FrequencyHz == 0U)
    {
        FrequencyHz = 1000U;
    }

    CLR_BIT(TRISC, 2);

    Local_PR2 = (PWM_FOSC_HZ / (4UL * PWM_T2_PRESCALER * (u32)FrequencyHz));
    if (Local_PR2 == 0UL)
    {
        Local_PR2 = 1UL;
    }
    Local_PR2 -= 1UL;

    if (Local_PR2 > 255UL)
    {
        Local_PR2 = 255UL;
    }

    PWM_Pr2Cached = (u8)Local_PR2;
    PR2 = PWM_Pr2Cached;

    CCP1CON &= (u8)0xF0;
    CCP1CON |= 0x0C;

    if (PWM_T2_PRESCALER == 1U)
    {
        T2CON &= (u8)0xFC;
    }
    else if (PWM_T2_PRESCALER == 4U)
    {
        T2CON = (u8)((T2CON & (u8)0xFC) | 0x01);
    }
    else
    {
        T2CON = (u8)((T2CON & (u8)0xFC) | 0x02);
    }

    PWM_SetDutyCycle(0);
}

void PWM_Start(void)
{
    SET_BIT(T2CON, TMR2ON_BIT);
}

void PWM_Stop(void)
{
    CLR_BIT(T2CON, TMR2ON_BIT);
}

void PWM_SetDutyCycle(u8 DutyPercent)
{
    u16 Local_DutyValue;

    if (DutyPercent > 100U)
    {
        DutyPercent = 100U;
    }

    Local_DutyValue = (u16)(((u32)DutyPercent * (u32)(PWM_Pr2Cached + 1U) * 4UL) / 100UL);

    CCPR1L = (u8)(Local_DutyValue >> 2);

    if ((Local_DutyValue & 0x01U) != 0U)
    {
        SET_BIT(CCP1CON, CCP1X_BIT);
    }
    else
    {
        CLR_BIT(CCP1CON, CCP1X_BIT);
    }

    if ((Local_DutyValue & 0x02U) != 0U)
    {
        SET_BIT(CCP1CON, (CCP1X_BIT + 1));
    }
    else
    {
        CLR_BIT(CCP1CON, (CCP1X_BIT + 1));
    }
}
