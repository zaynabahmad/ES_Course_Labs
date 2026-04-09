#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

#define I2C_ACK 0
#define I2C_NACK 1

void I2C_MasterInit(u32 clock_hz); /* e.g. 100000UL for 100 kHz */
void I2C_Start(void);
void I2C_Stop(void);
void I2C_RepeatedStart(void);
u8 I2C_WriteByte(u8 i2cData); /* Returns 0=ACK, 1=NACK     */
u8 I2C_ReadByte(u8 ack);      /* ack: I2C_ACK or I2C_NACK  */

#endif