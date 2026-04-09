#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "PWM_Interface.h"
#include "PWM_Private.h"
#include "PWM_Config.h"

void PWM_voidInit(void)
{

    CLR_BIT(TRISC_REG, 2);
    TMR2_PERIOD_REG = PWM_PR2_VALUE;
    CCP1_DATA_LOW_REG = 0;
    CCP1_CON_REG &= ~CCP1_DUTY_L_MASK;
    CCP1_CON_REG = (CCP1_CON_REG & 0xF0) | CCP1_MODE_PWM;
    TMR2_CON_REG = (TMR2_CON_REG & ~TMR2_PRE_MASK) | (PWM_T2_PRESCALER_MASK & TMR2_PRE_MASK);
    CLR_BIT(TMR2_CON_REG, TMR2_ON_BIT);
}

void PWM_voidSetDutyRaw(u16 Copy_u16DutyValue)
{
    if (Copy_u16DutyValue > 1023) Copy_u16DutyValue = 1023;


    CCP1_DATA_LOW_REG = (u8)(Copy_u16DutyValue >> 2);
    CCP1_CON_REG &= ~CCP1_DUTY_L_MASK;
    CCP1_CON_REG |= (u8)((Copy_u16DutyValue & 0x03) << 4);
}

void PWM_voidSetDutyCycle(u8 Copy_u8DutyPercent)
{
    u16 Local_u16DutyRaw;
    if (Copy_u8DutyPercent > 100) Copy_u8DutyPercent = 100;


    Local_u16DutyRaw = (u16)(((u32)(TMR2_PERIOD_REG + 1) * Copy_u8DutyPercent << 2) / 100);

    PWM_voidSetDutyRaw(Local_u16DutyRaw);
}

void PWM_voidStart(void)
{
    SET_BIT(TMR2_CON_REG, TMR2_ON_BIT);
}

void PWM_voidStop(void)
{
    CLR_BIT(TMR2_CON_REG, TMR2_ON_BIT);
}