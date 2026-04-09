#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Register Addresses */
#define ADRESH  (*((volatile u8*)0x1E))
#define ADCON0  (*((volatile u8*)0x1F))
#define ADRESL  (*((volatile u8*)0x9E))
#define ADCON1  (*((volatile u8*)0x9F))

/* ADCON0 bits */
#define ADCS1_BIT   7   /* Clock select MSB */
#define ADCS0_BIT   6   /* Clock select LSB */
#define CHS2_BIT    5   /* Channel select bit 2 */
#define CHS1_BIT    4   /* Channel select bit 1 */
#define CHS0_BIT    3   /* Channel select bit 0 */
#define GO_DONE_BIT 2   /* Start conversion / conversion in progress */
#define ADON_BIT    0   /* ADC module on */

/* ADCON1 bits */
#define ADFM_BIT    7   /* Result format: 1=right-justified (10-bit in ADRESH:ADRESL) */
#define ADCS2_BIT   6   /* Clock select bit 2 */

#endif
