#ifndef ADC_H
#define ADC_H

#include "std_types.h"
#include "adc_cfg.h"

void   ADC_Init(void);
uint16 ADC_Read(uint8 channel);

#endif