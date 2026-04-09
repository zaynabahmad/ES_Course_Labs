#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"


#define I2C_ACK_RECEIVED    0
#define I2C_NACK_RECEIVED   1
#define I2C_SEND_ACK        0
#define I2C_SEND_NACK       1


void I2C_voidMasterInit(void);
void I2C_voidStart(void);
void I2C_voidStop(void);
void I2C_voidRepeatedStart(void);
u8 I2C_u8WriteByte(u8 Copy_u8Data);
u8 I2C_u8ReadByte(u8 Copy_u8Ack);
void I2C_voidDisable(void);

#endif /* I2C_INTERFACE_H */