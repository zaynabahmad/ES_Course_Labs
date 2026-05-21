/**
 * @file    ADC_private.h
 * @brief   Register map and field layout for the ADC driver.
 *
 * @details The ADC spreads its control across ADCON0 (clock, channel, start)
 *          and ADCON1 (result justification, pin assignment). The channel
 *          number sits in a 3-bit field, so its shift and mask are named here
 *          rather than buried as literals in the driver.
 */
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../SERVICES/Types.h"

#define ADC_REG_ADCON0      ( *((volatile byte_t *)0x1Fu) )
#define ADC_REG_ADCON1      ( *((volatile byte_t *)0x9Fu) )
#define ADC_REG_ADRESH      ( *((volatile byte_t *)0x1Eu) )
#define ADC_REG_ADRESL      ( *((volatile byte_t *)0x9Eu) )
#define ADC_REG_TRISA       ( *((volatile byte_t *)0x85u) )
#define ADC_REG_TRISE       ( *((volatile byte_t *)0x89u) )

/* Analogue pins are spread across two ports: AN0..AN3 + AN4 on PORTA
 * (RA0..RA3, RA5) and AN5..AN7 on PORTE (RE0..RE2). They must be inputs for
 * the sample-and-hold to see the external voltage. */
#define ADC_TRISA_AN_MASK   0x2Fu
#define ADC_TRISE_AN_MASK   0x07u

/* ADCON0 fields. */
#define ADC_BIT_ADON        0u          /* module power                     */
#define ADC_BIT_GODONE      2u          /* start / busy flag                 */
#define ADC_CHANNEL_SHIFT   3u          /* CHS2:0 occupy bits 5:3            */
#define ADC_CHANNEL_MASK    0x07u
#define ADC_CLOCK_SHIFT     6u          /* ADCS1:0 occupy bits 7:6           */

/* ADCON1 fields. */
#define ADC_BIT_ADFM        7u          /* 1 = right-justified result        */
/* PCFG = 0b0000 -> every AN pin analogue, references tied to Vdd/Vss. */
#define ADC_PORTCFG_ALL_AN  0x00u

/* Highest analogue channel index on the PIC16F877A (AN0..AN7). */
#define ADC_CHANNEL_MAX     7u

#endif /* ADC_PRIVATE_H */
