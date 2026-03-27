#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* Clock Polarity (CKP): 0 = Idle State Low, 1 = Idle State High */
#define SPI_CLOCK_POLARITY 0

/* Clock Edge (CKE): 0 = Transmit on idle to active, 1 = Transmit on active to idle */
#define SPI_CLOCK_EDGE 1

/* Sample Phase (SMP): 0 = Sample at middle, 1 = Sample at end */
#define SPI_SAMPLE_PHASE 0

/* SPI Master Clock Rate (Fosc/4) */
#define SPI_MASTER_OSC_DIV_4 0

#endif
