#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* I2C Status Codes */
#define I2C_SUCCESS    1
#define I2C_ERROR      0

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
u8 I2C_Write(u8 Data);
u8 I2C_Read(u8 Ack);
u8 I2C_WriteDevice(u8 Address, u8 *Data, u8 Length);
u8 I2C_ReadDevice(u8 Address, u8 *Data, u8 Length);

#endif
