#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\STD_TYPES.h"

/* Return codes */
#define I2C_OK              0u
#define I2C_ERR_NACK        1u    /* Slave sent NACK         */
#define I2C_ERR_TIMEOUT     2u    /* Bus did not become free */
#define I2C_ERR_BUS_BUSY    3u    /* Collision / bus busy    */

/* Read/Write direction byte flags */
#define I2C_WRITE           0u
#define I2C_READ            1u

/* ---- Public function prototypes ---- */

void I2C_voidInit(void);

void I2C_voidStart(void);

void I2C_voidRepeatedStart(void);

void I2C_voidStop(void);

unsigned char I2C_u8Write(unsigned char data);

unsigned char I2C_u8Read(unsigned char send_ack);

void I2C_voidWaitIdle(void);

#endif /* I2C_INTERFACE_H */