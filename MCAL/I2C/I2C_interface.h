#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void I2C_Master_Init(void);
void I2C_Wait(void);
void I2C_Start(void);
void I2C_RepeatedStart(void);
void I2C_Stop(void);
u8   I2C_Write(u8 Data);
u8   I2C_Read_Byte(u8 Send_ACK);

#endif