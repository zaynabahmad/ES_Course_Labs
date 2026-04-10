#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void I2C_Master_Init(uint32 clock_freq);
void I2C_Master_Start(void);
void I2C_Master_RepeatedStart(void);
void I2C_Master_Stop(void);
void I2C_Master_Write(uint8 data);
uint8 I2C_Master_Read(uint8 ack_option);

#define I2C_ACK     0
#define I2C_NACK    1

#endif