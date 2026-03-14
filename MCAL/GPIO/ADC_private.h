#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADCON0    (*((volatile u8*)0x1F))
#define ADCON1    (*((volatile u8*)0x9F))
#define ADRESH    (*((volatile u8*)0x1E))
#define ADRESL    (*((volatile u8*)0x9E))

/* ADCON0 Bits */
#define ADON_BIT    0
#define GO_DONE_BIT 2

#endif