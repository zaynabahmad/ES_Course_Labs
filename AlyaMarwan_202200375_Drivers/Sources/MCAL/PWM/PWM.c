#include "pwm.h"
#include "bit_math.h"

void PWM_Init(void)
{
    /* Step 1: Set RC2 (CCP1) as output */
    CLR_BIT(TRISC, 2);

    /* Step 2: Set PWM period via PR2 */
    PR2 = PWM_PR2;

    /* Step 3: Configure CCP1 for PWM mode */
    CCP1CON = 0x0C;              /* bits 3:0 = 1100 ? PWM mode */

    /* Step 4: Configure Timer2 prescaler and enable */
    T2CON = 0x00;                /* Clear first */
    if(PWM_PRESCALER == PWM_PRESCALER_4)
    {
        SET_BIT(T2CON, 0);       /* T2CKPS = 01 ? prescaler 1:4 */
    }
    else if(PWM_PRESCALER == PWM_PRESCALER_16)
    {
        SET_BIT(T2CON, 0);
        SET_BIT(T2CON, 1);       /* T2CKPS = 11 ? prescaler 1:16 */
    }

    /* Step 5: Start with 50% duty cycle */
    PWM_SetDuty(50);

    /* Step 6: Enable Timer2 */
    SET_BIT(T2CON, 2);           /* TMR2ON = 1 */
}

void PWM_SetDuty(uint8 dutyPercent)
{
    uint16 dutyCycle;

    if(dutyPercent > 100) dutyPercent = 100;

    /* duty = (dutyPercent / 100) × 4 × (PR2 + 1) */
    dutyCycle = ((uint16)dutyPercent * 4 * (PWM_PR2 + 1)) / 100;

    /* Upper 8 bits ? CCPR1L */
    CCPR1L = (uint8)(dutyCycle >> 2);

    /* Lower 2 bits ? CCP1CON bits 5:4 */
    CCP1CON = (CCP1CON & 0xCF) | ((dutyCycle & 0x03) << 4);
}

void PWM_Start(void)
{
    SET_BIT(T2CON, 2);           /* TMR2ON = 1 */
}

void PWM_Stop(void)
{
    CLR_BIT(T2CON, 2);           /* TMR2ON = 0 */
}