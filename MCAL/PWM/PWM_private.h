#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

/* CCP1 Registers */
#define CCP1CON *((volatile u8*)0x17)
#define CCPR1L  *((volatile u8*)0x15)

/* Timer2 Registers (Required for PWM) */
#define T2CON   *((volatile u8*)0x12)
#define PR2     *((volatile u8*)0x92)

/* CCP1CON Bits */
#define CCP1CON_CCP1M2  2
#define CCP1CON_CCP1M3  3

/* T2CON Bits */
#define T2CON_TMR2ON    2

#endif /* PWM_PRIVATE_H */
