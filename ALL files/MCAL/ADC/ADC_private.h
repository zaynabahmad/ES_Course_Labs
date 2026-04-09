#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Registers (PIC16F877A) */

#define ADCON0   (*((volatile u8*)0x1F))
#define ADCON1   (*((volatile u8*)0x9F))

#define ADRESH   (*((volatile u8*)0x1E))
#define ADRESL   (*((volatile u8*)0x9E))

/* Bits */
#define ADON     0
#define GO_DONE  2

#endif