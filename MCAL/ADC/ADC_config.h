#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/* F_CPU = 4 MHz
 *
 * ADC clock select: ADCS<2:0> (ADCS2 in ADCON1 bit6, ADCS1:ADCS0 in ADCON0 bits7:6)
 *   000 = Fosc/2   → Tad = 0.5 µs  (below min 1.6 µs — NOT OK at 4 MHz)
 *   001 = Fosc/8   → Tad = 2.0 µs  (OK)
 *   010 = Fosc/32  → Tad = 8.0 µs  (OK)
 *   011 = FRC      → ~4 µs internal RC (OK)
 *
 * Using Fosc/8: ADCS2=0, ADCS1=0, ADCS0=1
 */
#define ADC_ADCS2   0   /* ADCON1 bit 6 */
#define ADC_ADCS1   0   /* ADCON0 bit 7 */
#define ADC_ADCS0   1   /* ADCON0 bit 6 */

/* Result format: right-justified (10-bit result, ADRESH holds 2 MSBs) */
#define ADC_RESULT_RIGHT_JUSTIFIED  1

/* Port configuration: all AN0-AN4 analog, Vref = VDD/VSS
 * ADCON1 PCFG<3:0> = 0000 → AN0–AN7 analog, Vref+ = VDD, Vref– = VSS */
#define ADC_PCFG    0x00

#endif
