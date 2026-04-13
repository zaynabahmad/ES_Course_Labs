#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define ADCON0    (*((volatile u8*)0x1F))
#define ADCON1    (*((volatile u8*)0x9F))
#define ADRESH    (*((volatile u8*)0x1E))
#define ADRESL    (*((volatile u8*)0x9E))
#define INTCON    (*((volatile u8*)0x0B))
#define PIE1      (*((volatile u8*)0x8C))
#define PIR1      (*((volatile u8*)0x0C))

#define ADON      0
#define GO_DONE   2
#define CHS0      3
#define CHS1      4
#define CHS2      5
#define ADCS0     6
#define ADCS1     7

#define PCFG0     0
#define PCFG1     1
#define PCFG2     2
#define PCFG3     3
#define VCFG0     4
#define VCFG1     5
#define ADFM      7

#define ADIE      6
#define ADIF      6

#define ADCS_FOSC_2     0
#define ADCS_FOSC_8     1
#define ADCS_FOSC_32    2
#define ADCS_FRC        3

#endif
