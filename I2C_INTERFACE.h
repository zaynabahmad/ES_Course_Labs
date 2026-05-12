#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../SERVICES/STD_TYPES.h"

/* ACK/NACK options for I2C_ReceiveByte() */
#define I2C_SEND_ACK   0
#define I2C_SEND_NACK  1

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_RepeatedStart(void);
u8   I2C_SendByte(u8 data);
u8   I2C_ReceiveByte(u8 ack);
void I2C_SendAck(void);
void I2C_SendNack(void);

#endif
