#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H



//                ADCON0 (ADC Control Register 0)

#define ADCS1   7   // ADC Clock Select
#define ADCS0   6

#define CHS2    5   // Channel Select
#define CHS1    4
#define CHS0    3

#define GO_DONE 2   // Start Conversion / Conversion Status

// bit 1 unused

#define ADON    0   // ADC Enable



//                ADCON1 (ADC Control Register 1)

#define ADFM 7      // Result Format (1 = Right Justified)

// bits 6-4 unused

#define PCFG3 3     // Analog/Digital Config
#define PCFG2 2
#define PCFG1 1
#define PCFG0 0


#endif // ADC_PRIVATE_H