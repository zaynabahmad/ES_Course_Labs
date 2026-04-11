#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

#define I2C_ACK      0
#define I2C_NACK     1

void MI2C_MasterInit(u32 clock_hz);
void MI2C_MasterWait(void);
void MI2C_MasterStart(void);
void MI2C_MasterRepeatedStart(void);
void MI2C_MasterStop(void);
u8   MI2C_MasterWrite(u8 data);
u8   MI2C_MasterRead(u8 ack_state);

#endif