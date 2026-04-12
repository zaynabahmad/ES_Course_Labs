#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#define CCP1CON_REG    *((volatile unsigned char *)0x17)
#define CCPR1L_REG     *((volatile unsigned char *)0x15)
#define T2CON_REG      *((volatile unsigned char *)0x12)
#define PR2_REG        *((volatile unsigned char *)0x92)
#define TRISC_REG      *((volatile unsigned char *)0x87)

/* CCP1CON mode bits */
#define CCP1M3_BIT     3
#define CCP1M2_BIT     2

/* DC1B bits position in CCP1CON (bits 5:4) */
#define DC1B_SHIFT     4

#endif
