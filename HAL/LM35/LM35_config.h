#ifndef LM35_CONFIG_H
#define LM35_CONFIG_H

/* Microcontroller ADC Operating Voltage in milliVolts (5V = 5000mV) */
#define LM35_VREF_MV          5000.0

/* ADC Maximum Steps (10-bit ADC = 1024) */
#define LM35_ADC_MAX_STEPS    1024.0

/* LM35 Sensor Step (LM35 gives 10mV per degree Celsius) */
#define LM35_MV_PER_CELSIUS   10.0

#endif /* LM35_CONFIG_H */