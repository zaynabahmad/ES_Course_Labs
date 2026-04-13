#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* SPI Clock Modes */
#define SPI_CPOL_0_CPHA_0       0   /* Rising edge, sample on rising */
#define SPI_CPOL_0_CPHA_1       1   /* Rising edge, sample on falling */
#define SPI_CPOL_1_CPHA_0       2   /* Falling edge, sample on failing */
#define SPI_CPOL_1_CPHA_1       3   /* Falling edge, sample on rising */

/* SPI Clock Speed */
#define SPI_CLK_FOSC_4          0   /* Fosc/4 */
#define SPI_CLK_FOSC_16         1   /* Fosc/16 */
#define SPI_CLK_FOSC_64         2   /* Fosc/64 */
#define SPI_CLK_TMR2            3   /* TMR2 output */

/* SPI Modes */
#define SPI_MASTER              0
#define SPI_SLAVE               1

/* SPI Initialization */
void SPI_Init(u8 mode, u8 clockSpeed, u8 clockMode);

/* Write byte to SPI (blocking) */
u8 SPI_Write(u8 data);

/* Read byte from SPI (blocking) */
u8 SPI_Read(void);

/* Write and read simultaneously (full-duplex) */
u8 SPI_WriteRead(u8 dataOut);

/* Set SPI interrupt callback */
void SPI_SetCallback(void (*Callback)(u8));

/* SPI Interrupt Service Routine */
void SPI_ISR(void);

/* Enable/Disable SPI */
void SPI_Enable(void);
void SPI_Disable(void);

#endif
