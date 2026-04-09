#include "PWM_private.h"
#include "PWM_config.h"
#include "PWM_interface.h"
#include "../GPIO/GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"

void PWM_Init(void)
{
    /* RC2/CCP1 pin must be output — configure via GPIO */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN2, GPIO_OUTPUT);

    /* Set PWM period via PR2 */
    PR2 = PWM_PR2_VALUE;

    /* CCP1CON: set PWM mode — CCP1M<3:0> = 1100 */
    CLR_BIT(CCP1CON, CCP1M0_BIT);
    CLR_BIT(CCP1CON, CCP1M1_BIT);
    SET_BIT(CCP1CON, CCP1M2_BIT);
    SET_BIT(CCP1CON, CCP1M3_BIT);

    /* Clear duty cycle initially */
    CCPR1L = 0;
    CLR_BIT(CCP1CON, DC1B0_BIT);
    CLR_BIT(CCP1CON, DC1B1_BIT);

    /* Configure Timer2 prescaler and start Timer2 */
    T2CON = (PWM_T2_PRESCALER & 0x03);
    SET_BIT(T2CON, TMR2ON_BIT);
}

/*
 * DutyCycle: 0–1000 (per-mille)
 * 10-bit duty-cycle value = DutyCycle * (PR2 + 1) * 4 / 1000
 * CCPR1L holds the 8 MSBs; DC1B<1:0> in CCP1CON hold the 2 LSBs.
 */
void PWM_SetDutyCycle(u16 DutyCycle)
{
    u16 dc10bit;
    u8  dc_msb;
    u8  dc_lsb;

    if (DutyCycle > 1000)
        DutyCycle = 1000;

    /* 10-bit duty-cycle count */
    dc10bit = (u16)((u32)DutyCycle * ((u16)PWM_PR2_VALUE + 1) * 4 / 1000);

    dc_msb = (u8)(dc10bit >> 2);          /* bits 9:2 → CCPR1L */
    dc_lsb = (u8)(dc10bit & 0x03);        /* bits 1:0 → DC1B<1:0> */

    CCPR1L = dc_msb;

    if (dc_lsb & 0x01)
        SET_BIT(CCP1CON, DC1B0_BIT);
    else
        CLR_BIT(CCP1CON, DC1B0_BIT);

    if (dc_lsb & 0x02)
        SET_BIT(CCP1CON, DC1B1_BIT);
    else
        CLR_BIT(CCP1CON, DC1B1_BIT);
}

void PWM_Stop(void)
{
    /* Clear CCP1M bits to disable PWM output */
    CLR_BIT(CCP1CON, CCP1M0_BIT);
    CLR_BIT(CCP1CON, CCP1M1_BIT);
    CLR_BIT(CCP1CON, CCP1M2_BIT);
    CLR_BIT(CCP1CON, CCP1M3_BIT);

    /* Stop Timer2 */
    CLR_BIT(T2CON, TMR2ON_BIT);

    GPIO_SetPinValue(GPIO_PORTC, GPIO_PIN2, GPIO_LOW);
}
