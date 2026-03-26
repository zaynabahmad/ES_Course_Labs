#ifndef ADC_H
#define ADC_H

#include "../../SERVICES/Std_Types.h"

/* Function to initialize the ADC module */
void M_ADC_voidInit(void);

/* Function to read a specific channel (0-7) and return 10-bit result */
u16 M_ADC_u16ReadChannel(u8 copy_u8Channel);

#endif