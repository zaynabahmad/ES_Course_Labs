/*
 * pwm_private.h
 * MCAL - PWM (CCP1/CCP2) Register Definitions for PIC16F877A
 */

#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

/* =====================================================
 * CCP1 Registers
 * ===================================================== */
#define CCP1CON_REG    (*((volatile unsigned char*)0x17))
#define CCPR1L_REG     (*((volatile unsigned char*)0x15))
#define CCPR1H_REG     (*((volatile unsigned char*)0x16))

/* =====================================================
 * CCP2 Registers
 * ===================================================== */
#define CCP2CON_REG    (*((volatile unsigned char*)0x1D))
#define CCPR2L_REG     (*((volatile unsigned char*)0x1B))
#define CCPR2H_REG     (*((volatile unsigned char*)0x1C))

/* =====================================================
 * Timer2 Registers (Required for PWM)
 * ===================================================== */
#define T2CON_REG      (*((volatile unsigned char*)0x12))
#define TMR2_REG       (*((volatile unsigned char*)0x11))
#define PR2_REG        (*((volatile unsigned char*)0x92))  /* Bank 1 */

/* T2CON Bits */
#define T2CON_TMR2ON   2    /* Timer2 ON bit */
#define T2CON_T2CKPS1  1    /* Timer2 prescaler bit 1 */
#define T2CON_T2CKPS0  0    /* Timer2 prescaler bit 0 */

/*
 * CCPxCON Mode bits (CCP1M3:CCP1M0)
 * 1100 = PWM mode
 * 1101 = PWM mode (same)
 * 1110 = PWM mode (same)
 * 1111 = PWM mode (same)
 */
#define CCP_PWM_MODE   0x0C   /* 0b00001100 */

/* DCxB1:DCxB0 in CCPxCON bits 5:4 - LSBs of duty cycle */
#define CCP_DC_B1_POS  5
#define CCP_DC_B0_POS  4

/* TRISC bits for CCP pins */
#define TRISC_REG      (*((volatile unsigned char*)0x87))

#endif /* PWM_PRIVATE_H */
