#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"


static u8 PWM_CurrentLevel = PWM_INIT_DUTY_LEVEL;


#define PWM_WRITE_DUTY(duty10)                          \
    do {                                                \
        CCPR1L = (u8)((duty10) >> 2);                   \
        if ((duty10) & 0x02)                            \
            SET_BIT(CCP1CON, CCP1CON_DC1B1);           \
        else                                            \
            CLR_BIT(CCP1CON, CCP1CON_DC1B1);           \
        if ((duty10) & 0x01)                            \
            SET_BIT(CCP1CON, CCP1CON_DC1B0);           \
        else                                            \
            CLR_BIT(CCP1CON, CCP1CON_DC1B0);           \
    } while(0)


void PWM_Init(void)
{

    PR2 = PWM_PR2_VALUE;             

    /* Step 2 – initial duty cycle 25 % */
    PWM_WRITE_DUTY(PWM_DUTY_25);

    /* Step 3 – RC2 (CCP1 pin) as output */
    CLR_BIT(TRISC, TRISC2);

    /* Step 4 – TMR2 prescaler 1:4 (T2CKPS<1:0> = 01), start TMR2 */
    CLR_BIT(T2CON, T2CON_T2CKPS1);
    SET_BIT(T2CON, T2CON_T2CKPS0);
    SET_BIT(T2CON, T2CON_TMR2ON);

    /* Step 5 – CCP1 PWM mode: CCP1M<3:0> = 1100 */
    SET_BIT(CCP1CON, CCP1CON_CCP1M3);
    SET_BIT(CCP1CON, CCP1CON_CCP1M2);
    CLR_BIT(CCP1CON, 1);
    CLR_BIT(CCP1CON, 0);
}



void PWM_SetDutyLevel(u8 level)
{
    PWM_CurrentLevel = level % PWM_DUTY_LEVELS_NUM;

    switch (PWM_CurrentLevel)
    {
        case PWM_DUTY_LEVEL_25:
            PWM_WRITE_DUTY(PWM_DUTY_25);
            break;

        case PWM_DUTY_LEVEL_50:
            PWM_WRITE_DUTY(PWM_DUTY_50);
            break;

        case PWM_DUTY_LEVEL_75:
            PWM_WRITE_DUTY(PWM_DUTY_75);
            break;

        case PWM_DUTY_LEVEL_100:
            PWM_WRITE_DUTY(PWM_DUTY_100);
            break;

        default:
            break;
    }
}


void PWM_NextDutyLevel(void)
{
    PWM_CurrentLevel = (PWM_CurrentLevel + 1u) % PWM_DUTY_LEVELS_NUM;
    PWM_SetDutyLevel(PWM_CurrentLevel);
}