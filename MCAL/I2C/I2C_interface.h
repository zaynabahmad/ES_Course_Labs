#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* I2C Mode */
#define I2C_MODE_MASTER 0
#define I2C_MODE_SLAVE 1

/* I2C Speed */
#define I2C_SPEED_100KHZ 100000
#define I2C_SPEED_400KHZ 400000

/* I2C Status */
#define I2C_SUCCESS 0
#define I2C_ERROR_ACK 1
#define I2C_ERROR_BUSY 2
#define I2C_ERROR_TIMEOUT 3

/* Function Prototypes */
void I2C_Init(u8 Mode, u8 Address);
void I2C_SetSpeed(u32 SpeedHz);
void I2C_Start(void);
void I2C_Stop(void);
u8 I2C_WriteByte(u8 Data);
u8 I2C_ReadByte(u8 ACK);
void I2C_SendACK(void);
void I2C_SendNACK(void);
u8 I2C_WriteAddress(u8 Address, u8 ReadWrite);
u8 I2C_IsACKReceived(void);
void I2C_SetAddress(u8 Address);

#endif
