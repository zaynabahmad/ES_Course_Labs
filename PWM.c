#include "PWM_INTERFACE.h"
#include "PWM_PRIVATE.h"
#include "PWM_CONFIG.h"
#include "../SERVICES/BIT_MATH.h"

void PWM_Init(void)
{
    /* RC2/CCP1 pin must be output */
    CLR_BIT(TRISC, 2);

    /* Set PWM period via PR2 */
    PR2 = PWM_PR2_VALUE;

    /* PWM mode: CCP1M3:CCP1M2 = 11, CCP1M1:CCP1M0 = 00 */
    SET_BIT(CCP1CON, CCP1M3);
    SET_BIT(CCP1CON, CCP1M2);
    CLR_BIT(CCP1CON, CCP1M1);
    CLR_BIT(CCP1CON, CCP1M0);

    /* Set Timer2 prescaler */
    T2CON = (T2CON & 0xFC) | (PWM_TIMER2_PRESCALE & 0x03);

    /* Start Timer2 */
    SET_BIT(T2CON, TMR2ON);
}

void PWM_SetDutyCycle(u8 duty_percent)
{
    u16 duty_val;

    if(duty_percent > 100) duty_percent = 100;

    /* 10-bit duty = duty_percent * (PR2+1) * 4 / 100 */
    duty_val = ((u16)duty_percent * ((u16)PWM_PR2_VALUE + 1) * 4u) / 100u;

    /* Upper 8 bits -> CCPR1L */
    CCPR1L = (u8)(duty_val >> 2);

    /* Lower 2 bits -> DC1B1:DC1B0 in CCP1CON */
    if(GET_BIT(duty_val, 1))
        SET_BIT(CCP1CON, DC1B1);
    else
        CLR_BIT(CCP1CON, DC1B1);

    if(GET_BIT(duty_val, 0))
        SET_BIT(CCP1CON, DC1B0);
    else
        CLR_BIT(CCP1CON, DC1B0);
}

void PWM_Start(void)
{
    SET_BIT(T2CON, TMR2ON);
}

void PWM_Stop(void)
{
    CLR_BIT(T2CON, TMR2ON);
}
