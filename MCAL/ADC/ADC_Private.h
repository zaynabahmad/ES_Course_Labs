#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* PIC16F877A ADC registers */
#define ADCON0      (*(volatile u8*)0x1F)   /* Bank 0 */
#define ADCON1      (*(volatile u8*)0x9F)   /* Bank 1 */
#define ADRESH      (*(volatile u8*)0x1E)   /* Bank 0 */
#define ADRESL      (*(volatile u8*)0x9E)   /* Bank 1 */

#ifndef PIR1
#define PIR1        (*(volatile u8*)0x0C)   /* Bank 0 */
#endif

#ifndef PIE1
#define PIE1        (*(volatile u8*)0x8C)   /* Bank 1 */
#endif

/* ================= ADCON0 bit positions ================= */
#define ADCS1_BIT   7   /* A/D Conversion Clock Select bit 1 */
#define ADCS0_BIT   6   /* A/D Conversion Clock Select bit 0 */
#define CHS2_BIT    5   /* Analog Channel Select bit 2 */
#define CHS1_BIT    4   /* Analog Channel Select bit 1 */
#define CHS0_BIT    3   /* Analog Channel Select bit 0 */
#define GO_DONE_BIT 2   /* A/D Conversion Status bit */
#define ADON_BIT    0   /* A/D On bit */

/* ================= ADCON1 bit positions ================= */
#define ADFM_BIT    7   /* A/D Result Format Select bit (1 = Right justified) */
#define ADCS2_BIT   6   /* A/D Conversion Clock Select bit 2 */
#define PCFG3_BIT   3   /* A/D Port Configuration Control bit 3 */
#define PCFG2_BIT   2   /* A/D Port Configuration Control bit 2 */
#define PCFG1_BIT   1   /* A/D Port Configuration Control bit 1 */
#define PCFG0_BIT   0   /* A/D Port Configuration Control bit 0 */

/* ================= PIR1/PIE1 bit positions ================= */
#define ADIF_BIT    6   /* A/D Converter Interrupt Flag bit */
#define ADIE_BIT    6   /* A/D Converter Interrupt Enable bit */

/* Voltage Reference / Port Configurations */
#define ADC_ALL_ANALOG    0x00
#define ADC_AN0_TO_AN4    0x02
/* Note: See PIC16F877A datasheet for full PCFG bits */

/* Result Justification */
#define ADC_RIGHT_JUSTIFIED 1
#define ADC_LEFT_JUSTIFIED  0

#endif