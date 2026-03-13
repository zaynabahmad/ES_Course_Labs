#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#include "../../SERVICES/STD_TYPES1.h"

#define STATUS_REG (*((volatile uint8 *)0x03))
#define TMR0 (*((volatile uint8 *)0x01))
#define OPTION_REG (*((volatile uint8 *)0x81))
#define INTCON (*((volatile uint8 *)0x0B))

#define INTCON_T0IF 2 /* Timer0 Overflow Interrupt Flag bit */
#define INTCON_T0IE 5 /* Timer0 Overflow Interrupt Enable bit */
#define INTCON_GIE 7  /* Global Interrupt Enable bit */

#define OPTION_REG_T0CS 5 /* Timer0 Clock Source Select bit (0 = Internal instruction cycle clock) */
#define OPTION_REG_PSA 3  /* Prescaler Assignment bit (0 = Prescaler is assigned to Timer0) */

#endif /* TIMER0_PRIVATE_H */