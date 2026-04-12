#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "SPI_Config.h"
#include "SPI_Private.h"

/* ================= Mode Macros ================= */

#define SPI_MASTER       0
#define SPI_SLAVE        1

/* ================= Polarity Macros ================= */

#define SPI_IDLE_LOW     0
#define SPI_IDLE_HIGH    1

/* ================= Edge Macros ================= */

#define SPI_TRANSMIT_RISING     0
#define SPI_TRANSMIT_FALLING    1

/* ================= Clock Rate Macros ================= */

#define SPI_FOSC_4     0x00
#define SPI_FOSC_16    0x01
#define SPI_FOSC_64    0x02
#define SPI_TMR2       0x03

/* ================= Function Prototypes ================= */

void SPI_Init(void);
u8   SPI_Transceive(u8 Data);
void SPI_SendByte(u8 Data);
u8   SPI_ReceiveByte(void);

#endif
