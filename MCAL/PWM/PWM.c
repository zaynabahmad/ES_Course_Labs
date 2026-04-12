#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"
#include "../../SERVICES/BIT_MATH.h"

void PWM_Init(void)
{
    /* Set CCP1 pin (RC2) as output */
    CLR_BIT(TRISC, 2);

    /* Set PWM mode in CCP1CON: bits 3:0 = 1100 */
    SET_BIT(CCP1CON, 3);
    SET_BIT(CCP1CON, 2);
    CLR_BIT(CCP1CON, 1);
    CLR_BIT(CCP1CON, 0);

    /* Set period in PR2 */
    PR2 = PWM_PR2_VALUE;

    /* Set Timer2 prescaler and turn on Timer2 */
    T2CON = (PWM_PRESCALER) | (1 << 2);
}

void PWM_SetDutyCycle(u8 DutyCycle)
{
    u16 Local_DutyValue;

    if(DutyCycle > 100) DutyCycle = 100;

    /* DutyValue = (DutyCycle / 100) * 4 * (PR2 + 1) */
    Local_DutyValue = ((u16)DutyCycle * 4 * (PWM_PR2_VALUE + 1)) / 100;

    /* Upper 8 bits in CCPR1L */
    CCPR1L = (u8)(Local_DutyValue >> 2);

    /* Lower 2 bits in CCP1CON bits 5:4 */
    if(Local_DutyValue & 0x01) SET_BIT(CCP1CON, 4); else CLR_BIT(CCP1CON, 4);
    if(Local_DutyValue & 0x02) SET_BIT(CCP1CON, 5); else CLR_BIT(CCP1CON, 5);
}

void PWM_Stop(void)
{
    CLR_BIT(CCP1CON, 3);
    CLR_BIT(CCP1CON, 2);
}