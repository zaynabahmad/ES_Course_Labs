#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* Clock polarity: SPI_CKP_LOW_IDLE or SPI_CKP_HIGH_IDLE */
#define SPI_CLOCK_POLARITY   SPI_CKP_LOW_IDLE

/* Clock edge: SPI_CKE_ACTIVE_IDLE or SPI_CKE_IDLE_ACTIVE */
#define SPI_CLOCK_PHASE      SPI_CKE_ACTIVE_IDLE

/* Master/slave: SPI_MASTER or SPI_SLAVE */
#define SPI_MODE             SPI_MASTER

/* Master clock divider: SPI_CLK_FOSC_4, SPI_CLK_FOSC_16, SPI_CLK_FOSC_64 */
#define SPI_CLOCK_SPEED      SPI_CLK_FOSC_4

#endif
