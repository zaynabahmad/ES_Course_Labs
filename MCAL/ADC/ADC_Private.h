#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADCON0 (*((volatile u8 *)0x1F))
#define ADCON1 (*((volatile u8 *)0x9F))

#define ADRESH (*((volatile u8 *)0x1E))
#define ADRESL (*((volatile u8 *)0x9E))

#define PIR1 (*((volatile u8 *)0x0C))
#define PIE1 (*((volatile u8 *)0x8C))

#define INTCON (*((volatile u8 *)0x18B))
#define OPTION_REG (*((volatile u8 *)0x181))
#endif
