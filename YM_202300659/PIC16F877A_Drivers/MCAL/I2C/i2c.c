/*
 * i2c.c
 * MCAL - I2C Driver Implementation for PIC16F877A (Master Mode)
 */

#include "i2c.h"
#include "i2c_private.h"

/* Wait for SSP interrupt flag (operation complete) */
static void I2C_WaitFlag(void)
{
    while(!((PIR1_REG >> PIR1_SSPIF) & 0x01));
    PIR1_REG &= ~(1 << PIR1_SSPIF);
}

/* Wait for MSSP idle (no pending operation) */
static void I2C_WaitIdle(void)
{
    /* Wait while: SEN/RSEN/PEN/RCEN/ACKEN set OR bus not idle */
    while( (SSPCON2_REG & 0x1F) || ((SSPSTAT_REG >> SSPSTAT_RW) & 0x01) );
}

void I2C_MasterInit(I2C_Speed_t speed)
{
    /* Set SDA and SCL as inputs (I2C module controls them) */
    TRISC_REG |= (1 << I2C_SCL_BIT) | (1 << I2C_SDA_BIT);

    /* Disable MSSP first */
    SSPCON_REG = 0x00;

    /* Configure I2C Master mode */
    SSPCON_REG  = I2C_MASTER_MODE;     /* SSPM = 1000 */
    SSPCON_REG |= (1 << SSPCON_SSPEN); /* Enable MSSP */

    /* Slew rate control off for standard speed */
    SSPSTAT_REG = (1 << SSPSTAT_SMP);

    /* Set baud rate */
    SSPADD_REG  = (u8)speed;

    /* Clear SSPCON2 */
    SSPCON2_REG = 0x00;

    /* Clear interrupt flag */
    PIR1_REG &= ~(1 << PIR1_SSPIF);
}

void I2C_Start(void)
{
    I2C_WaitIdle();
    SSPCON2_REG |= (1 << SSPCON2_SEN);  /* Initiate START */
    I2C_WaitFlag();
}

void I2C_RepeatedStart(void)
{
    I2C_WaitIdle();
    SSPCON2_REG |= (1 << SSPCON2_RSEN); /* Initiate REPEATED START */
    I2C_WaitFlag();
}

void I2C_Stop(void)
{
    I2C_WaitIdle();
    SSPCON2_REG |= (1 << SSPCON2_PEN);  /* Initiate STOP */
    I2C_WaitFlag();
}

I2C_Status_t I2C_SendByte(u8 data)
{
    I2C_WaitIdle();
    SSPBUF_REG = data;
    I2C_WaitFlag();

    /* Check ACK from slave (ACKSTAT=0 means ACK received) */
    if((SSPCON2_REG >> SSPCON2_ACKSTAT) & 0x01)
    {
        return I2C_NACK;
    }
    return I2C_ACK;
}

u8 I2C_ReceiveByte(u8 ack)
{
    u8 data;

    I2C_WaitIdle();

    /* Enable receive */
    SSPCON2_REG |= (1 << SSPCON2_RCEN);
    I2C_WaitFlag();

    data = SSPBUF_REG;

    I2C_WaitIdle();

    /* Send ACK or NACK */
    if(ack)
    {
        SSPCON2_REG &= ~(1 << SSPCON2_ACKDT);  /* ACK  = 0 */
    }
    else
    {
        SSPCON2_REG |=  (1 << SSPCON2_ACKDT);  /* NACK = 1 */
    }
    SSPCON2_REG |= (1 << SSPCON2_ACKEN);        /* Send it  */
    I2C_WaitFlag();

    return data;
}

I2C_Status_t I2C_MasterWrite(u8 slaveAddr, const u8 *pData, u8 len)
{
    u8 i;
    I2C_Status_t status;

    I2C_Start();

    /* Send address with WRITE bit (bit0 = 0) */
    status = I2C_SendByte((u8)(slaveAddr << 1));
    if(status != I2C_ACK)
    {
        I2C_Stop();
        return I2C_NACK;
    }

    for(i = 0; i < len; i++)
    {
        status = I2C_SendByte(pData[i]);
        if(status != I2C_ACK)
        {
            I2C_Stop();
            return I2C_NACK;
        }
    }

    I2C_Stop();
    return I2C_OK;
}

I2C_Status_t I2C_MasterRead(u8 slaveAddr, u8 *pData, u8 len)
{
    u8 i;
    I2C_Status_t status;

    I2C_Start();

    /* Send address with READ bit (bit0 = 1) */
    status = I2C_SendByte((u8)((slaveAddr << 1) | 0x01));
    if(status != I2C_ACK)
    {
        I2C_Stop();
        return I2C_NACK;
    }

    for(i = 0; i < len; i++)
    {
        /* ACK all bytes except the last */
        pData[i] = I2C_ReceiveByte((i < (len - 1)) ? 1 : 0);
    }

    I2C_Stop();
    return I2C_OK;
}

I2C_Status_t I2C_WriteRegister(u8 slaveAddr, u8 regAddr, u8 data)
{
    u8 buf[2];
    buf[0] = regAddr;
    buf[1] = data;
    return I2C_MasterWrite(slaveAddr, buf, 2);
}

u8 I2C_ReadRegister(u8 slaveAddr, u8 regAddr)
{
    u8 data = 0;

    /* Write register address */
    I2C_Start();
    I2C_SendByte((u8)(slaveAddr << 1));
    I2C_SendByte(regAddr);

    /* Repeated start then read */
    I2C_RepeatedStart();
    I2C_SendByte((u8)((slaveAddr << 1) | 0x01));
    data = I2C_ReceiveByte(0);   /* NACK = last byte */

    I2C_Stop();
    return data;
}

u8 I2C_IsBusFree(void)
{
    return !((SSPCON2_REG & 0x1F) || ((SSPSTAT_REG >> SSPSTAT_RW) & 0x01));
}
