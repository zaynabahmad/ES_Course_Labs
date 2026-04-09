#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* Crystal Frequency in Hz */
#define SPI_FOSC            8000000UL

/**
 * SPI Clock Polarity (CKP)
 * 0: Idle state for clock is a low level
 * 1: Idle state for clock is a high level
 */
#define SPI_CLOCK_POLARITY  0

/**
 * SPI Clock Edge (CKE)
 * 0: Transmit occurs on transition from Idle to Active clock state
 * 1: Transmit occurs on transition from Active to Idle clock state
 */
#define SPI_CLOCK_PHASE     0

/**
 * SPI Sample bit (SMP)
 * 0: Input data sampled at middle of data output time
 * 1: Input data sampled at end of data output time
 */
#define SPI_DATA_SAMPLE     0

#endif