#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADMUX   (*(volatile unsigned char*)0x27)
#define ADCSRA  (*(volatile unsigned char*)0x26)
#define ADCL    (*(volatile unsigned char*)0x24)
#define ADCH    (*(volatile unsigned char*)0x25)

#endif