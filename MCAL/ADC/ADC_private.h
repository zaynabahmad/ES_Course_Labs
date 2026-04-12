#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADCON0_REG    *((volatile unsigned char *)0x1F)
#define ADCON1_REG    *((volatile unsigned char *)0x9F)
#define ADRESH_REG    *((volatile unsigned char *)0x1E)
#define ADRESL_REG    *((volatile unsigned char *)0x9E)
#define TRISA_REG     *((volatile unsigned char *)0x85)

/* ADCON0 bits */
#define ADON_BIT      0
#define GO_DONE_BIT   2

/* channel selection mask */
#define CHS_MASK      0b11000101

#endif
