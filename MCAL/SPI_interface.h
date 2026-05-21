/**
 * @file    SPI_interface.h
 * @brief   Public API of the MSSP SPI (master) driver.
 */
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../SERVICES/Types.h"

/**
 * @brief  Configure the MSSP block as an SPI master: set SCK/SDO as outputs,
 *         SDI as input, apply the configured clock rate and idle the slave
 *         select high (device deselected).
 */
void vSPI_MasterInit(void);

/**
 * @brief  Exchange one byte on the bus.
 * @param  u8TxData  byte clocked out on SDO.
 * @return byte simultaneously clocked in on SDI.
 * @note   SPI is inherently full-duplex -- one byte always comes back for
 *         every byte sent, so transmit and receive share this single call.
 */
byte_t u8SPI_Transfer(byte_t u8TxData);

/**
 * @brief  Drive the slave-select line.
 * @param  eLevel  LEVEL_LOW selects the device, LEVEL_HIGH releases it.
 */
void vSPI_SlaveSelect(eLevel_t eLevel);

#endif /* SPI_INTERFACE_H */
