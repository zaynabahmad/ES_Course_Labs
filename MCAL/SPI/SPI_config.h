#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#include "../../SERVICES/STD_TYPES.h"

/* SPI Default Configuration */
#define SPI_DEFAULT_MODE SPI_MODE_MASTER       /* Master or Slave mode */
#define SPI_DEFAULT_CLOCK_RATE SPI_CLK_FOSC_16 /* Clock rate */
#define SPI_DEFAULT_POLARITY SPI_CPOL_LOW      /* Clock idle state */
#define SPI_DEFAULT_PHASE SPI_CPHA_LEADING     /* Sample edge */

/* SPI Interrupt Enable */
#define SPI_INTERRUPT_ENABLE 0 /* 1 = enable, 0 = disable */

#endif
