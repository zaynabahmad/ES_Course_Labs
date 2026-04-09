#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* Register Definitions */
#define ADCON0  (*((volatile u8 *)0x1F))
#define ADCON1  (*((volatile u8 *)0x9F))
#define ADRESH  (*((volatile u8 *)0x1E))
#define ADRESL  (*((volatile u8 *)0x9E))

/* ADCON0 Bits */
#define ADON_BIT    0  /* A/D On bit */
#define GO_DONE_BIT 2  /* A/D Conversion Status bit */
#define CHS0_BIT    3  /* Analog Channel Select bits */
#define CHS1_BIT    4
#define CHS2_BIT    5
#define ADCS0_BIT   6  /* A/D Conversion Clock Select bits */
#define ADCS1_BIT   7

/* ADCON1 Bits */
#define PCFG0_BIT   0  /* A/D Port Configuration Control bits */
#define PCFG1_BIT   1
#define PCFG2_BIT   2
#define PCFG3_BIT   3
#define ADFM_BIT    7  /* A/D Result Format Select bit */

#endif