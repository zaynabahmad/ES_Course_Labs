#ifndef LM35_H
#define LM35_H

#include "../../MCAL/ADC/ADC.h"

/* Returns temperature in Celsius */
f32 H_LM35_f32ReadTemp(u8 copy_u8ADCChannel);

#endif