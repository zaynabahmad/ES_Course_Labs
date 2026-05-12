#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SSPCON   (*((volatile u8*)0x14))
#define SSPSTAT  (*((volatile u8*)0x94))
#define SSPBUF   (*((volatile u8*)0x13))
#define TRISC    (*((volatile u8*)0x87))
#define TRISA    (*((volatile u8*)0x85))

/* SSPCON bit positions */
#define WCOL     7   /* Write Collision Detect */
#define SSPOV    6   /* Receive Overflow Indicator */
#define SSPEN    5   /* SSP Enable */
#define CKP      4   /* Clock Polarity Select */
#define SSPM3    3   /* SSP Mode Select bit 3 */
#define SSPM2    2   /* SSP Mode Select bit 2 */
#define SSPM1    1   /* SSP Mode Select bit 1 */
#define SSPM0    0   /* SSP Mode Select bit 0 */

/* SSPSTAT bit positions */
#define SMP      7   /* Sample bit (master: 0=middle, 1=end) */
#define CKE      6   /* SPI Clock Edge Select */
#define BF       0   /* Buffer Full Status bit */

#endif
