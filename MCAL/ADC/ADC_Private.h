#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"


#define ADCON0_REG          (*(volatile u8*)0x1F)
#define ADRESH_REG          (*(volatile u8*)0x1E)


#define ADCON1_REG          (*(volatile u8*)0x9F)
#define ADRESL_REG          (*(volatile u8*)0x9E)


#define ADCS1               7
#define ADCS0               6
#define CHS2                5
#define CHS1                4
#define CHS0                3
#define GO_DONE             2
#define ADON                0
#define ADFM                7
#define ADCS2               6

#endif