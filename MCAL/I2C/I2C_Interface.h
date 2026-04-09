#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* I2C Address Direction Bits */
#define I2C_DIRECTION_WRITE  0
#define I2C_DIRECTION_READ   1

/* Acknowledge Options for Reading */
#define I2C_ACK     0
#define I2C_NACK    1

/* Function Prototypes */
void I2C_Init(void);
void I2C_Start(void);
void I2C_RepeatedStart(void);
void I2C_Stop(void);

u8 I2C_Write(u8 copy_u8Data);
u8 I2C_Read(u8 copy_u8AckOption);

/* Pro Improvements: Block Transfers */
void I2C_WriteBlock(u8 slave_addr, u8* data_array, u8 length);
void I2C_ReadBlock(u8 slave_addr, u8* data_buffer, u8 length);

#endif