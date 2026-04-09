#include "PWM_Interface.h"

/* =========================================================
   PWM_Init
   - Configures RC2 as output (CCP1 pin)
   - Sets Timer2 prescaler and period (PR2)
   - Sets CCP1CON to PWM mode
   - Starts with 0% duty cycle
   - Timer2 is NOT started; call PWM_Start() to begin output
========================================================= */

void PWM_Init(void)
{
    /* Configure CCP1 pin (RC2) as output via GPIO layer */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN2, GPIO_OUTPUT);

    /* Set Timer2 period register for desired frequency */
    PR2 = PWM_PR2_VALUE;

    /* Zero the duty cycle initially */
    CCPR1L = 0;
    CLR_BIT(CCP1CON, DC1B0_BIT);
    CLR_BIT(CCP1CON, DC1B1_BIT);

    /* Set CCP1 to PWM mode (bits 3:0 = 0b1100) */
    CCP1CON = (CCP1CON & 0xF0) | CCP1_PWM_MODE;

    /* Configure T2CON: set prescaler, timer off until PWM_Start() */
    T2CON = (T2CON & 0xF8) | (PWM_T2_PRESCALER & 0x03);
    CLR_BIT(T2CON, TMR2ON_BIT);
}

/* =========================================================
   PWM_SetDutyCycle
   duty: 0–100 (percentage)
   10-bit duty count = (PR2+1) * 4 * duty / 100
========================================================= */

void PWM_SetDutyCycle(u8 duty)
{
    u16 duty_count;

    if(duty > 100) { duty = 100; }

    duty_count = (u16)(((u16)(PR2 + 1U) * 4U * (u16)duty) / 100U);

    /* Upper 8 bits → CCPR1L */
    CCPR1L = (u8)(duty_count >> 2);

    /* Lower 2 bits → CCP1CON<5:4> */
    if(GET_BIT(duty_count, 0)) { SET_BIT(CCP1CON, DC1B0_BIT); }
    else                        { CLR_BIT(CCP1CON, DC1B0_BIT); }

    if(GET_BIT(duty_count, 1)) { SET_BIT(CCP1CON, DC1B1_BIT); }
    else                        { CLR_BIT(CCP1CON, DC1B1_BIT); }
}

/* =========================================================
   PWM_Start — enable Timer2
========================================================= */

void PWM_Start(void)
{
    SET_BIT(T2CON, TMR2ON_BIT);
}

/* =========================================================
   PWM_Stop — disable Timer2
========================================================= */

void PWM_Stop(void)
{
    CLR_BIT(T2CON, TMR2ON_BIT);
}