#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* Modes */
#define SPI_MODE0   0
#define SPI_MODE1   1
#define SPI_MODE2   2
#define SPI_MODE3   3

/* Clock (Master only) */
#define SPI_FOSC_4     0
#define SPI_FOSC_16    1
#define SPI_FOSC_64    2
#define SPI_TMR2_DIV2  3

/* User Config */
#define SPI_MODE        SPI_MODE0
#define SPI_CLOCK       SPI_FOSC_4

#endif