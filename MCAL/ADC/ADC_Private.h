#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* ================= Register Addresses ================= */

#define ADCON0       (*((volatile u8*)0x1F))
#define ADCON1       (*((volatile u8*)0x9F))
#define ADRESH       (*((volatile u8*)0x1E))
#define ADRESL       (*((volatile u8*)0x9E))

/* TRISA for analog input pins */
#define TRISA        (*((volatile u8*)0x85))

/* ================= ADCON0 Bits ================= */

#define ADCS0        6      /* A/D Conversion Clock bit 0 */
#define ADCS1        7      /* A/D Conversion Clock bit 1 */
#define CHS0         3      /* Channel Select bit 0 */
#define CHS1         4      /* Channel Select bit 1 */
#define CHS2         5      /* Channel Select bit 2 */
#define GO_DONE      2      /* A/D Conversion Status */
#define ADON         0      /* A/D On */

/* ================= ADCON1 Bits ================= */

#define ADFM         7      /* Result Format: 1=Right Justified */
#define PCFG0        0      /* Port Configuration bit 0 */
#define PCFG1        1
#define PCFG2        2
#define PCFG3        3

#endif
