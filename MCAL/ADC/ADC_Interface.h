#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

/* Available ADC channels (AN0–AN7) */
#define ADC_CHANNEL_0   0
#define ADC_CHANNEL_1   1
#define ADC_CHANNEL_2   2
#define ADC_CHANNEL_3   3
#define ADC_CHANNEL_4   4
#define ADC_CHANNEL_5   5
#define ADC_CHANNEL_6   6
#define ADC_CHANNEL_7   7

/*
 * Initialize the ADC module.
 * Configures port pins, clock source, and result justification.
 * Turns the ADC on.
 */
void ADC_Init(void);

/*
 * Select the active ADC input channel (0–7).
 */
void ADC_SelectChannel(u8 Channel);

/*
 * Perform a single conversion on the selected channel.
 * Blocks until conversion is complete.
 * Returns the 10-bit result (0–1023).
 */
u16 ADC_Read(u8 Channel);

/* Turn the ADC module off to save power */
void ADC_Disable(void);

#endif