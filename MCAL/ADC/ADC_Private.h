#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define ADCON0      (*((volatile u8*)0x1F))
#define ADCON1      (*((volatile u8*)0x9F))
#define ADRESH      (*((volatile u8*)0x1E))
#define ADRESL      (*((volatile u8*)0x9E))

#define ADON_BIT    0
#define GO_DONE_BIT 2
#define CHS0_BIT    3

#endif
