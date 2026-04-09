#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H
#include "I2C_private.h"
#include "I2C_config.h"
#include "../../SERVICES/STD_TYPES.h"

void I2C_Init(u32 feq);
void I2C_Master_Start(void);
void I2C_Master_Stop(void);
void I2C_Write_Byte(u8 data);
u8 I2C_Read_Byte(void);

#endif