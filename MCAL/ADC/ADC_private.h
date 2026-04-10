#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* PIC16F877A ADC Register Definitions */
#define ADCON0_REG   (*((volatile u8*)0x1F))
#define ADCON1_REG   (*((volatile u8*)0x9F))
#define ADRESH_REG   (*((volatile u8*)0x1E))
#define ADRESL_REG   (*((volatile u8*)0x9E))
#define TRISA_REG    (*((volatile u8*)0x85))
#define PORTA_REG    (*((volatile u8*)0x05))

/* ADCON0 Bit Positions */
#define ADON_BIT     0
#define GO_nDONE_BIT 2

/* Bit Mask */
#define ADC_CHANNEL_MASK     0x38

#endif
