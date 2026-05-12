#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#define CCP1CON  (*((volatile u8*)0x17))
#define CCPR1L   (*((volatile u8*)0x15))
#define T2CON    (*((volatile u8*)0x12))
#define PR2      (*((volatile u8*)0x92))
#define TRISC    (*((volatile u8*)0x87))

/* CCP1CON bit positions */
#define DC1B1    5   /* PWM duty cycle LSb bit 1 */
#define DC1B0    4   /* PWM duty cycle LSb bit 0 */
#define CCP1M3   3   /* CCP1 mode select bit 3   */
#define CCP1M2   2   /* CCP1 mode select bit 2   */
#define CCP1M1   1   /* CCP1 mode select bit 1   */
#define CCP1M0   0   /* CCP1 mode select bit 0   */

/* T2CON bit positions */
#define TMR2ON   2   /* Timer2 on bit    */
#define T2CKPS1  1   /* Prescaler bit 1  */
#define T2CKPS0  0   /* Prescaler bit 0  */

#endif
