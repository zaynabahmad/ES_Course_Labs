#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"


#define ADCON0_REG  (*((volatile u8*)0x1F))
#define ADCON1_REG  (*((volatile u8*)0x9F))
#define ADRESH_REG  (*((volatile u8*)0x1E))
#define ADRESL_REG  (*((volatile u8*)0x9E))

#define GO_DONE_BIT 2
#define ADON_BIT    0

#endif