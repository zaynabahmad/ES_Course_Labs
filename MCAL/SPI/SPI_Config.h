#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* SPI Mode: SPI_MASTER or SPI_SLAVE */
#define SPI_MODE          SPI_MASTER

/* Clock Polarity: SPI_IDLE_LOW or SPI_IDLE_HIGH */
#define SPI_CLOCK_POLARITY    SPI_IDLE_LOW

/* Clock Edge: SPI_TRANSMIT_RISING or SPI_TRANSMIT_FALLING */
#define SPI_CLOCK_EDGE        SPI_TRANSMIT_RISING

/* Clock Rate (Master only): SPI_FOSC_4, SPI_FOSC_16, SPI_FOSC_64, SPI_TMR2 */
#define SPI_CLOCK_RATE        SPI_FOSC_16

#endif
