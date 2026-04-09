#ifndef I2C_H
#define I2C_H

#include "i2c_cfg.h"

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(void);
int  I2C_Read(void);

#endif