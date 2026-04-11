#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* ADC Register Addresses */
#define ADCON0  *((volatile u8*)0x1F)
#define ADCON1  *((volatile u8*)0x9F)
#define ADRESH  *((volatile u8*)0x1E)
#define ADRESL  *((volatile u8*)0x9E)

/* ADCON0 Bits */
#define ADCON0_ADON      0  /* ADC Enable */
#define ADCON0_GO_DONE   2  /* Start Conversion / Status */

/* ADCON1 Bits */
#define ADCON1_ADFM      7  /* 1 = Right Justified Result */

#endif /* ADC_PRIVATE_H */