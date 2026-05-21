#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"
#include "I2C_Private.h"
#include "I2C_Config.h"

#define I2C_SEND_ACK    1
#define I2C_SEND_NACK   0

void I2C_MasterInit(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_RepeatedStart(void);
u8   I2C_WriteByte(u8 Data);
u8   I2C_ReadByte(u8 ack);
void I2C_Disable(void);

#endif
