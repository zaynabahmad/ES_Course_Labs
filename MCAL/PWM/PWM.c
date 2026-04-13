#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"
#include "../../SERVICES/BIT_MATH.h"

static u8 Local_Channel1_DutyCycle = 0;
static u8 Local_Channel2_DutyCycle = 0;

void PWM_Init(u8 frequency)
{
    u8 Digital_PR2, Prescaler, Temp;

    if (frequency >= 20) {
        Digital_PR2 = 49;
        Prescaler = T2_PRESCALER_1;
    }
    else if (frequency >= 5) {
        Digital_PR2 = 199;
        Prescaler = T2_PRESCALER_1;
    }
    else {
        Digital_PR2 = 124;
        Prescaler = T2_PRESCALER_4;
    }

    PR2 = Digital_PR2;
    T2CON = 0x00;

    Temp = (Prescaler << 0);
    Temp |= (1 << TMR2ON);
    T2CON = Temp;

    CCP1CON = CCP_MODE_PWM;
    CCP2CON = CCP_MODE_PWM;

    CLR_BIT(TRISC, 2);
    CLR_BIT(TRISC, 1);

    Local_Channel1_DutyCycle = 0;
    Local_Channel2_DutyCycle = 0;

    CCPR1L = 0;
    CCPR2L = 0;
}

void PWM_SetDutyCycle(u8 channel, u8 dutyCycle)
{
    u16 Digital_DutyCycle;
    u8 Temp;

    if (dutyCycle > 100)
        dutyCycle = 100;

    Digital_DutyCycle = ((u16)dutyCycle * (PR2 + 1) * 4) / 100;

    switch (channel)
    {
        case PWM_CHANNEL1:
            CCPR1L = (Digital_DutyCycle >> 2) & 0xFF;
            Temp = (Digital_DutyCycle & 0x03);
            PWM1CON = (PWM1CON & 0xFC) | Temp;
            Local_Channel1_DutyCycle = dutyCycle;
            break;

        case PWM_CHANNEL2:
            CCPR2L = (Digital_DutyCycle >> 2) & 0xFF;
            Local_Channel2_DutyCycle = dutyCycle;
            break;

        default:
            break;
    }
}

void PWM_Start(u8 channel)
{
    switch (channel)
    {
        case PWM_CHANNEL1:
            CCP1CON = CCP_MODE_PWM;
            break;

        case PWM_CHANNEL2:
            CCP2CON = CCP_MODE_PWM;
            break;

        default:
            break;
    }
}

void PWM_Stop(u8 channel)
{
    switch (channel)
    {
        case PWM_CHANNEL1:
            CCP1CON = CCP_MODE_OFF;
            break;

        case PWM_CHANNEL2:
            CCP2CON = CCP_MODE_OFF;
            break;

        default:
            break;
    }
}

u8 PWM_GetDutyCycle(u8 channel)
{
    switch (channel)
    {
        case PWM_CHANNEL1:
            return Local_Channel1_DutyCycle;

        case PWM_CHANNEL2:
            return Local_Channel2_DutyCycle;

        default:
            return 0;
    }
}
