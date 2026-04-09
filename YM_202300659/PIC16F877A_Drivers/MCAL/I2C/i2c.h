/*
 * i2c.h
 * MCAL - I2C Driver Interface for PIC16F877A
 * SCL = RC3, SDA = RC4
 */

#ifndef I2C_H
#define I2C_H

typedef unsigned char u8;
typedef unsigned int  u16;

/* =====================================================
 * Return / Status Codes
 * ===================================================== */
typedef enum {
    I2C_OK      = 0,
    I2C_ACK     = 0,
    I2C_NACK    = 1,
    I2C_BUSY    = 2,
    I2C_ERROR   = 3
} I2C_Status_t;

/* =====================================================
 * Baud Rate Options
 * ===================================================== */
typedef enum {
    I2C_SPEED_100KHZ = 9,    /* Standard mode  @ 4MHz */
    I2C_SPEED_400KHZ = 1     /* Fast mode      @ 4MHz */
} I2C_Speed_t;

/* =====================================================
 * Function Prototypes
 * ===================================================== */

/**
 * @brief  Initialize I2C as Master
 * @param  speed : I2C_SPEED_100KHZ or I2C_SPEED_400KHZ
 */
void I2C_MasterInit(I2C_Speed_t speed);

/**
 * @brief  Generate I2C START condition
 */
void I2C_Start(void);

/**
 * @brief  Generate I2C Repeated START condition
 */
void I2C_RepeatedStart(void);

/**
 * @brief  Generate I2C STOP condition
 */
void I2C_Stop(void);

/**
 * @brief  Send one byte on I2C bus
 * @param  data : byte to transmit
 * @return I2C_ACK if acknowledged, I2C_NACK otherwise
 */
I2C_Status_t I2C_SendByte(u8 data);

/**
 * @brief  Receive one byte from I2C bus
 * @param  ack : 1 = send ACK after byte, 0 = send NACK (last byte)
 * @return received byte
 */
u8 I2C_ReceiveByte(u8 ack);

/**
 * @brief  Write bytes to a slave device (address + data)
 * @param  slaveAddr : 7-bit slave address
 * @param  pData     : pointer to data buffer
 * @param  len       : number of bytes to write
 * @return I2C_OK on success, I2C_NACK on failure
 */
I2C_Status_t I2C_MasterWrite(u8 slaveAddr, const u8 *pData, u8 len);

/**
 * @brief  Read bytes from a slave device
 * @param  slaveAddr : 7-bit slave address
 * @param  pData     : pointer to receive buffer
 * @param  len       : number of bytes to read
 * @return I2C_OK on success, I2C_NACK on failure
 */
I2C_Status_t I2C_MasterRead(u8 slaveAddr, u8 *pData, u8 len);

/**
 * @brief  Write to a register of a slave device
 *         (START + addr + regAddr + data + STOP)
 */
I2C_Status_t I2C_WriteRegister(u8 slaveAddr, u8 regAddr, u8 data);

/**
 * @brief  Read from a register of a slave device
 *         (START + addr + regAddr + RSTART + addr+R + data + STOP)
 */
u8 I2C_ReadRegister(u8 slaveAddr, u8 regAddr);

/**
 * @brief  Check if I2C bus is idle
 */
u8 I2C_IsBusFree(void);

#endif /* I2C_H */
