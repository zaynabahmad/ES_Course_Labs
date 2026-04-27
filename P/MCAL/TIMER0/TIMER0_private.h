#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

/* ---- Registers ---- */
#define TMR0_REG    *((volatile unsigned char*)0x01)
#define INTCON_REG  *((volatile unsigned char*)0x0B)
#define OPTION_REG  *((volatile unsigned char*)0x81)

/* ---- INTCON bit positions ---- */
#define GIE     7   /* Global interrupt enable  */
#define TMR0IE  5   /* Timer0 interrupt enable  */
#define TMR0IF  2   /* Timer0 overflow flag     */

/* ---- OPTION_REG bit positions ---- */
#define T0CS    5   /* Clock source: 0=internal */
#define PSA     3   /* Prescaler assign: 0=TMR0 */
#define PS2     2   /* Prescaler select bits    */
#define PS1     1
#define PS0     0

/* ---- INTCON bit positions (shared with EXTI) ---- */
#define INTF    1   /* External INT flag        */

#endif
