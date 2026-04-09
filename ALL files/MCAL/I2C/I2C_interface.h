#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Initialize I2C as Master */
void I2C_Init(void);

/* Send START condition */
void I2C_Start(void);

/* Send STOP condition */
void I2C_Stop(void);

/* Write one byte */
void I2C_Write(u8 Data);

/* Read one byte */
u8 I2C_Read(void);

#endif