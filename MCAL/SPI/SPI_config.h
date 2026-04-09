#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* Mode */
#define SPI_MASTER 1
#define SPI_SLAVE  0

#define SPI_MODE SPI_MASTER

/* Clock Rate (Master only) */
#define SPI_CLOCK_FOSC_4   0
#define SPI_CLOCK_FOSC_16  1
#define SPI_CLOCK_FOSC_64  2

#define SPI_CLOCK_RATE SPI_CLOCK_FOSC_16

#endif