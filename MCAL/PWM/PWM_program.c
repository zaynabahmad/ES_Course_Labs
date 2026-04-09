#include "PWM_interface.h"
#include "PWM_private.h"
#include "../../SERVICES/BIT_MATH.h"

void PWM_Init(void)
{
    /* Step 1 – RC2/CCP1 as output */
    CLR_BIT(TRISC, 2);

    /* Step 2 – Set PWM period via PR2
     *   PWM period = (PR2 + 1) * 4 * Tosc * Prescaler
     *   PR2 = 255 → ~977 Hz @ 4 MHz, prescaler 1:4            */
    PR2 = 255;

    /* Step 3 – Clear Timer2 */
    TMR2 = 0;

    /* Step 4 – Set Timer2 prescaler to 1:4, enable Timer2 */
    CLR_BIT(T2CON, T2CON_T2CKPS1);
    SET_BIT(T2CON, T2CON_T2CKPS0); /* bits 1:0 = 01 → 1:4  */
    SET_BIT(T2CON, T2CON_TMR2ON);

    /* Step 5 – Configure CCP1 for PWM mode (CCP1M = 1100) */
    SET_BIT(CCP1CON, CCP1CON_CCP1M3);
    SET_BIT(CCP1CON, CCP1CON_CCP1M2);
    CLR_BIT(CCP1CON, 1);
    CLR_BIT(CCP1CON, 0);

    /* Default 0 % duty */
    PWM_SetDuty(0);
}

void PWM_SetDuty(u8 duty_percent)
{
    u16 duty_10bit;

    /* Clamp to 100 */
    if (duty_percent > 100)
        duty_percent = 100;

    /*
     * 10-bit duty cycle value:
     *   duty_10bit = duty_percent * (PR2 + 1) * 4 / 100
     *   With PR2 = 255 → max = 1023
     */
    duty_10bit = ((u16)duty_percent * 1023) / 100;

    /* Upper 8 bits → CCPR1L */
    CCPR1L = (u8)(duty_10bit >> 2);

    /* Lower 2 bits → CCP1CON bits 5:4 */
    if (duty_10bit & 0x01)
        SET_BIT(CCP1CON, CCP1CON_DC1B0);
    else
        CLR_BIT(CCP1CON, CCP1CON_DC1B0);

    if (duty_10bit & 0x02)
        SET_BIT(CCP1CON, CCP1CON_DC1B1);
    else
        CLR_BIT(CCP1CON, CCP1CON_DC1B1);
}

void PWM_Stop(void)
{
    /* Clear CCP1CON mode bits → CCP module off */
    CLR_BIT(CCP1CON, CCP1CON_CCP1M3);
    CLR_BIT(CCP1CON, CCP1CON_CCP1M2);
    CLR_BIT(CCP1CON, 1);
    CLR_BIT(CCP1CON, 0);
}