 #ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADMUX  *((volatile u8*)0x27)
#define ADCSRA *((volatile u8*)0x26)
#define ADCL   *((volatile u8*)0x24)
#define ADCH   *((volatile u8*)0x25)

// Bits
#define ADEN  7
#define ADSC  6
#define ADIF  4

#endif