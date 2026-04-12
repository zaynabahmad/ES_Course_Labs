#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* ADC Result High Register */
#define ADRESH   (*((volatile u8*)0x1E))

/* ADC Result Low Register */
#define ADRESL   (*((volatile u8*)0x9E))

/* ADC Control Register 0 */
#define ADCON0   (*((volatile u8*)0x1F))

/* ADC Control Register 1 */
#define ADCON1   (*((volatile u8*)0x9F))

/* TRISA Register */
#define TRISA    (*((volatile u8*)0x85))

#endif