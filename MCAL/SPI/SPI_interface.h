#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* SPI Modes */
#define SPI_MODE_SLAVE 0
#define SPI_MODE_MASTER 1

/* SPI Clock Polarity */
#define SPI_CPOL_LOW 0  /* Clock idle low */
#define SPI_CPOL_HIGH 1 /* Clock idle high */

/* SPI Clock Phase */
#define SPI_CPHA_LEADING 0  /* Data sampled on leading edge */
#define SPI_CPHA_TRAILING 1 /* Data sampled on trailing edge */

/* SPI Clock Rate */
#define SPI_CLK_FOSC_4 0
#define SPI_CLK_FOSC_16 1
#define SPI_CLK_FOSC_64 2
#define SPI_CLK_TMR2 3

/* Function Prototypes */
void SPI_Init(u8 Mode);
void SPI_Write(u8 Data);
u8 SPI_Read(void);
u8 SPI_TransmitReceive(u8 Data);
void SPI_SetClockRate(u8 ClockRate);
void SPI_SetClockPolarity(u8 Polarity);
void SPI_SetClockPhase(u8 Phase);
void SPI_EnableInterrupt(void);
void SPI_DisableInterrupt(void);

#endif
