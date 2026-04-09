#ifndef ADC_PRV_H
#define ADC_PRV_H

#include "D:/ES-Project-Lab/SERVICES/std_types.h"

/* PIC16F877A-style register addresses */
#define ADCON0_REG      (*((volatile u8*)0x1F))
#define ADCON1_REG      (*((volatile u8*)0x9F))
#define ADRESH_REG      (*((volatile u8*)0x1E))
#define ADRESL_REG      (*((volatile u8*)0x9E))

/* ADCON0 bits */
#define ADON_BIT        0
#define GO_DONE_BIT     2
#define CHS0_BIT        3
#define CHS1_BIT        4
#define CHS2_BIT        5
#define ADCS0_BIT       6
#define ADCS1_BIT       7

/* ADCON1 bits */
#define ADFM_BIT        7
#define ADCS2_BIT       6

#endif