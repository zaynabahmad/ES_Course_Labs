#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADCON0 (*(volatile unsigned char*)0x1F)
#define ADCON1 (*(volatile unsigned char*)0x9F)

#define ADRESH (*(volatile unsigned char*)0x1E)
#define ADRESL (*(volatile unsigned char*)0x9E)

#endif