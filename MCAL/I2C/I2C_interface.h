#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void I2C_voidInitMaster(void);
void I2C_voidStart(void);
void I2C_voidStop(void);
u8 I2C_u8Write(u8 Copy_u8Data);

#endif