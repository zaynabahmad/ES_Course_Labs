#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write (unsigned char u8Data);
unsigned char I2C_Read (unsigned char u8Ack);

#endif