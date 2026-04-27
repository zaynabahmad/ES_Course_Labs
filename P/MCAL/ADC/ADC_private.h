#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* ---- ADC registers ---- */
#define ADCON0_REG  *((volatile unsigned char*)0x1F)
#define ADCON1_REG  *((volatile unsigned char*)0x9F)
#define ADRESH_REG  *((volatile unsigned char*)0x1E)
#define ADRESL_REG  *((volatile unsigned char*)0x9E)
#define TRISA_REG   *((volatile unsigned char*)0x85)

/* ---- ADCON0 bit positions ---- */
#define ADON        0   /* ADC module enable */
#define GO_DONE     2   /* Start / busy flag  */

#endif
