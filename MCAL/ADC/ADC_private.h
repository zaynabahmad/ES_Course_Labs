#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* ------- Register Definitions ------- */
#define ADRESH (*((volatile u8 *)0x1E))
#define ADRESL (*((volatile u8 *)0x9E))
#define ADCON0 (*((volatile u8 *)0x1F))
#define ADCON1 (*((volatile u8 *)0x9F))
#define TRISA (*((volatile u8 *)0x85))

/* ------- ADCON0 Bits ------- */
#define ADCON0_ADON 0    /* ADC Enable            */
#define ADCON0_GO_DONE 2 /* Start conversion      */
#define ADCON0_CHS0 3    /* Channel select bit 0  */
#define ADCON0_CHS1 4    /* Channel select bit 1  */
#define ADCON0_CHS2 5    /* Channel select bit 2  */
#define ADCON0_ADCS0 6   /* Clock select bit 0    */
#define ADCON0_ADCS1 7   /* Clock select bit 1    */

/* ------- ADCON1 Bits ------- */
#define ADCON1_ADFM 7 /* Result format: 1=right-justified */
#define ADCON1_PCFG0 0
#define ADCON1_PCFG1 1
#define ADCON1_PCFG2 2
#define ADCON1_PCFG3 3

#endif