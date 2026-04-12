#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

/* ================= Register Addresses ================= */

/* Timer2 Registers */
#define T2CON        (*((volatile u8*)0x12))
#define PR2          (*((volatile u8*)0x92))
#define TMR2         (*((volatile u8*)0x11))
#define PIR1         (*((volatile u8*)0x0C))

/* CCP1 Registers */
#define CCP1CON      (*((volatile u8*)0x17))
#define CCPR1L       (*((volatile u8*)0x15))
#define CCPR1H       (*((volatile u8*)0x16))

/* CCP2 Registers */
#define CCP2CON      (*((volatile u8*)0x1D))
#define CCPR2L       (*((volatile u8*)0x1B))
#define CCPR2H       (*((volatile u8*)0x1C))

/* TRISC for CCP pins */
#define TRISC        (*((volatile u8*)0x87))

/* ================= T2CON Bits ================= */

#define T2CKPS0      0      /* Timer2 Prescaler bit 0 */
#define T2CKPS1      1      /* Timer2 Prescaler bit 1 */
#define TMR2ON       2      /* Timer2 On */
#define TOUTPS0      3      /* Postscaler bit 0 */
#define TOUTPS1      4
#define TOUTPS2      5
#define TOUTPS3      6

/* ================= CCPxCON Bits ================= */

#define CCP_MODE0    0
#define CCP_MODE1    1
#define CCP_MODE2    2
#define CCP_MODE3    3
#define DCxB0        4      /* LSBs of duty cycle */
#define DCxB1        5

/* ================= PIR1 Bits ================= */

#define TMR2IF       1

#endif
