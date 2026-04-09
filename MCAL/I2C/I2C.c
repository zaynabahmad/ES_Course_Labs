#include "I2C_Interface.h"
#include "I2C_Private.h"
#include "I2C_Config.h"

#include "../../SERVICES/BIT_MATH.h"

/* Wait for MSSP interrupt flag (SSPIF) to be set, then clear it */
static void I2C_Wait(void)
{
    while (GET_BIT(PIR1, SSPIF) == 0);
    CLR_BIT(PIR1, SSPIF);
}

void I2C_Master_Init(void)
{
    /* Configure SSPADD for the desired Baud Rate */
    /* Formula: SSPADD = (FOSC / (4 * BaudRate)) - 1 */
    SSPADD = (u8)((I2C_FOSC / (4 * I2C_BAUDRATE)) - 1);

    /* Set I2C Master Mode in SSPCON (SSPM3:SSPM0 = 1000) */
    CLR_BIT(SSPCON, SSPM0);
    CLR_BIT(SSPCON, SSPM1);
    CLR_BIT(SSPCON, SSPM2);
    SET_BIT(SSPCON, SSPM3);

    /* Enable MSSP Module (SSPEN = 1) */
    SET_BIT(SSPCON, SSPEN);
}

void I2C_Start(void)
{
    /* Initiate Start Condition */
    SET_BIT(SSPCON2, SEN);
    I2C_Wait();
}

void I2C_Repeated_Start(void)
{
    /* Initiate Repeated Start Condition */
    SET_BIT(SSPCON2, RSEN);
    I2C_Wait();
}

void I2C_Stop(void)
{
    /* Initiate Stop Condition */
    SET_BIT(SSPCON2, PEN);
    I2C_Wait();
}

void I2C_Write(u8 Data)
{
    /* Load Data to buffer */
    SSPBUF = Data;
    I2C_Wait();
}

u8 I2C_Read(u8 Ack)
{
    u8 Local_Data;

    /* Enable Receive (RCEN = 1) */
    SET_BIT(SSPCON2, RCEN);
    I2C_Wait();

    /* Read Data */
    Local_Data = SSPBUF;

    /* Acknowledge Action */
    if (Ack == 1)
    {
        /* Send ACK (ACKDT = 0) */
        CLR_BIT(SSPCON2, ACKDT);
    }
    else
    {
        /* Send NACK (ACKDT = 1) */
        SET_BIT(SSPCON2, ACKDT);
    }

    /* Initiate Acknowledge Sequence (ACKEN = 1) */
    SET_BIT(SSPCON2, ACKEN);
    I2C_Wait();

    return Local_Data;
}

void I2C_Slave_Init(u8 Slave_Address)
{
    /* Set I2C Slave Mode (7-bit address) in SSPCON (SSPM3:SSPM0 = 0110) */
    CLR_BIT(SSPCON, SSPM0);
    SET_BIT(SSPCON, SSPM1);
    SET_BIT(SSPCON, SSPM2);
    CLR_BIT(SSPCON, SSPM3);

    /* Assign Slave Address */
    SSPADD = Slave_Address;

    /* Enable Clock Stretching (SEN = 1 in Slave mode) */
    SET_BIT(SSPCON2, SEN);

    /* Release Clock if it was held */
    SET_BIT(SSPCON, CKP);

    /* Enable MSSP Module */
    SET_BIT(SSPCON, SSPEN);
}

u8 I2C_Slave_Read(void)
{
    u8 Local_Data;

    /* Wait until reception completes */
    I2C_Wait();

    /* Read Received Data (Clears BF automatically) */
    Local_Data = SSPBUF;

    /* Release Clock stretching so master can continue */
    SET_BIT(SSPCON, CKP);

    return Local_Data;
}
