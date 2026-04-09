#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/* 
    Result Format Selection 
    1 = Right justified (Suitable for 10-bit result)
    0 = Left justified
*/
#define ADC_RESULT_FORMAT       1

/*
    Clock Selection (ADCS2:ADCS1:ADCS0)
    0 = FOSC/2
    1 = FOSC/8
    2 = FOSC/32
    3 = FRC (internal RC)
    4 = FOSC/4
    5 = FOSC/16
    6 = FOSC/64
    7 = FRC
*/
#define ADC_CLOCK_SEL           1

/*
    Port Configuration Control (PCFG3:PCFG0)
    0b1110 = AN0 is Analog, others Digital, Vref+ = VDD, Vref- = VSS
    0b0100 = AN0, AN1, AN3 are Analog. Vref+ = VDD, Vref- = VSS
    0b0000 = All Analog (AN0 to AN7)
    (See datasheet for full table)
    Using 0b0000 for standard all-analog usage or user configurable value.
*/
#define ADC_PORT_CONFIG         0b0000

#endif
