#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* PIC16F877A ADC Registers */
#define ADCON0  (*(volatile u8*)0x1F)
#define ADCON1  (*(volatile u8*)0x9F)
#define ADRESH  (*(volatile u8*)0x1E)
#define ADRESL  (*(volatile u8*)0x9E)

/* ADCON0 Bits */
#define ADON    0
#define GO_DONE 2
#define CHS0    3
#define CHS1    4
#define CHS2    5
#define ADCS0   6
#define ADCS1   7

/* ADCON1 Bits */
#define PCFG0   0
#define PCFG1   1
#define PCFG2   2
#define PCFG3   3
#define ADFM    7

/* ADC Configuration Value for ADCON1 */
/* PCFG = 0000: All 8 channels analog, VREF = VSS and VDD */
#define ADCON1_CONFIG  0x00

#endif
