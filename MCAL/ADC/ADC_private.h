#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* ADC Registers for PIC16F877A */
#define ADCON0      (*((volatile uint8*)0x1F))
#define ADCON1      (*((volatile uint8*)0x9F))
#define ADRESH      (*((volatile uint8*)0x1E))
#define ADRESL      (*((volatile uint8*)0x9E))

/* ADCON0 Bits */
#define ADON_BIT    0
#define GO_DONE_BIT 2

#endif