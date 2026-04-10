#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Register Definitions for PIC16F877A - ADC */

/* ADC Result Registers */
#define ADRESH (*((volatile u8 *)0x1E)) /* ADC Result High Byte */
#define ADRESL (*((volatile u8 *)0x1F)) /* ADC Result Low Byte */

/* ADC Control Registers */
#define ADCON0 (*((volatile u8 *)0x1F)) /* ADC Control Register 0 */
#define ADCON1 (*((volatile u8 *)0x9F)) /* ADC Control Register 1 */

/* ADCON0 Bit Definitions */
#define ADON 0    /* ADC Module Enable Bit */
#define GO_DONE 2 /* A/D Conversion Status Bit */
#define CHS0 3    /* Analog Channel Select Bits */
#define CHS1 4
#define CHS2 5
#define ADCS0 6 /* A/D Conversion Clock Select Bits */
#define ADCS1 7

/* ADCON1 Bit Definitions */
#define PCFG0 0 /* A/D Port Configuration Control Bits */
#define PCFG1 1
#define PCFG2 2
#define PCFG3 3
#define VCFG0 4 /* Voltage Reference Configuration Bits */
#define VCFG1 5

/* Port E Register */
#define PORTE (*((volatile u8 *)0x09))
#define TRISE (*((volatile u8 *)0x89))

/* Interrupt Registers */
#define PIR1 (*((volatile u8 *)0x0C))
#define PIE1 (*((volatile u8 *)0x8C))
#define ADIF 6 /* ADC Interrupt Flag */
#define ADIE 6 /* ADC Interrupt Enable */

#endif
