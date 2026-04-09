#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "PWM_interface.h"
#include "PWM_config.h"

/* Helper: Convert percentage ? 10-bit duty */
static u16 PWM_ConvertDuty(u8 percent)
{
    return (u16)((percent * 1023UL) / 100);
}

void PWM_Init(void)
{
    /* Set PWM period */
    PR2 = PWM_PR2_VALUE;

    /* Configure Timer2 prescaler */
    T2CON &= 0xFC;

    #if PWM_TMR2_PRESCALER == 1
        /* 00 */
    #elif PWM_TMR2_PRESCALER == 4
        SET_BIT(T2CON, 0);
    #elif PWM_TMR2_PRESCALER == 16
        SET_BIT(T2CON, 1);
    #endif

    /* Start Timer2 */
    SET_BIT(T2CON, TMR2ON);
}

void PWM_Start(u8 Channel)
{
    if(Channel == PWM_CHANNEL_1)
    {
        /* CCP1 PWM mode */
        CCP1CON = 0x0C;
    }
    else if(Channel == PWM_CHANNEL_2)
    {
        /* CCP2 PWM mode */
        CCP2CON = 0x0C;
    }
}

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

void PWM_SetDutyCycle(u8 Channel, u8 DutyPercent)
{
    u16 duty = PWM_ConvertDuty(DutyPercent);

    if(Channel == PWM_CHANNEL_1)
    {
        CCPR1L = duty >> 2;

        CCP1CON &= 0xCF;
        CCP1CON |= ((duty & 0x03) << 4);
    }
    else if(Channel == PWM_CHANNEL_2)
    {
        CCPR2L = duty >> 2;

        CCP2CON &= 0xCF;
        CCP2CON |= ((duty & 0x03) << 4);
    }
}