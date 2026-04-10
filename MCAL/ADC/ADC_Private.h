#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADCON0     *((volatile u8*)0x1F)
#define ADCON1     *((volatile u8*)0x9F)
#define ADRESH     *((volatile u8*)0x1E)
#define ADRESL     *((volatile u8*)0x9E)
#define TRISA      *((volatile u8*)0x85)

#define GO_DONE    2
#define ADON       0

#endif