#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/*
 * I2C Master (MSSP) driver for PIC16F877A
 * Pins: SCL=RC3, SDA=RC4 (open-drain, external pull-ups required)
 *
 * Active only when MSSP_ACTIVE_MODE == MSSP_MODE_I2C in MSSP_config.h
 */

/* Return values */
#define I2C_OK      0
#define I2C_NACK    1

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_RepeatedStart(void);
u8   I2C_WriteByte(u8 Data);        /* Returns I2C_OK or I2C_NACK */
u8   I2C_ReadByte(u8 SendAck);      /* SendAck: 1=ACK, 0=NACK after read */

#endif
