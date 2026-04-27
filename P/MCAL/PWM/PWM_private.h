#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

/* ---- CCP1 registers ---- */
#define CCP1CON_REG *((volatile unsigned char*)0x17)
#define CCPR1L_REG  *((volatile unsigned char*)0x15)

/* ---- Timer2 registers ---- */
#define T2CON_REG   *((volatile unsigned char*)0x12)
#define PR2_REG     *((volatile unsigned char*)0x92)

/* ---- Direction register ---- */
#define TRISC_REG   *((volatile unsigned char*)0x87)

/* ---- CCP1CON bit positions ---- */
#define CCP1M3      3   /* PWM mode select bits */
#define CCP1M2      2

#endif
