#include "PWM_Interface.h"
#include "PWM_Private.h"
#include "PWM_Config.h"
#include "../../SERVICES/BIT_MATH.h"

void PWM1_Init(void)
{
    /* Set CCP1 pin (RC2) as output */
    CLR_BIT(TRISC, PWM_PIN);

    /* Set PWM Period */
    PR2 = PWM_PR2_VALUE;

    /* Configure CCP1 module in PWM mode */
    CCP1CON = 0x0C; // CCP1M3:CCP1M0 = 1100

    /* Initialize duty cycle to 0 */
    CCPR1L = 0;
    CLR_BIT(CCP1CON, 4);
    CLR_BIT(CCP1CON, 5);

    /* Set Timer2 Prescaler to 16 and enable Timer2 */
    T2CON = 0x06; // T2CKPS1 = 1, TMR2ON = 1
}

void PWM1_SetDutyCycle(u8 DutyCycle)
{
    u16 PWM_Value;

    /* Calculate PWM value based on DutyCycle percentage (0-100) */
    /* PWM_Value = (DutyCycle * (PR2 + 1) * 4) / 100 */
    PWM_Value = ((u16)DutyCycle * (PWM_PR2_VALUE + 1) * 4) / 100;

    /* Store the 8 MSBs in CCPR1L */
    CCPR1L = (u8)(PWM_Value >> 2);

    /* Store the 2 LSBs in CCP1CON<5:4> */
    if (GET_BIT(PWM_Value, 1)) SET_BIT(CCP1CON, 5); else CLR_BIT(CCP1CON, 5);
    if (GET_BIT(PWM_Value, 0)) SET_BIT(CCP1CON, 4); else CLR_BIT(CCP1CON, 4);
}