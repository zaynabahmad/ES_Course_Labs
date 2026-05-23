#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADCON0   (*(volatile unsigned char*)0x1F)

#define ADCON1   (*(volatile unsigned char*)0x9F)

/* ADC Result Registers */
#define ADRESH   (*(volatile unsigned char*)0x1E)
#define ADRESL   (*(volatile unsigned char*)0x9E)

#define ADC_ADON_BIT      0   /* ADC module ON/OFF         */
#define ADC_GO_DONE_BIT   2   /* Start / completion flag   */
#define ADC_CHS_SHIFT     3   /* Channel select start bit  */
#define ADC_ADCS_SHIFT    6   /* Clock select start bit    */

#define ADC_CLK_FOSC_2    0x00   /* 00 = Fosc/2  */
#define ADC_CLK_FOSC_8    0x01   /* 01 = Fosc/8  */
#define ADC_CLK_FOSC_32   0x02   /* 10 = Fosc/32 */
#define ADC_CLK_FRC       0x03   /* 11 = FRC     */

/* ---- ADCON1 configuration ---- */
/* ADFM=1 (right justified), all of AN0 analog, rest digital */
#define ADC_ADCON1_CONFIG  0x8E

/* ---- Channel mask (clears CHS2:CHS0 in ADCON0) ---- */
#define ADC_CHANNEL_MASK  0b11000111

/* ---- Maximum valid channel number on PIC16F877A ---- */
#define ADC_MAX_CHANNEL   7u

/* ---- Acquisition delay loop count (~20 us @ 8 MHz) ---- */
#define ADC_ACQ_DELAY_COUNT  40u

#endif /* ADC_PRIVATE_H */