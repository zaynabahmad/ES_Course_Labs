#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"



#define ADCON0          (*(volatile u8*)0x1F)
#define ADCON0_ADON      0   /* ADC module ON          */
#define ADCON0_GO_DONE   2   /* Start conversion       */
#define ADCON0_CHS0      3   /* Channel select bit 0   */
#define ADCON0_CHS1      4   /* Channel select bit 1   */
#define ADCON0_CHS2      5   /* Channel select bit 2   */
#define ADCON0_ADCS0     6   /* Clock select bit 0     */
#define ADCON0_ADCS1     7   /* Clock select bit 1     */

#define ADCON1          (*(volatile u8*)0x9F)

/* ADC Result Registers */
#define ADRESH          (*(volatile u8*)0x1E)   /* Bank 0: 0x1E */
#define ADRESL          (*(volatile u8*)0x9E)   /* Bank 1: 0x9E */

#define TRISA           (*(volatile u8*)0x85)

#define ADC_ADCON1_CONFIG    0x8E   /* 0b10001110 */
#define ADC_ADCON0_INIT      0x81   /* Fosc/32, CH0, ADC ON */

#endif /* ADC_PRIVATE_H */
