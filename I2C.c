#include "I2C_INTERFACE.h"
#include "I2C_PRIVATE.h"
#include "I2C_CONFIG.h"
#include "../SERVICES/BIT_MATH.h"

void I2C_Init(void)
{
    /* RC3=SCL and RC4=SDA must be inputs (open-drain handled by hardware) */
    SET_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);

    /* Set I2C clock via SSPADD */
    SSPADD = I2C_SSPADD_VALUE;

    /* I2C Master mode: SSPM3:SSPM0 = 1000 */
    SSPCON = (SSPCON & 0xF0) | 0x08;

    /* Disable slew rate control (standard speed 100 kHz) */
    SET_BIT(SSPSTAT, SMP);

    /* Enable SSP module */
    SET_BIT(SSPCON, SSPEN);
}

void I2C_Start(void)
{
    SET_BIT(SSPCON2, SEN);
    while(GET_BIT(SSPCON2, SEN) == 1);
}

void I2C_Stop(void)
{
    SET_BIT(SSPCON2, PEN);
    while(GET_BIT(SSPCON2, PEN) == 1);
}

void I2C_RepeatedStart(void)
{
    SET_BIT(SSPCON2, RSEN);
    while(GET_BIT(SSPCON2, RSEN) == 1);
}

u8 I2C_SendByte(u8 data)
{
    SSPBUF = data;
    while(GET_BIT(SSPSTAT, BF) == 1); /* Wait until byte is shifted out */
    /* ACKSTAT: 0=ACK received, 1=NACK received */
    return GET_BIT(SSPCON2, ACKSTAT);
}

u8 I2C_ReceiveByte(u8 ack)
{
    u8 data;

    SET_BIT(SSPCON2, RCEN);              /* Enable receive */
    while(GET_BIT(SSPCON2, RCEN) == 1); /* Wait for byte */
    data = SSPBUF;

    if(ack == I2C_SEND_ACK)
        I2C_SendAck();
    else
        I2C_SendNack();

    return data;
}

void I2C_SendAck(void)
{
    CLR_BIT(SSPCON2, ACKDT);  /* ACK = 0 */
    SET_BIT(SSPCON2, ACKEN);
    while(GET_BIT(SSPCON2, ACKEN) == 1);
}

void I2C_SendNack(void)
{
    SET_BIT(SSPCON2, ACKDT);  /* NACK = 1 */
    SET_BIT(SSPCON2, ACKEN);
    while(GET_BIT(SSPCON2, ACKEN) == 1);
}
