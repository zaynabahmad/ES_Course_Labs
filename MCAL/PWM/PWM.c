#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"

void PWM_Init(u8 Copy_u8PR2Value)
{
    PR2 = Copy_u8PR2Value;
    CCPR1L = 0;
    CCP1CON &= 0xCF;

    CLR_BIT(TRISC, 2);
    T2CON = 0x07;

    SET_BIT(CCP1CON, 3);
    SET_BIT(CCP1CON, 2);
}

void PWM_SetDutyCycle(u8 Copy_u8DutyPercentage)
{
    u16 Local_u16DutyValue;

    if (Copy_u8DutyPercentage > 100)
    {
        Copy_u8DutyPercentage = 100;
    }

    Local_u16DutyValue = (u16)(((u32)Copy_u8DutyPercentage * 4 * (PR2 + 1)) / 100);
    CCPR1L = (u8)(Local_u16DutyValue >> 2);
    CCP1CON = (CCP1CON & 0xCF) | ((u8)(Local_u16DutyValue & 0x03) << 4);
}

void PWM_Stop(void)
{
    CLR_BIT(T2CON, 2);
}
