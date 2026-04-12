#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"
#include "../../SERVICES/BIT_MATH.h"

void I2C_Init(void)
{
    /* Set SDA(RC4) and SCL(RC3) as inputs (I2C hardware controls them) */
    SET_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);

    /* Set clock speed via SSPADD */
    SSPADD = I2C_SSPADD_VALUE;

    /* SSPSTAT: Slew rate disabled for 100KHz */
    SSPSTAT = 0x80;

    /* SSPCON: Enable SSP, I2C Master mode (0x08) */
    SSPCON = 0x28;

    /* SSPCON2: Clear all */
    SSPCON2 = 0x00;
}

void I2C_Start(void)
{
    /* Set SEN bit to initiate Start condition */
    SET_BIT(SSPCON2, 0);

    /* Wait until Start condition is complete */
    while(GET_BIT(SSPCON2, 0));
}

void I2C_Stop(void)
{
    /* Set PEN bit to initiate Stop condition */
    SET_BIT(SSPCON2, 2);

    /* Wait until Stop condition is complete */
    while(GET_BIT(SSPCON2, 2));
}

void I2C_RepeatedStart(void)
{
    /* Set RSEN bit */
    SET_BIT(SSPCON2, 1);

    /* Wait until complete */
    while(GET_BIT(SSPCON2, 1));
}

u8 I2C_SendByte(u8 Data)
{
    /* Write data to buffer */
    SSPBUF = Data;

    /* Wait until transmission complete (SSPIF in PIR1) */
    while(!GET_BIT(PIR1, 3));

    /* Clear SSPIF flag */
    CLR_BIT(PIR1, 3);

    /* Return ACK status: ACKSTAT bit6 of SSPCON2 */
    return GET_BIT(SSPCON2, 6);
}

u8 I2C_ReceiveByte(u8 ACK)
{
    u8 Local_Data;

    /* Enable receive mode: set RCEN bit */
    SET_BIT(SSPCON2, 3);

    /* Wait until buffer full */
    while(!GET_BIT(SSPSTAT, 0));

    /* Read data */
    Local_Data = SSPBUF;

    /* Send ACK or NACK */
    if(ACK == 1)
        CLR_BIT(SSPCON2, 5);  /* ACK  */
    else
        SET_BIT(SSPCON2, 5);  /* NACK */

    /* Initiate ACK sequence */
    SET_BIT(SSPCON2, 4);

    /* Wait until ACK complete */
    while(GET_BIT(SSPCON2, 4));

    return Local_Data;
}