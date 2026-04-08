#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/* * ADC Port Configuration Control
 * 0x00 = All channels analog, Vref+ = VDD, Vref- = VSS
 * 0x02 = AN0-AN4 analog, Vref+ = VDD, Vref- = VSS
 * Adjust based on your hardware needs (refer to ADCON1 PCFG bits).
 */
#define ADC_PORT_CONFIG      ADC_ALL_ANALOG

/*
 * ADC Result Justification
 * Use ADC_RIGHT_JUSTIFIED for easy 10-bit reading into a u16 variable.
 */
#define ADC_JUSTIFICATION    ADC_RIGHT_JUSTIFIED

#endif