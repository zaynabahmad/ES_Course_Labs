#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#define TMR0        (*((volatile u8*)0x01))
#define OPTION_REG  (*((volatile u8*)0x81))
#define INTCON      (*((volatile u8*)0x0B))

/* OPTION_REG bit positions */
#define T0CS   5   /* Clock Source Select: 1=external, 0=internal */
#define T0SE   4   /* Source Edge Select:  1=falling, 0=rising    */
#define PSA    3   /* Prescaler Assignment: 1=WDT, 0=Timer0        */
#define PS2    2   /* Prescaler Rate Select bit 2 */
#define PS1    1   /* Prescaler Rate Select bit 1 */
#define PS0    0   /* Prescaler Rate Select bit 0 */

/* INTCON bit positions */
#define GIE    7   /* Global Interrupt Enable */
#define T0IE   5   /* Timer0 Overflow Interrupt Enable */
#define T0IF   2   /* Timer0 Overflow Interrupt Flag   */

#endif
