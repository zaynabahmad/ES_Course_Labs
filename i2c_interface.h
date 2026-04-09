#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/types.h"

void I2C_Configure(void);
void I2C_GenerateStart(void);
void I2C_GenerateStop(void);
void I2C_SendByte(unsigned char byte);
unsigned char I2C_ReceiveByte(unsigned char ack);

#endif