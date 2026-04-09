#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/std_types.h"

void I2C_voidMasterInit(void);
void I2C_voidMasterStart(void);
void I2C_voidMasterStop(void);
void I2C_voidMasterWrite(u8 copy_u8Data);

#endif