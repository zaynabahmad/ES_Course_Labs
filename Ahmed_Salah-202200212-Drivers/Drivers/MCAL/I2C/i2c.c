/**
 * @file    i2c.c
 * @brief   PIC16F877 I2C Driver Implementation
 */

#include "i2c.h"

/*============================================================
 * Internal helpers
 *============================================================*/

/** Wait for SSP interrupt flag (operation complete) */
static void i2c_wait_flag(void)
{
    while (!PIR1bits.SSPIF) { /* wait */ }
    PIR1bits.SSPIF = 0;
}

/** Wait until MSSP is idle (no pending operations) */
static void i2c_wait_idle(void)
{
    /* Wait while any control bit is set or BF is set */
    while ((SSPCON2 & 0x1Fu) || SSPSTATbits.BF) { /* wait */ }
}

/*------------------------------------------------------------
 * I2C_Master_Init
 * SSPADD = Fosc/(4*BaudRate) - 1
 *------------------------------------------------------------*/
void I2C_Master_Init(const I2C_MasterConfig_t *cfg)
{
    /* SCL(RC3) and SDA(RC4) must be inputs for open-drain */
    TRISCbits.TRISC3 = 1;
    TRISCbits.TRISC4 = 1;

    /* Disable SSP before configuring */
    SSPCONbits.SSPEN = 0;

    /* SSPADD — baud rate */
    SSPADD = (uint8_t)((cfg->foscHz / (4u * cfg->speedHz)) - 1u);

    /* SSPCON — Master mode (1000) */
    SSPCON = (uint8_t)(I2C_MODE_MASTER & 0x0Fu);

    /* SSPSTAT — SMP (slew rate) and CKE=0 (I2C levels) */
    SSPSTAT = (uint8_t)((uint8_t)cfg->slewRate << 7);

    /* SSPCON2 — clear all control bits */
    SSPCON2 = 0x00u;

    /* Clear interrupt flag */
    PIR1bits.SSPIF = 0;

    /* Interrupt enable (caller must set PEIE + GIE) */
    PIE1bits.SSPIE = (uint8_t)cfg->intEnable;

    /* Enable SSP */
    SSPCONbits.SSPEN = 1;
}

/*------------------------------------------------------------
 * I2C_Master_Start
 *------------------------------------------------------------*/
I2C_Status_t I2C_Master_Start(void)
{
    i2c_wait_idle();
    SSPCON2bits.SEN = 1;       /* Initiate START */
    i2c_wait_flag();
    return I2C_OK;
}

/*------------------------------------------------------------
 * I2C_Master_RepeatedStart
 *------------------------------------------------------------*/
I2C_Status_t I2C_Master_RepeatedStart(void)
{
    i2c_wait_idle();
    SSPCON2bits.RSEN = 1;      /* Initiate Repeated START */
    i2c_wait_flag();
    return I2C_OK;
}

/*------------------------------------------------------------
 * I2C_Master_Stop
 *------------------------------------------------------------*/
void I2C_Master_Stop(void)
{
    i2c_wait_idle();
    SSPCON2bits.PEN = 1;       /* Initiate STOP */
    i2c_wait_flag();
}

/*------------------------------------------------------------
 * I2C_Master_WriteByte
 *------------------------------------------------------------*/
I2C_Status_t I2C_Master_WriteByte(uint8_t data)
{
    i2c_wait_idle();
    SSPBUF = data;             /* Load data / address byte */
    i2c_wait_flag();

    /* Check for write collision */
    if (SSPCONbits.WCOL) {
        SSPCONbits.WCOL = 0;
        return I2C_ERR_COLLISION;
    }

    /* Check ACK from slave (ACKSTAT: 0=ACK, 1=NACK) */
    if (SSPCON2bits.ACKSTAT) {
        return I2C_ERR_NACK;
    }

    return I2C_OK;
}

/*------------------------------------------------------------
 * I2C_Master_ReadByte
 *------------------------------------------------------------*/
uint8_t I2C_Master_ReadByte(I2C_Ack_t ackType)
{
    uint8_t data;

    i2c_wait_idle();

    /* Enable receive */
    SSPCON2bits.RCEN = 1;
    i2c_wait_flag();

    /* Read received byte */
    data = SSPBUF;

    /* Send ACK or NACK */
    i2c_wait_idle();
    SSPCON2bits.ACKDT = (uint8_t)ackType;   /* 0=ACK, 1=NACK */
    SSPCON2bits.ACKEN = 1;
    i2c_wait_flag();

    return data;
}

/*------------------------------------------------------------
 * I2C_Master_Write  — START, address+W, data[], STOP
 *------------------------------------------------------------*/
I2C_Status_t I2C_Master_Write(uint8_t devAddr,
                               const uint8_t *buf,
                               uint8_t len)
{
    I2C_Status_t status;
    uint8_t i;

    status = I2C_Master_Start();
    if (status != I2C_OK) return status;

    /* Send address byte with Write bit (bit0=0) */
    status = I2C_Master_WriteByte((uint8_t)(devAddr << 1u));
    if (status != I2C_OK) { I2C_Master_Stop(); return status; }

    for (i = 0u; i < len; i++) {
        status = I2C_Master_WriteByte(buf[i]);
        if (status != I2C_OK) { I2C_Master_Stop(); return status; }
    }

    I2C_Master_Stop();
    return I2C_OK;
}

/*------------------------------------------------------------
 * I2C_Master_Read  — START, address+R, data[], STOP
 *------------------------------------------------------------*/
I2C_Status_t I2C_Master_Read(uint8_t devAddr,
                              uint8_t *buf,
                              uint8_t len)
{
    I2C_Status_t status;
    uint8_t i;

    if (len == 0u) return I2C_OK;

    status = I2C_Master_Start();
    if (status != I2C_OK) return status;

    /* Send address byte with Read bit (bit0=1) */
    status = I2C_Master_WriteByte((uint8_t)((devAddr << 1u) | 0x01u));
    if (status != I2C_OK) { I2C_Master_Stop(); return status; }

    for (i = 0u; i < len; i++) {
        /* Send NACK after last byte, ACK for all others */
        I2C_Ack_t ack = (i < (len - 1u)) ? I2C_ACK : I2C_NACK;
        buf[i] = I2C_Master_ReadByte(ack);
    }

    I2C_Master_Stop();
    return I2C_OK;
}

/*------------------------------------------------------------
 * I2C_Master_WriteRead
 * Pattern: START → addr+W → regAddr → RSTART → addr+R → data[] → STOP
 *------------------------------------------------------------*/
I2C_Status_t I2C_Master_WriteRead(uint8_t devAddr,
                                   uint8_t regAddr,
                                   uint8_t *buf,
                                   uint8_t len)
{
    I2C_Status_t status;
    uint8_t i;

    if (len == 0u) return I2C_OK;

    status = I2C_Master_Start();
    if (status != I2C_OK) return status;

    /* Write phase: address + register */
    status = I2C_Master_WriteByte((uint8_t)(devAddr << 1u));
    if (status != I2C_OK) { I2C_Master_Stop(); return status; }

    status = I2C_Master_WriteByte(regAddr);
    if (status != I2C_OK) { I2C_Master_Stop(); return status; }

    /* Repeated START then switch to read */
    status = I2C_Master_RepeatedStart();
    if (status != I2C_OK) { I2C_Master_Stop(); return status; }

    status = I2C_Master_WriteByte((uint8_t)((devAddr << 1u) | 0x01u));
    if (status != I2C_OK) { I2C_Master_Stop(); return status; }

    /* Read phase */
    for (i = 0u; i < len; i++) {
        I2C_Ack_t ack = (i < (len - 1u)) ? I2C_ACK : I2C_NACK;
        buf[i] = I2C_Master_ReadByte(ack);
    }

    I2C_Master_Stop();
    return I2C_OK;
}

/*------------------------------------------------------------
 * I2C_Slave_Init
 *------------------------------------------------------------*/
void I2C_Slave_Init(const I2C_SlaveConfig_t *cfg)
{
    /* SCL and SDA as inputs */
    TRISCbits.TRISC3 = 1;
    TRISCbits.TRISC4 = 1;

    SSPCONbits.SSPEN = 0;

    /* SSPADD — slave address (bits<7:1>; bit0 ignored) */
    SSPADD = (uint8_t)(cfg->slaveAddr << 1u);

    /* SSPCON — slave mode */
    SSPCON = (uint8_t)((uint8_t)cfg->mode & 0x0Fu);

    /* SSPSTAT — SMP */
    SSPSTAT = (uint8_t)((uint8_t)cfg->slewRate << 7);

    /* SSPCON2 */
    SSPCON2 = 0x00u;
    if (cfg->genCallEn) {
        SSPCON2bits.GCEN = 1;
    }

    /* Release SCL */
    SSPCONbits.CKP = 1;

    PIR1bits.SSPIF = 0;
    PIE1bits.SSPIE = (uint8_t)cfg->intEnable;

    SSPCONbits.SSPEN = 1;
}

/*------------------------------------------------------------
 * I2C_Enable / Disable
 *------------------------------------------------------------*/
void I2C_Enable(void)
{
    SSPCONbits.SSPEN = 1;
}

void I2C_Disable(void)
{
    SSPCONbits.SSPEN = 0;
}

/*------------------------------------------------------------
 * Weak callbacks
 *------------------------------------------------------------*/
void __attribute__((weak)) I2C_Slave_Callback(void) { }

/*============================================================
 * ISR dispatch (standalone; merge with project ISR)
 *============================================================*/
#ifdef I2C_USE_STANDALONE_ISR
void __interrupt() I2C_ISR(void)
{
    if (PIE1bits.SSPIE && PIR1bits.SSPIF) {
        PIR1bits.SSPIF = 0;
        I2C_Slave_Callback();   /* Slave events dispatched here */
    }
}
#endif
