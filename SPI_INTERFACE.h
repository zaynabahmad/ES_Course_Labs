#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../SERVICES/STD_TYPES.h"

/* Clock polarity */
#define SPI_CKP_LOW_IDLE    0
#define SPI_CKP_HIGH_IDLE   1

/* Clock edge / phase */
#define SPI_CKE_ACTIVE_IDLE  1
#define SPI_CKE_IDLE_ACTIVE  0

/* Mode */
#define SPI_MASTER  0
#define SPI_SLAVE   1

/* Master clock speed (SSPM3:SSPM0) */
#define SPI_CLK_FOSC_4    0x00  /* Fosc/4   */
#define SPI_CLK_FOSC_16   0x01  /* Fosc/16  */
#define SPI_CLK_FOSC_64   0x02  /* Fosc/64  */
#define SPI_CLK_TMR2      0x03  /* TMR2/2   */

void SPI_Init(void);
void SPI_SendByte(u8 data);
u8   SPI_ReceiveByte(void);
u8   SPI_ExchangeByte(u8 data);

#endif
