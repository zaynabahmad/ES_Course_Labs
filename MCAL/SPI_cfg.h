/**
 * @file    SPI_cfg.h
 * @brief   Compile-time configuration for the MSSP SPI (master) driver.
 *
 * @details The SPI clock rate and the slave-select pin are the two board-level
 *          choices. The clock divider is given as a plain number so the intent
 *          is readable; SPI.c maps it to the SSPM bit pattern.
 */
#ifndef SPI_CFG_H
#define SPI_CFG_H

/** SCK = Fosc / SPI_CLOCK_DIV. Valid dividers: 4, 16, 64. */
#define SPI_CLOCK_DIV       16u

/**
 * Slave-select line, driven as a plain output on PORTC.
 * RC0 is used by default so it never collides with SCK/SDI/SDO on RC3..RC5.
 */
#define SPI_SS_PIN          0u

#endif /* SPI_CFG_H */
