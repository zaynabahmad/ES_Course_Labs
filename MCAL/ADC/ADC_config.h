#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/* * Port Configuration (PCFG bits in ADCON1)
 * 0x0E -> AN0 is Analog, rest Digital
 * 0x04 -> AN0, AN1, AN3 are Analog
 * 0x00 -> All AN0-AN7 are Analog
 * 0x06 -> All Digital
 */
#define ADC_PORT_CONFIG  0x0E

#endif /* ADC_CONFIG_H */