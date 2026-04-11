#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"

static u16 PWM_g_pr2_plus1 = 1;

static void PWM_Timer2_SetPrescaler(u8 prescaler)
{
    switch(prescaler)
    {
        case 1:
            CLR_BIT(T2CON, T2CKPS1_BIT);
            CLR_BIT(T2CON, T2CKPS0_BIT);
            break;

        case 4:
            CLR_BIT(T2CON, T2CKPS1_BIT);
            SET_BIT(T2CON, T2CKPS0_BIT);
            break;

        case 16:
            SET_BIT(T2CON, T2CKPS1_BIT);
            CLR_BIT(T2CON, T2CKPS0_BIT);
            break;

        default:
            CLR_BIT(T2CON, T2CKPS1_BIT);
            SET_BIT(T2CON, T2CKPS0_BIT);
            break;
    }
}

void PWM_Init(unsigned long freq_hz)
{
    u32 pr2_calc;
    u8 selected_prescaler = 1;

    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN2, GPIO_OUTPUT);

    /* Choose prescaler so PR2 fits in 8 bits */
    pr2_calc = (PWM_FOSC_HZ / (freq_hz * 4UL * selected_prescaler)) - 1UL;

    if(pr2_calc > 255UL)
    {
        selected_prescaler = 4;
        pr2_calc = (PWM_FOSC_HZ / (freq_hz * 4UL * selected_prescaler)) - 1UL;
    }

    if(pr2_calc > 255UL)
    {
        selected_prescaler = 16;
        pr2_calc = (PWM_FOSC_HZ / (freq_hz * 4UL * selected_prescaler)) - 1UL;
    }

    if(pr2_calc > 255UL)
    {
        pr2_calc = 255UL;
    }

    PR2 = (u8)pr2_calc;
    PWM_g_pr2_plus1 = (u16)(pr2_calc + 1UL);

    PWM_Timer2_SetPrescaler(selected_prescaler);

    /* CCP1 PWM mode = 1100 */
    CLR_BIT(CCP1CON, CCP1M0_BIT);
    CLR_BIT(CCP1CON, CCP1M1_BIT);
    SET_BIT(CCP1CON, CCP1M2_BIT);
    SET_BIT(CCP1CON, CCP1M3_BIT);

    /* Start with 0% duty */
    CCPR1L = 0;
    CLR_BIT(CCP1CON, DC1B0_BIT);
    CLR_BIT(CCP1CON, DC1B1_BIT);
}

void PWM_Start(void)
{
    CLR_BIT(PIR1, TMR2IF_BIT);
    SET_BIT(T2CON, TMR2ON_BIT);

    while(GET_BIT(PIR1, TMR2IF_BIT) == 0)
    {
    }

    CLR_BIT(PIR1, TMR2IF_BIT);
}

void PWM_Stop(void)
{
    CLR_BIT(T2CON, TMR2ON_BIT);
}

void PWM_SetDutyPercent(u8 duty_percent)
{
    u32 duty_10bit;

    if(duty_percent > 100)
    {
        duty_percent = 100;
    }

    duty_10bit = ((u32)duty_percent * 4UL * PWM_g_pr2_plus1) / 100UL;

    CCPR1L = (u8)(duty_10bit >> 2);

    if(duty_10bit & 0x01)
        SET_BIT(CCP1CON, DC1B0_BIT);
    else
        CLR_BIT(CCP1CON, DC1B0_BIT);

    if(duty_10bit & 0x02)
        SET_BIT(CCP1CON, DC1B1_BIT);
    else
        CLR_BIT(CCP1CON, DC1B1_BIT);
}

void PWM_SetDutyRaw(u8 duty_raw)
{
    u16 duty_10bit;

    duty_10bit = ((u32)duty_raw * 4UL * PWM_g_pr2_plus1) / 255UL;

    CCPR1L = (u8)(duty_10bit >> 2);

    if(duty_10bit & 0x01)
        SET_BIT(CCP1CON, DC1B0_BIT);
    else
        CLR_BIT(CCP1CON, DC1B0_BIT);

    if(duty_10bit & 0x02)
        SET_BIT(CCP1CON, DC1B1_BIT);
    else
        CLR_BIT(CCP1CON, DC1B1_BIT);
}