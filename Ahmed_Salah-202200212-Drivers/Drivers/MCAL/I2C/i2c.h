#ifndef I2C_H
#define I2C_H

#include "../../SERVICES/Std_Types.h"

void I2C_voidMasterInit(void);
void I2C_voidStart(void);
void I2C_voidStop(void);
void I2C_voidWrite(u8 copy_u8Data);
u8   I2C_u8Read(u8 copy_u8Ack);

#endif