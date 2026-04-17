#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define ADCON0  (*((volatile u8*)0x1F))
#define ADCON1  (*((volatile u8*)0x9F))
#define ADRESH  (*((volatile u8*)0x1E))
#define ADRESL  (*((volatile u8*)0x9E))

/* ADCON0 bits */
#define ADCS1   7
#define ADCS0   6
#define CHS2    5
#define CHS1    4
#define CHS0    3
#define GO_DONE 2
#define ADON    0

/* ADCON1 bits */
#define ADFM    7

#endif
