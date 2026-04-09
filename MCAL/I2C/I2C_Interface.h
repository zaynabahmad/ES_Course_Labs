#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void I2C_Master_Init(void);
void I2C_Slave_Init(u8 Slave_Address);
void I2C_Start(void);
void I2C_Repeated_Start(void);
void I2C_Stop(void);
void I2C_Write(u8 Data);
u8   I2C_Read(u8 Ack);
u8   I2C_Slave_Read(void);

#endif
