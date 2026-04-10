#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/* ADC reference in millivolts (VDD = 5V) */
#define ADC_REF_MV           5000U
#define ADC_MAX_VALUE        1023U

/* ADCON1 configuration for PIC16F877A:
   - Right justify result
   - Vref = VDD
   - AN0..AN3 analog, others digital */
#define ADCON1_CONFIG        0x80

/* ADC conversion settle time */
#define ADC_CONVERSION_DELAY_MS 2U

#endif