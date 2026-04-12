#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_RepeatedStart(void);
u8   I2C_SendByte(u8 Data);
u8   I2C_ReceiveByte(u8 ACK);

#endif