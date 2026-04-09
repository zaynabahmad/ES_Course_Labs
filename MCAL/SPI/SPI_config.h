#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* Available clock options */
#define SPI_CLOCK_DIV_4     0x00
#define SPI_CLOCK_DIV_16    0x01
#define SPI_CLOCK_DIV_64    0x02
#define SPI_CLOCK_TMR2      0x03

/* Choose one (e.g., Fosc/16) */
#define SPI_CLOCK_MODE      SPI_CLOCK_DIV_16

#endif