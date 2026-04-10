#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void I2C_Master_Init(const u32 BaudRate);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(u8 Data);

#endif
