#ifndef TIMER_0_PRIVATE_H
#define TIMER_0_PRIVATE_H

/* ================= Register Addresses ================= */

#define OPTION_REG   (*((volatile u8*)0x81))
#define INTCON       (*((volatile u8*)0x0B))
#define TMR0         (*((volatile u8*)0x01))

/* ================= OPTION_REG Bits ================= */

#define PS0          0      /* Prescaler bit 0 */
#define PS1          1      /* Prescaler bit 1 */
#define PS2          2      /* Prescaler bit 2 */
#define PSA          3      /* Prescaler Assignment: 0=Timer0, 1=WDT */
#define T0SE         4      /* Source Edge Select */
#define T0CS         5      /* Clock Source: 0=Internal, 1=External */

/* ================= INTCON Bits ================= */

#define T0IF         2      /* Timer0 Overflow Interrupt Flag */
#define T0IE         5      /* Timer0 Overflow Interrupt Enable */
#define GIE_BIT      7
#define PEIE_BIT     6

#endif
