#include "PWM_Interface.h"
#include "PWM_Private.h"
#include "../GPIO/GPIO_interface.h"

void PWM1_Init(void)
{
    /* Set RC2 as output for CCP1 module */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN2, GPIO_OUTPUT);

    /* Set PR2 for approx 4kHz PWM frequency (assuming 4MHz Fosc) */
    PR2 = 62;

    /* Configure CCP1 for PWM mode (bits 3:2 = 11) */
    CCP1CON = 0x0C;

    /* Set Timer2 prescaler to 16 and turn Timer2 on */
    T2CON = 0x06;
}

void PWM1_SetDutyCycle(u8 DutyCycle_Percent)
{
    if (DutyCycle_Percent > 100) DutyCycle_Percent = 100;

    /* Calculate 10-bit value based on PR2 */
    u16 PWM_Value = (u16)((DutyCycle_Percent * (PR2 + 1) * 4) / 100);

    /* 8 MSB go to CCPR1L */
    CCPR1L = (u8)(PWM_Value >> 2);

    /* 2 LSB go to CCP1CON bits 4 and 5 */
    CCP1CON &= 0xCF;
    CCP1CON |= ((PWM_Value & 0x03) << 4);
}
