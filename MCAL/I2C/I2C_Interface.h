#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void I2C_voidMasterInit(void);
void I2C_voidSlaveInit(u8 Copy_u8SlaveAddress);

void I2C_voidStart(void);
void I2C_voidRepeatedStart(void);
void I2C_voidStop(void);

void I2C_voidWait(void);
u8   I2C_u8WriteByte(u8 Copy_u8Data);
u8   I2C_u8ReadByte(u8 Copy_u8AckParam);

#endif