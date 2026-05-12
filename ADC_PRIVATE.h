#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADCON0   (*((volatile u8*)0x1F))
#define ADCON1   (*((volatile u8*)0x9F))
#define ADRESH   (*((volatile u8*)0x1E))
#define ADRESL   (*((volatile u8*)0x9E))

/* ADCON0 bit positions */
#define ADCS1    7   /* A/D Conversion Clock Select bit 1 */
#define ADCS0    6   /* A/D Conversion Clock Select bit 0 */
#define CHS2     5   /* Analog Channel Select bit 2 */
#define CHS1     4   /* Analog Channel Select bit 1 */
#define CHS0     3   /* Analog Channel Select bit 0 */
#define GO_DONE  2   /* A/D Conversion Status: 1=in progress */
#define ADON     0   /* A/D On bit: 1=ADC module enabled */

/* ADCON1 bit positions */
#define ADFM     7   /* A/D Result Format Select: 1=right-justified */
#define PCFG3    3   /* Port Configuration bit 3 */
#define PCFG2    2   /* Port Configuration bit 2 */
#define PCFG1    1   /* Port Configuration bit 1 */
#define PCFG0    0   /* Port Configuration bit 0 */

#endif
