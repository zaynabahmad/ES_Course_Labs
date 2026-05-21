/**
 * @file    I2C_interface.h
 * @brief   Public API of the MSSP I2C (master) driver.
 */
#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../SERVICES/Types.h"

/**
 * @brief  Configure the MSSP block as an I2C master and derive SSPADD from
 *         the configured bus clock. SCL/SDA are released to the peripheral.
 */
void vI2C_MasterInit(void);

/**
 * @brief  Emit a START condition and wait for it to complete.
 */
void vI2C_Start(void);

/**
 * @brief  Emit a STOP condition and wait for it to complete.
 */
void vI2C_Stop(void);

/**
 * @brief  Clock one byte out to the bus.
 * @param  u8Data  byte to transmit (address or payload).
 * @return OUTCOME_OK if the slave acknowledged, OUTCOME_FAIL if it did not.
 */
eOutcome_t u8I2C_Write(byte_t u8Data);

/**
 * @brief  Clock one byte in from the bus.
 * @param  bAck  FLAG_RAISED to ACK the byte (more to follow), FLAG_CLEARED to
 *               NACK it (last byte of the read).
 * @return the byte received from the slave.
 */
byte_t u8I2C_Read(flag_t bAck);

#endif /* I2C_INTERFACE_H */
