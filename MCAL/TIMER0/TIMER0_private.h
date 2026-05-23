#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

/* Timer0 count register */
#define TMR0        (*(volatile unsigned char*)0x01)

/* Option register — controls Timer0 clock, edge, prescaler */
#define OPTION_REG  (*(volatile unsigned char*)0x81)

/* Interrupt Control Register */
#define INTCON      (*(volatile unsigned char*)0x0B)

/* ---- OPTION_REG bit positions ---- */
#define OPTION_T0CS     5    /* Clock source: 0=internal, 1=T0CKI  */
#define OPTION_T0SE     4    /* Source edge:  0=rising, 1=falling   */
#define OPTION_PSA      3    /* Prescaler:    0=Timer0, 1=WDT       */
#define OPTION_PS2      2    /* Prescaler rate select bit 2         */
#define OPTION_PS1      1    /* Prescaler rate select bit 1         */
#define OPTION_PS0      0    /* Prescaler rate select bit 0         */

/* ---- INTCON bit positions ---- */
#define INTCON_GIE      7    /* Global Interrupt Enable             */
#define INTCON_T0IE     5    /* Timer0 Overflow Interrupt Enable    */
#define INTCON_T0IF     2    /* Timer0 Overflow Interrupt Flag      */

#define TIMER0_PRESCALE_2     0x00u   /* 000 → 1:2   */
#define TIMER0_PRESCALE_4     0x01u   /* 001 → 1:4   */
#define TIMER0_PRESCALE_8     0x02u   /* 010 → 1:8   */
#define TIMER0_PRESCALE_16    0x03u   /* 011 → 1:16  */
#define TIMER0_PRESCALE_32    0x04u   /* 100 → 1:32  */
#define TIMER0_PRESCALE_64    0x05u   /* 101 → 1:64  */
#define TIMER0_PRESCALE_128   0x06u   /* 110 → 1:128 */
#define TIMER0_PRESCALE_256   0x07u   /* 111 → 1:256 */

#define TIMER0_PRELOAD_1MS    6u

/* Prescaler used with the preload above */
#define TIMER0_PRESCALE_1MS   TIMER0_PRESCALE_8

/* Maximum value of an 8-bit timer */
#define TIMER0_MAX_COUNT      255u

#endif /* TIMER0_PRIVATE_H */