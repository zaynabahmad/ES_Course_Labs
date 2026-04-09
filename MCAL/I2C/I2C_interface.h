#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Init */
void I2C_voidInitMaster(void);

/* Control */
void I2C_voidStart(void);
void I2C_voidRepeatedStart(void);
void I2C_voidStop(void);

/* Data */
u8 I2C_u8WriteByte(u8 Copy_u8Data);
u8 I2C_u8ReadByte(u8 Copy_u8AckNack);

#endif