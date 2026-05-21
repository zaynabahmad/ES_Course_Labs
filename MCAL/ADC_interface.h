/**
 * @file    ADC_interface.h
 * @brief   Public API of the 10-bit ADC driver.
 */
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../SERVICES/Types.h"

/** @brief Analogue input channels of the PIC16F877A. */
typedef enum
{
    ADC_CH_AN0 = 0,
    ADC_CH_AN1,
    ADC_CH_AN2,
    ADC_CH_AN3,
    ADC_CH_AN4,
    ADC_CH_AN5,
    ADC_CH_AN6,
    ADC_CH_AN7
} eAdcChannel_t;

/**
 * @brief  Power up the ADC, select the conversion clock and make every AN
 *         pin analogue with a right-justified result.
 */
void vADC_Init(void);

/**
 * @brief  Run one blocking conversion on @p eChannel.
 * @return 10-bit result (0..1023); 0 if the channel index is invalid.
 * @note   The sample-and-hold settling time is spent in a counted cycle loop
 *         derived from ADC_ACQ_CYCLES -- not a fixed millisecond delay -- so
 *         it scales with the core clock.
 */
word_t u16ADC_Capture(eAdcChannel_t eChannel);

#endif /* ADC_INTERFACE_H */
