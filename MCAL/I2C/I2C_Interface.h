#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);

void I2C_Write(u8 data);
u8 I2C_Read(u8 ack);

#endif