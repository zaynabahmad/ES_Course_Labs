#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* ADC Registers */
#define ADCON0          *((volatile u8*)0x1F)  /* Control Register 0 */
#define ADCON1          *((volatile u8*)0x9F)  /* Control Register 1 */
#define ADRESH          *((volatile u8*)0x1E)  /* Result High */
#define ADRESL          *((volatile u8*)0x9E)  /* Result Low */

/* PIR1 for Interrupt Flag */
#define PIR1            *((volatile u8*)0x0C)
#define ADIF            6   /* ADC Interrupt Flag */

/* ADCON0 Bit Definitions */
#define ADCON0_ADON     0   /* ADC Enable bit */
#define ADCON0_GO_DONE  2   /* Start conversion / Status bit */
#define ADCON0_CHS0     3   /* Channel Select Bit 0 */

#define TRISA           *((volatile u8*)0x85)  /* PORTA Data Direction Register */

/* ADCON1 Bit Definitions */
#define ADCON1_ADFM     7   /* Result Format Select (1=Right, 0=Left) */

#endif