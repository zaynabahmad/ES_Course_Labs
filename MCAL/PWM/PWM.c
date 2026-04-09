#include "PWM_Interface.h"
#include "PWM_Private.h"
#include "../GPIO/GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"

static u8 PWM_PeriodShadow = 0;

void PWM_Init(PWM_ConfigType *ConfigPtr)
{
    if (ConfigPtr == 0)
    {
        return;
    }

    PWM_PeriodShadow = ConfigPtr->Period;
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN2, GPIO_OUTPUT);

    PR2 = ConfigPtr->Period;
    T2CON &= (u8)~0x03;
    T2CON |= (ConfigPtr->Timer2Prescaler & 0x03);

    CCP1CON &= (u8)~0x0F;
    CCP1CON |= 0x0C;

    PWM_SetDutyCycle(ConfigPtr->DutyPercent);
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

    if (DutyPercent > 100)
    {
        DutyPercent = 100;
    }

    Local_DutyValue = (u16)(((u32)(PWM_PeriodShadow + 1) * 4UL * DutyPercent) / 100UL);
    CCPR1L = (u8)(Local_DutyValue >> 2);
    CCP1CON &= (u8)~0x30;
    CCP1CON |= (u8)((Local_DutyValue & 0x03) << 4);
}
