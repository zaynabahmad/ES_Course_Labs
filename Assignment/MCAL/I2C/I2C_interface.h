#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../SERVICES/STD_TYPES.h"

void I2C_voidInit(void);
void I2C_voidStart(void);
void I2C_voidRepeatedStart(void);
void I2C_voidStop(void);

void I2C_voidWrite(u8 data);
u8   I2C_u8Read_ACK(void);
u8   I2C_u8Read_NACK(void);

#endif