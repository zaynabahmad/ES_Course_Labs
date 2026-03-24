#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

/* ── Wait until the MSSP hardware is idle ── */
static void I2C_WaitIdle(void)
{
    /* Wait while transmitting OR any condition in progress */
    while (
        (SSPSTAT & 0x04) ||          /* R/W bit = transmitting        */
        (SSPCON2 & 0x1F)             /* SEN/RSEN/PEN/RCEN/ACKEN busy  */
    );
}

/* ── Wait for buffer full (byte received) ── */
static void I2C_WaitBF(void)
{
    while (GET_BIT(SSPSTAT, SSPSTAT_BF) == 0);
}

/* ────────────────────────────────────────────── */

void I2C_Init(void)
{
    /* RC3 (SCL) and RC4 (SDA) must be inputs for MSSP module */
    SET_BIT(TRISC, TRISC3);
    SET_BIT(TRISC, TRISC4);

    /* Disable slew rate control for 100 kHz */
    SET_BIT(SSPSTAT, SSPSTAT_SMP);
    CLR_BIT(SSPSTAT, SSPSTAT_CKE);

    /* Set baud rate */
    SSPADD = I2C_BAUD_RATE_VAL;

    /* SSPCON: Master I2C mode = 0b1000 on bits 3:0, enable MSSP */
    SSPCON = 0x28;   /* SSPEN=1, I2C Master mode (SSPM=1000) */
}

void I2C_Start(void)
{
    I2C_WaitIdle();
    SET_BIT(SSPCON2, SSPCON2_SEN);   /* Initiate Start condition */
    I2C_WaitIdle();
}

void I2C_RepeatedStart(void)
{
    I2C_WaitIdle();
    SET_BIT(SSPCON2, SSPCON2_RSEN);  /* Initiate Repeated Start  */
    I2C_WaitIdle();
}

void I2C_Stop(void)
{
    I2C_WaitIdle();
    SET_BIT(SSPCON2, SSPCON2_PEN);   /* Initiate Stop condition  */
    I2C_WaitIdle();
}

u8 I2C_WriteByte(u8 data)
{
    I2C_WaitIdle();
    SSPBUF = data;                   /* Load byte → starts transmission */
    I2C_WaitIdle();

    /* Return ACK status: 0 = ACK received, 1 = NACK */
    if (GET_BIT(SSPCON2, SSPCON2_ACKSTAT) == 0)
        return I2C_ACK;
    else
        return I2C_NACK;
}

u8 I2C_ReadByte_ACK(void)
{
    u8 data;
    I2C_WaitIdle();

    SET_BIT(SSPCON2, SSPCON2_RCEN);  /* Enable receive mode      */
    I2C_WaitBF();                    /* Wait for byte            */
    data = SSPBUF;

    /* Send ACK */
    I2C_WaitIdle();
    CLR_BIT(SSPCON2, SSPCON2_ACKDT); /* ACKDT=0 → ACK            */
    SET_BIT(SSPCON2, SSPCON2_ACKEN); /* Send ACK sequence        */
    I2C_WaitIdle();

    return data;
}

u8 I2C_ReadByte_NACK(void)
{
    u8 data;
    I2C_WaitIdle();

    SET_BIT(SSPCON2, SSPCON2_RCEN);  /* Enable receive mode      */
    I2C_WaitBF();                    /* Wait for byte            */
    data = SSPBUF;

    /* Send NACK (last byte signal) */
    I2C_WaitIdle();
    SET_BIT(SSPCON2, SSPCON2_ACKDT); /* ACKDT=1 → NACK           */
    SET_BIT(SSPCON2, SSPCON2_ACKEN); /* Send NACK sequence       */
    I2C_WaitIdle();

    return data;
}

/* ── Full write transaction ── */
u8 I2C_MasterWrite(u8 addr, u8 *data, u8 len)
{
    u8 i;
    u8 status;

    I2C_Start();

    /* Send address with write bit (LSB = 0) */
    status = I2C_WriteByte((addr << 1) | 0x00);
    if (status == I2C_NACK)
    {
        I2C_Stop();
        return I2C_NACK;
    }

    for (i = 0; i < len; i++)
    {
        status = I2C_WriteByte(data[i]);
        if (status == I2C_NACK)
        {
            I2C_Stop();
            return I2C_NACK;
        }
    }

    I2C_Stop();
    return I2C_OK;
}

/* ── Full read transaction ── */
u8 I2C_MasterRead(u8 addr, u8 *buf, u8 len)
{
    u8 i;
    u8 status;

    I2C_Start();

    /* Send address with read bit (LSB = 1) */
    status = I2C_WriteByte((addr << 1) | 0x01);
    if (status == I2C_NACK)
    {
        I2C_Stop();
        return I2C_NACK;
    }

    for (i = 0; i < len; i++)
    {
        if (i < (len - 1u))
            buf[i] = I2C_ReadByte_ACK();   /* ACK all except last  */
        else
            buf[i] = I2C_ReadByte_NACK();  /* NACK on last byte    */
    }

    I2C_Stop();
    return I2C_OK;
}
