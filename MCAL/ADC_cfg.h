/**
 * @file    ADC_cfg.h
 * @brief   Compile-time configuration for the 10-bit ADC driver.
 *
 * @details Two things must suit the 20 MHz clock: the conversion clock must
 *          give a Tad of at least 1.6 us, and the sample-and-hold capacitor
 *          must be given time to settle before each conversion. Both are set
 *          here as cycle counts rather than microsecond literals so the wait
 *          tracks the core clock instead of a hand-tuned delay.
 */
#ifndef ADC_CFG_H
#define ADC_CFG_H

/**
 * Acquisition settling time, expressed in CPU instruction cycles.
 * One cycle = Tcy = 0.2 us at 20 MHz, so 100 cycles = 20 us -- comfortably
 * above the ~19.7 us the datasheet asks for at worst-case source impedance.
 */
#define ADC_ACQ_CYCLES      100u

/**
 * Conversion-clock divider: Fosc/32 -> Tad = 1.6 us, the fastest legal
 * setting at 20 MHz. Encoded as the ADCS2:ADCS1:ADCS0 pattern 0b010.
 */
#define ADC_CLOCK_SELECT    0x02u

#endif /* ADC_CFG_H */
