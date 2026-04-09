#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* SPI Master Mode Clock Rate (SSPM3:SSPM0 bits in SSPCON)
   0x00 -> Fosc / 4
   0x01 -> Fosc / 16
   0x02 -> Fosc / 64 */
#define SPI_MASTER_MODE_CLOCK   0x00

/* SPI Slave Mode (SSPM3:SSPM0 bits in SSPCON)
   0x04 -> Slave mode, SS pin enabled */
#define SPI_SLAVE_MODE          0x04

#endif