#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "I2C_Config.h"
#include "I2C_Private.h"

/* ================= Mode Macros ================= */

#define I2C_MASTER    1
#define I2C_SLAVE     0

/* ================= Direction Macros ================= */

#define I2C_WRITE     0
#define I2C_READ      1

/* ================= Function Prototypes ================= */

void I2C_Init(void);
void I2C_Start(void);
void I2C_RepeatedStart(void);
void I2C_Stop(void);
void I2C_SendByte(u8 Data);
u8   I2C_ReceiveByte(u8 Ack);
u8   I2C_GetAck(void);
void I2C_SendACK(void);
void I2C_SendNACK(void);

#endif
