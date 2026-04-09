#ifndef MSSP_CONFIG_H
#define MSSP_CONFIG_H

/*
 * MSSP module is shared between SPI and I2C on the PIC16F877A (RC3/RC4 pins).
 * Only ONE mode can be active in a given build.
 *
 * Set MSSP_ACTIVE_MODE to one of:
 *   MSSP_MODE_SPI  — enables SPI driver, stubs out I2C
 *   MSSP_MODE_I2C  — enables I2C driver, stubs out SPI
 */
#define MSSP_MODE_SPI   0
#define MSSP_MODE_I2C   1

#define MSSP_ACTIVE_MODE   MSSP_MODE_SPI

#endif
