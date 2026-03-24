#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* ── Return status codes ── */
#define I2C_OK          0
#define I2C_ACK         0
#define I2C_NACK        1
#define I2C_ERROR       2

/* ── API ── */
void I2C_Init(void);

void I2C_Start(void);
void I2C_RepeatedStart(void);
void I2C_Stop(void);

u8   I2C_WriteByte(u8 data);        /* returns I2C_ACK or I2C_NACK */
u8   I2C_ReadByte_ACK(void);        /* read then send ACK           */
u8   I2C_ReadByte_NACK(void);       /* read then send NACK (last)   */

/* ── Helper: full write transaction ── */
/* addr = 7-bit slave address                                        */
u8   I2C_MasterWrite(u8 addr, u8 *data, u8 len);

/* ── Helper: full read transaction ── */
u8   I2C_MasterRead(u8 addr, u8 *buf, u8 len);

#endif
