#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define ADCON0      (*((volatile u8*)0x1F))
#define ADCON1      (*((volatile u8*)0x9F))
#define ADRESH      (*((volatile u8*)0x1E))
#define ADRESL      (*((volatile u8*)0x9E))
#define ADCS1_BIT   7
#define ADCS0_BIT   6
#define CHS2_BIT    5
#define CHS1_BIT    4
#define CHS0_BIT    3
#define GO_DONE_BIT 2
#define ADON_BIT    0
#define ADFM_BIT    7   
#define PCFG3_BIT   3
#define PCFG2_BIT   2
#define PCFG1_BIT   1
#define PCFG0_BIT   0
#define PIR1        (*((volatile u8*)0x0C))
#define PIE1        (*((volatile u8*)0x8C))
#define ADIF_BIT    6
#define ADIE_BIT    6

#endif
