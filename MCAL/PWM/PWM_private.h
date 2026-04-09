#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

/* --- PWM (CCP1) Registers Memory Mapping --- */

/** * CCP1CON: CCP1 Control Register
 * Used to set PWM mode and the 2 least significant bits of the duty cycle.
 */
#define CCP1CON         *((volatile u8*)0x17)

/** * CCPR1L: CCP1 Period Register (High Byte)
 * Used to set the 8 most significant bits of the 10-bit duty cycle.
 */
#define CCPR1L          *((volatile u8*)0x15)

/* --- Timer2 Registers (Required for PWM) --- */

/** * PR2: Timer2 Period Register
 * This register determines the frequency of the PWM signal.
 */
#define PR2             *((volatile u8*)0x92)

/** * T2CON: Timer2 Control Register
 * Used to enable Timer2 and set the prescaler (1, 4, or 16).
 */
#define T2CON           *((volatile u8*)0x12)

/* --- GPIO Control for PWM Pin (RC2) --- */
#define TRISC           *((volatile u8*)0x87)
#define PORTC           *((volatile u8*)0x07)

/* --- Bit Definitions for Control Registers --- */

/* CCP1CON Bit Definitions */
#define CCP1M3          3   /* CCP1 Mode Select bit 3 */
#define CCP1M2          2   /* CCP1 Mode Select bit 2 */
#define CCP1M1          1   /* CCP1 Mode Select bit 1 */
#define CCP1M0          0   /* CCP1 Mode Select bit 0 */
#define CCP1X           5   /* PWM Duty Cycle bit 1 */
#define CCP1Y           4   /* PWM Duty Cycle bit 0 */

/* T2CON Bit Definitions */
#define TMR2ON          2   /* Timer2 On bit */
#define T2CKPS1         1   /* Timer2 Clock Prescale Select bit 1 */
#define T2CKPS0         0   /* Timer2 Clock Prescale Select bit 0 */

#endif