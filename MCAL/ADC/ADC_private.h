#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H
#define ADCON0  (*((volatile u8*)0x80))
#define ADCON1  (*((volatile u8*)0x41))
#define ADRESH   (*((volatile u8*)0x1E))
#define ADRESL   (*((volatile u8*)0x9E))
#define PIR1     (*((volatile u8*)0x0C))
#define PIE1     (*((volatile u8*)0x0D))
#define INTCON    (*((volatile u8*)0x0B))
#endif // ADC_PRIVATE_H