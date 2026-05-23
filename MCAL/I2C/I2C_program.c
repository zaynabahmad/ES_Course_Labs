#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\STD_TYPES.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\BIT_MATH.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\I2C\I2C_private.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\I2C\I2C_interface.h"

/* ---------------------------------------------------------- */
void I2C_voidWaitIdle(void)
{

    while (((SSPCON2 & 0x1Fu) != 0u) ||
           (GET_BIT(SSPSTAT, SSPSTAT_R_W) != 0u))
    {
        /* spin */
    }
}

/* ---------------------------------------------------------- */
void I2C_voidInit(void)
{

    SET_BIT(TRISC, I2C_SCL_PIN);
    SET_BIT(TRISC, I2C_SDA_PIN);
    
    SSPCON = I2C_MASTER_MODE;

    SSPADD = I2C_SSPADD_100K;
    
    SET_BIT(SSPCON, 5u);
    
    CLR_BIT(PIR1, PIR1_SSPIF);
}

/* ---------------------------------------------------------- */
void I2C_voidStart(void)
{
    /* Wait until bus is free before asserting Start */
    I2C_voidWaitIdle();

    /* Assert Start condition */
    SET_BIT(SSPCON2, SSPCON2_SEN);


    while (GET_BIT(SSPCON2, SSPCON2_SEN))
    {
        /* spin */
    }
}

/* ---------------------------------------------------------- */
void I2C_voidRepeatedStart(void)
{
    I2C_voidWaitIdle();
    SET_BIT(SSPCON2, SSPCON2_RSEN);
    while (GET_BIT(SSPCON2, SSPCON2_RSEN))
    {
        /* spin */
    }
}

/* ---------------------------------------------------------- */
void I2C_voidStop(void)
{
    I2C_voidWaitIdle();

    /* Assert Stop condition */
    SET_BIT(SSPCON2, SSPCON2_PEN);


    while (GET_BIT(SSPCON2, SSPCON2_PEN))
    {
        /* spin */
    }
}

/* ---------------------------------------------------------- */
unsigned char I2C_u8Write(unsigned char data)
{
    /* Wait for bus to be idle before loading the buffer */
    I2C_voidWaitIdle();

    /* Load data into transmit buffer — this starts transmission */
    SSPBUF = data;
    
    while (GET_BIT(SSPSTAT, SSPSTAT_BF))
    {
        /* spin */
    }

    /* Wait for idle again (ensures ACK/NACK cycle finished) */
    I2C_voidWaitIdle();


    if (GET_BIT(SSPCON2, SSPCON2_ACKSTAT) == 1u)
    {
        return I2C_ERR_NACK;
    }

    return I2C_OK;
}

/* ---------------------------------------------------------- */
unsigned char I2C_u8Read(unsigned char send_ack)
{
    unsigned char received;

    I2C_voidWaitIdle();

    /* Enable receive mode */
    SET_BIT(SSPCON2, SSPCON2_RCEN);

    /* Wait until the full byte has been received (BF set) */
    while (!GET_BIT(SSPSTAT, SSPSTAT_BF))
    {
        /* spin */
    }

    /* Read the received byte from the buffer */
    received = SSPBUF;

    I2C_voidWaitIdle();

    /* Send ACK or NACK to the slave */
    if (send_ack == 1u)
        CLR_BIT(SSPCON2, SSPCON2_ACKDT);   /* ACK  */
    else
        SET_BIT(SSPCON2, SSPCON2_ACKDT);   /* NACK */

    /* Initiate the ACK/NACK sequence */
    SET_BIT(SSPCON2, SSPCON2_ACKEN);

    /* Wait for ACK sequence to complete */
    while (GET_BIT(SSPCON2, SSPCON2_ACKEN))
    {
        /* spin */
    }

    return received;
}