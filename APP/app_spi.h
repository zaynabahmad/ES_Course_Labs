/**
 * @file    app_spi.h
 * @brief   Entry point for the SPI master application.
 */
#ifndef APP_SPI_H
#define APP_SPI_H

/**
 * @brief  Act as an SPI master: frame a short byte sequence with the slave
 *         select line and report what each transfer clocked back. Never returns.
 */
void vApp_Spi(void);

#endif /* APP_SPI_H */
