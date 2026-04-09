#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/types.h"

#define ADCON0_REG      (*((volatile u8*)0x1F))
#define ADCON1_REG      (*((volatile u8*)0x9F))
#define ADRESH_REG      (*((volatile u8*)0x1E))
#define ADRESL_REG      (*((volatile u8*)0x9E))
#define TRISA_REG       (*((volatile u8*)0x85))

/* Bits */
#define ADON    0
#define GO_DONE 2

#endif