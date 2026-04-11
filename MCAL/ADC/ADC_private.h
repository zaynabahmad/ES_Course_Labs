#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* PIC16F877A Registers */
#define ADRESH   (*((volatile u8*)0x1E))
#define ADRESL   (*((volatile u8*)0x9E))
#define ADCON0   (*((volatile u8*)0x1F))
#define ADCON1   (*((volatile u8*)0x9F))
#define PIR1     (*((volatile u8*)0x0C))
#define PIE1     (*((volatile u8*)0x8C))
#define INTCON   (*((volatile u8*)0x0B))

#define TRISA    (*((volatile u8*)0x85))
#define TRISE    (*((volatile u8*)0x89))

/* ADCON0 Bits */
#define ADCS1_BIT     7
#define ADCS0_BIT     6
#define CHS2_BIT      5
#define CHS1_BIT      4
#define CHS0_BIT      3
#define GO_DONE_BIT   2
#define ADON_BIT      0

/* ADCON1 Bits */
#define ADFM_BIT      7

/* Interrupt Bits */
#define ADIF_BIT      6   /* PIR1 */
#define ADIE_BIT      6   /* PIE1 */
#define PEIE_BIT      6   /* INTCON */
#define GIE_BIT       7   /* INTCON */

#endif