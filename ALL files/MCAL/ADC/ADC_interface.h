#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/*
 * Function: ADC_Init
 * ------------------
 * Initializes ADC module
 */
void ADC_Init(void);


/*
 * Function: ADC_Read
 * ------------------
 * Reads analog value from given channel (0 ? 7)
 * Returns 10-bit result (0 ? 1023)
 */
u16 ADC_Read(u8 Channel);

#endif