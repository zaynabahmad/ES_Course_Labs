#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define ADCON0      (*(volatile u8*)0x1F)
#define ADCON1      (*(volatile u8*)0x9F)
#define ADRESH      (*(volatile u8*)0x1E)
#define ADRESL      (*(volatile u8*)0x9E)

#ifndef PIR1
#define PIR1        (*(volatile u8*)0x0C)
#endif

#define ADCS1_BIT   7
#define ADCS0_BIT   6
#define CHS2_BIT    5
#define CHS1_BIT    4
#define CHS0_BIT    3
#define GO_BIT      2
#define ADON_BIT    0

#define ADFM_BIT    7

#define ADIF_BIT    6

#define ADC_CLK_FOSC_2    0x00
#define ADC_CLK_FOSC_8    0x01
#define ADC_CLK_FOSC_32   0x02
#define ADC_CLK_FRC       0x03

#define ADC_CHANNEL_MASK  0x38

#define ADC_ADCON1_ALL_ANALOG   0x80
#define ADC_ADCON1_AN0_ONLY     0x8E

#endif
