#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/std_types.h"

void I2C_voidInitMaster(u32 Copy_u32Clock);
void I2C_voidStart(void);
void I2C_voidStop(void);
void I2C_voidWrite(u8 Copy_u8Data);
u8   I2C_u8ReadWithAck(void);
u8   I2C_u8ReadWithNoAck(void);

#endif