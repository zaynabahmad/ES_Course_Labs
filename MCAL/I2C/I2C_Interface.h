#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "I2C_Private.h"
#include "I2C_Config.h"

#define I2C_WRITE 0
#define I2C_READ  1

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Restart(void);
void I2C_Write(u8 Data);
u8 I2C_Read(u8 Ack);
u8 I2C_GetAckStatus(void);

#endif
