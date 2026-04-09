/*
 * adc_private.h
 * MCAL - ADC Register Definitions for PIC16F877A
 */

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* =====================================================
 * ADC Registers
 * ===================================================== */

/* ADRESH - ADC Result High (Bank 0) */
#define ADRESH_REG    (*((volatile unsigned char*)0x1E))

/* ADRESL - ADC Result Low (Bank 1) */
#define ADRESL_REG    (*((volatile unsigned char*)0x9E))

/* ADCON0 - ADC Control 0 (Bank 0) */
#define ADCON0_REG    (*((volatile unsigned char*)0x1F))

/* ADCON1 - ADC Control 1 (Bank 1) */
#define ADCON1_REG    (*((volatile unsigned char*)0x9F))

/* =====================================================
 * ADCON0 Bit Positions
 * ===================================================== */
#define ADCON0_ADCS1  7    /* ADC Clock Select bit 1 */
#define ADCON0_ADCS0  6    /* ADC Clock Select bit 0 */
#define ADCON0_CHS2   5    /* Channel Select bit 2    */
#define ADCON0_CHS1   4    /* Channel Select bit 1    */
#define ADCON0_CHS0   3    /* Channel Select bit 0    */
#define ADCON0_GO     2    /* GO/DONE: 1=start conv   */
#define ADCON0_ADON   0    /* ADC Enable              */

/* =====================================================
 * ADCON1 Bit Positions
 * ===================================================== */
#define ADCON1_ADFM   7    /* Result format: 1=right justified */
#define ADCON1_PCFG3  3    /* Port config bit 3 */
#define ADCON1_PCFG2  2    /* Port config bit 2 */
#define ADCON1_PCFG1  1    /* Port config bit 1 */
#define ADCON1_PCFG0  0    /* Port config bit 0 */

/* TRISA for analog input config */
#define TRISA_REG     (*((volatile unsigned char*)0x85))

#endif /* ADC_PRIVATE_H */
