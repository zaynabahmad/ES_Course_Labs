#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

#include "../../SERVICES/STD_TYPES.h"

/* ADC Configuration */
#define ADC_REFERENCE_MODE ADC_VREF_VSS_VDD /* VSS to VDD reference */
#define ADC_CONVERSION_MODE ADC_MODE_SINGLE /* Single channel mode */

/* ADC Clock Selection (ADCS bits) */
/* 00 = Fosc/2, 01 = Fosc/8, 10 = Fosc/32, 11 = FRC */
#define ADC_CLOCK_DIV 1 /* Fosc/8 */

/* Default Channel */
#define ADC_DEFAULT_CHANNEL ADC_CHANNEL_AN0

#endif
