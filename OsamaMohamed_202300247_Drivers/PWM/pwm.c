/*
 * pwm.c
 * PWM Driver for PIC16F877A — CCP1 module (RC2)
 */

#include "pwm.h"
#include "../common_macros.h"

/* PR2 value for ~2.5 kHz @ 8MHz, prescaler=4 */
#define PWM_PR2_VALUE   199U

void PWM_CCP1_init(uint8 dutyCycle_percent) {
    /* Step 1: RC2/CCP1 as output */
    TRISCbits.TRISC2 = 0;

    /* Step 2: Set PWM period via PR2 */
    PR2 = PWM_PR2_VALUE;

    /* Step 3: Configure CCP1 for PWM mode (CCP1CON = 0b00001100) */
    CCP1CON = 0x0C;   /* PWM mode, LSBs of duty = 00 initially */

    /* Step 4: Set duty cycle */
    PWM_CCP1_setDuty(dutyCycle_percent);

    /* Step 5: Configure Timer2 — prescaler=4, enable Timer2 */
    T2CON = 0x00;
    T2CONbits.T2CKPS1 = 0;
    T2CONbits.T2CKPS0 = 1;   /* Prescaler = 4 */
    T2CONbits.TMR2ON  = 1;   /* Start Timer2  */
}

void PWM_CCP1_setDuty(uint8 dutyCycle_percent) {
    /* 10-bit duty count = (duty/100) * 4 * (PR2+1) */
    uint16 duty10 = ((uint16)dutyCycle_percent * 4U * (PWM_PR2_VALUE + 1U)) / 100U;

    /* Upper 8 bits -> CCPR1L, lower 2 bits -> CCP1CON<5:4> */
    CCPR1L = (uint8)(duty10 >> 2);
    CCP1CON = (CCP1CON & 0xCF) | (uint8)((duty10 & 0x03) << 4);
}

void PWM_CCP1_stop(void) {
    CCP1CON = 0x00;           /* Disable CCP1 */
    T2CONbits.TMR2ON = 0;    /* Stop Timer2  */
    TRISCbits.TRISC2 = 1;    /* RC2 as input (Hi-Z) */
}
