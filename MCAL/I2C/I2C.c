#include "I2C_Interface.h"

/* ================= Initialization ================= */

void I2C_Init(void)
{
    /* Set RC3 (SCL) and RC4 (SDA) as inputs (I2C open-drain) */
    SET_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);

    /* Disable SSP before configuring */
    CLR_BIT(SSPCON, SSPEN);

    /* Clear SSPCON mode bits */
    SSPCON &= 0xF0;

#if I2C_MODE == I2C_MASTER
    /* Master mode: SSPM = 1000 */
    SET_BIT(SSPCON, SSPM3);
    CLR_BIT(SSPCON, SSPM2);
    CLR_BIT(SSPCON, SSPM1);
    CLR_BIT(SSPCON, SSPM0);

    /* Set baud rate: SSPADD = (FOSC / (4 * I2C_CLOCK_FREQ)) - 1 */
    SSPADD = (u8)((FOSC / (4UL * I2C_CLOCK_FREQ)) - 1);

#else
    /* Slave mode 7-bit address: SSPM = 0110 */
    CLR_BIT(SSPCON, SSPM3);
    SET_BIT(SSPCON, SSPM2);
    SET_BIT(SSPCON, SSPM1);
    CLR_BIT(SSPCON, SSPM0);

    /* Set slave address (7-bit shifted left) */
    SSPADD = (u8)(I2C_SLAVE_ADDRESS << 1);
#endif

    /* Slew rate control disabled for 100kHz */
    SET_BIT(SSPSTAT, SMP);

    /* Enable SSP */
    SET_BIT(SSPCON, SSPEN);
}

/* ================= Generate Start Condition ================= */

void I2C_Start(void)
{
    /* Initiate start condition */
    SET_BIT(SSPCON2, SEN);

    /* Wait for start condition to complete */
    while(GET_BIT(SSPCON2, SEN));
}

/* ================= Generate Repeated Start ================= */

void I2C_RepeatedStart(void)
{
    SET_BIT(SSPCON2, RSEN);
    while(GET_BIT(SSPCON2, RSEN));
}

/* ================= Generate Stop Condition ================= */

void I2C_Stop(void)
{
    SET_BIT(SSPCON2, PEN);
    while(GET_BIT(SSPCON2, PEN));
}

/* ================= Send One Byte ================= */

void I2C_SendByte(u8 Data)
{
    /* Load data into buffer */
    SSPBUF = Data;

    /* Wait for transmission to complete */
    while(GET_BIT(SSPSTAT, R_W));
}

/* ================= Receive One Byte ================= */

u8 I2C_ReceiveByte(u8 Ack)
{
    u8 Data;

    /* Enable receive mode */
    SET_BIT(SSPCON2, RCEN);

    /* Wait until buffer is full */
    while(!GET_BIT(SSPSTAT, BF));

    Data = SSPBUF;

    /* Send ACK or NACK */
    if(Ack == 1)
    {
        I2C_SendACK();
    }
    else
    {
        I2C_SendNACK();
    }

    return Data;
}

/* ================= Get Acknowledge Status ================= */

u8 I2C_GetAck(void)
{
    return GET_BIT(SSPCON2, ACKSTAT);   /* 0 = ACK received, 1 = NACK */
}

/* ================= Send ACK ================= */

void I2C_SendACK(void)
{
    CLR_BIT(SSPCON2, ACKDT);    /* ACKDT = 0 -> ACK */
    SET_BIT(SSPCON2, ACKEN);
    while(GET_BIT(SSPCON2, ACKEN));
}

/* ================= Send NACK ================= */

void I2C_SendNACK(void)
{
    SET_BIT(SSPCON2, ACKDT);    /* ACKDT = 1 -> NACK */
    SET_BIT(SSPCON2, ACKEN);
    while(GET_BIT(SSPCON2, ACKEN));
}
