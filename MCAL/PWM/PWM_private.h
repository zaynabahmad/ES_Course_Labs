#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

/* CCP1 Control Register */
#define CCP1CON  (*(volatile unsigned char*)0x17)

#define CCPR1L   (*(volatile unsigned char*)0x15)
#define CCPR1H   (*(volatile unsigned char*)0x16)   /* read-only slave */

/* Timer2 Control Register */
#define T2CON    (*(volatile unsigned char*)0x12)

/* Timer2 Period Register */
#define PR2      (*(volatile unsigned char*)0x92)

/* Timer2 Count Register */
#define TMR2     (*(volatile unsigned char*)0x11)

/* Data direction for Port C (RC2 = CCP1 output pin) */
#define TRISC    (*(volatile unsigned char*)0x87)

/* ---- CCP1CON bit positions ---- */
#define CCP1CON_CCP1M0   0    /* Mode select bit 0          */
#define CCP1CON_CCP1M1   1    /* Mode select bit 1          */
#define CCP1CON_CCP1M2   2    /* Mode select bit 2          */
#define CCP1CON_CCP1M3   3    /* Mode select bit 3          */
#define CCP1CON_DC1B0    4    /* LSb of duty cycle (bit 0)  */
#define CCP1CON_DC1B1    5    /* LSb of duty cycle (bit 1)  */

/* PWM mode value: CCP1M3:CCP1M0 = 1100 */
#define PWM_MODE_VALUE   0x0Cu

/* ---- T2CON bit positions ---- */
#define T2CON_TMR2ON     2    /* Timer2 ON bit              */
#define T2CON_T2CKPS0    0    /* Prescaler select bit 0     */
#define T2CON_T2CKPS1    1    /* Prescaler select bit 1     */

/* ---- T2CON prescaler options (bits 1:0) ---- */
#define T2_PRESCALE_1    0x00u   /* 00 = 1:1   */
#define T2_PRESCALE_4    0x01u   /* 01 = 1:4   */
#define T2_PRESCALE_16   0x02u   /* 10 = 1:16  */

#define PWM_PR2_VALUE      124u   /* 4 kHz @ Fosc=8MHz, pre=4 */

#define PWM_OUTPUT_PIN     2u

#define PWM_MAX_DUTY       255u

#endif /* PWM_PRIVATE_H */