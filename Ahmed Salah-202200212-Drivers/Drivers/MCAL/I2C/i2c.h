/**
 * @file    i2c.h
 * @brief   PIC16F877 I2C Driver Header (MSSP module in I2C mode)
 * @details Master and Slave modes. 7-bit addressing. 100kHz / 400kHz.
 *
 * Key Registers (DS30292C):
 *   SSPCON  (0x14):
 *     bit7  WCOL   — write collision
 *     bit6  SSPOV  — receive overflow
 *     bit5  SSPEN  — SSP enable
 *     bit4  CKP    — release SCL (set to release clock in slave)
 *     bit3-0 SSPM — mode:
 *       0110  I2C Slave,  7-bit address
 *       0111  I2C Slave, 10-bit address
 *       1000  I2C Master
 *       1011  I2C Firmware-controlled Master
 *   SSPCON2 (0x91):
 *     bit7  GCEN   — general call enable (slave)
 *     bit6  ACKSTAT — ACK status (master transmit)
 *     bit5  ACKDT  — ACK data bit (master receive)
 *     bit4  ACKEN  — ACK sequence enable
 *     bit3  RCEN   — receive enable
 *     bit2  PEN    — STOP condition enable
 *     bit1  RSEN   — repeated START
 *     bit0  SEN    — START condition enable
 *   SSPSTAT (0x94):
 *     bit7  SMP    — slew rate (0=400kHz, 1=100kHz)
 *     bit6  CKE    — SMBus levels
 *     bit5  D_nA   — data/address (slave)
 *     bit4  P      — STOP detected
 *     bit3  S      — START detected
 *     bit2  R_nW   — read/write (slave)
 *     bit1  UA     — update address (10-bit)
 *     bit0  BF     — buffer full
 *   SSPADD  (0x93) — Slave: I2C address / Master: baud rate
 *   SSPBUF  (0x13) — I2C data buffer
 *   PIR1<3> SSPIF  — SSP interrupt flag
 *   PIE1<3> SSPIE  — SSP interrupt enable
 *
 * Pin mapping:
 *   SCL → RC3
 *   SDA → RC4
 *
 * SSPADD (master baud rate):
 *   SSPADD = Fosc / (4 * BaudRate) - 1
 *   e.g., 4MHz, 100kHz: SSPADD = 4000000/(4*100000) - 1 = 9
 *   e.g., 4MHz, 400kHz: SSPADD = 4000000/(4*400000) - 1 = 1
 */

#ifndef I2C_H
#define I2C_H

#include <pic16f877.h>
#include <stdint.h>

/*============================================================
 * I2C Mode
 *============================================================*/
typedef enum {
    I2C_MODE_MASTER = 0x08,   /* SSPM = 1000 */
    I2C_MODE_SLAVE_7BIT = 0x06,  /* SSPM = 0110 */
    I2C_MODE_SLAVE_10BIT = 0x07  /* SSPM = 0111 */
} I2C_Mode_t;

/*============================================================
 * Speed / Slew Rate
 *============================================================*/
typedef enum {
    I2C_SPEED_100K = 1,   /* SMP=1 — slew rate control disabled (100kHz) */
    I2C_SPEED_400K = 0    /* SMP=0 — slew rate control enabled  (400kHz) */
} I2C_Speed_t;

/*============================================================
 * ACK/NACK
 *============================================================*/
typedef enum {
    I2C_ACK  = 0,
    I2C_NACK = 1
} I2C_Ack_t;

/*============================================================
 * Interrupt Enable
 *============================================================*/
typedef enum {
    I2C_INT_DISABLE = 0,
    I2C_INT_ENABLE  = 1
} I2C_Int_t;

/*============================================================
 * Status / Error Codes
 *============================================================*/
typedef enum {
    I2C_OK               = 0,
    I2C_ERR_NACK         = 1,   /* Device NACKed     */
    I2C_ERR_BUS_BUSY     = 2,   /* Bus not released  */
    I2C_ERR_OVERFLOW     = 3,   /* Receive overflow  */
    I2C_ERR_COLLISION    = 4    /* Write collision   */
} I2C_Status_t;

/*============================================================
 * Master Configuration Structure
 *============================================================*/
typedef struct {
    uint32_t   foscHz;     /* Crystal frequency              */
    uint32_t   speedHz;    /* Bus speed (100000 or 400000)   */
    I2C_Speed_t slewRate;  /* SMP bit                        */
    I2C_Int_t   intEnable; /* SSP interrupt                  */
} I2C_MasterConfig_t;

/*============================================================
 * Slave Configuration Structure
 *============================================================*/
typedef struct {
    uint8_t    slaveAddr;   /* 7-bit slave address (bits<7:1>) */
    I2C_Mode_t mode;        /* 7-bit or 10-bit slave           */
    I2C_Speed_t slewRate;   /* SMP bit                         */
    I2C_Int_t   intEnable;  /* SSP interrupt                   */
    uint8_t    genCallEn;   /* General call enable             */
} I2C_SlaveConfig_t;

/*============================================================
 * API — Master Mode
 *============================================================*/

/**
 * @brief  Initialize I2C in Master mode
 * @param  cfg  Pointer to I2C_MasterConfig_t
 */
void I2C_Master_Init(const I2C_MasterConfig_t *cfg);

/**
 * @brief  Generate START condition and wait
 * @return I2C_OK or I2C_ERR_BUS_BUSY
 */
I2C_Status_t I2C_Master_Start(void);

/**
 * @brief  Generate REPEATED START condition
 */
I2C_Status_t I2C_Master_RepeatedStart(void);

/**
 * @brief  Generate STOP condition
 */
void I2C_Master_Stop(void);

/**
 * @brief  Transmit one byte and check ACK
 * @param  data  Byte to send
 * @return I2C_OK or I2C_ERR_NACK
 */
I2C_Status_t I2C_Master_WriteByte(uint8_t data);

/**
 * @brief  Read one byte and send ACK or NACK
 * @param  ackType  I2C_ACK (more bytes to follow) or I2C_NACK (last byte)
 * @return Received byte
 */
uint8_t I2C_Master_ReadByte(I2C_Ack_t ackType);

/**
 * @brief  High-level: write N bytes to a device
 * @param  devAddr  7-bit device address
 * @param  buf      Data to write
 * @param  len      Number of bytes
 * @return I2C_OK or error code
 */
I2C_Status_t I2C_Master_Write(uint8_t devAddr, const uint8_t *buf, uint8_t len);

/**
 * @brief  High-level: read N bytes from a device
 * @param  devAddr  7-bit device address
 * @param  buf      Buffer to fill
 * @param  len      Number of bytes to read
 * @return I2C_OK or error code
 */
I2C_Status_t I2C_Master_Read(uint8_t devAddr, uint8_t *buf, uint8_t len);

/**
 * @brief  High-level: write then read (register read pattern)
 * @param  devAddr   7-bit device address
 * @param  regAddr   Register address byte to write first
 * @param  buf       Buffer for received data
 * @param  len       Number of bytes to read
 * @return I2C_OK or error code
 */
I2C_Status_t I2C_Master_WriteRead(uint8_t devAddr, uint8_t regAddr,
                                   uint8_t *buf, uint8_t len);

/*============================================================
 * API — Slave Mode
 *============================================================*/

/**
 * @brief  Initialize I2C in Slave mode
 * @param  cfg  Pointer to I2C_SlaveConfig_t
 */
void I2C_Slave_Init(const I2C_SlaveConfig_t *cfg);

/**
 * @brief  Slave ISR callback — implement in application
 * @note   Check SSPSTAT bits to determine transaction type
 */
void I2C_Slave_Callback(void);

/*============================================================
 * Common
 *============================================================*/
/** @brief  Enable SSP module */
void I2C_Enable(void);

/** @brief  Disable SSP module */
void I2C_Disable(void);

#endif /* I2C_H */
