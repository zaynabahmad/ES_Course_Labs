#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* TMR0 register — Bank 0, address 0x01 */
#define TMR0               (*((volatile u8*)0x01))

/* INTCON register — address 0x0B */
#define INTCON             (*((volatile u8*)0x0B))
#define INTCON_GIE         7    /* Global Interrupt Enable          */
#define INTCON_T0IE        5    /* Timer0 Overflow Interrupt Enable  */
#define INTCON_T0IF        2    /* Timer0 Overflow Interrupt Flag    */

/* OPTION_REG register — Bank 1, address 0x81 */
#define OPTION_REG         (*((volatile u8*)0x81))
#define OPTION_T0CS        5    /* 0 = internal Fosc/4 clock source  */
#define OPTION_PSA         3    /* 0 = prescaler assigned to Timer0  */

#endif
