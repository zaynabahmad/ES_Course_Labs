#include "I2C_Interface.h"
#include "I2C_Private.h"
#include "I2C_Config.h"
#include "../../SERVICES/BIT_MATH.h"

void I2C_Master_Init(void)
{
    /* Configure SDA and SCL as inputs initially */
    SET_BIT(TRISC, 3); // SCL
    SET_BIT(TRISC, 4); // SDA
    
    /* Set I2C Master Mode */
    SSPCON = 0x28; // SSPEN = 1, I2C Master mode, clock = FOSC / (4 * (SSPADD+1))
    
    SSPCON2 = 0x00; // Clear all bits
    
    /* Set Baud Rate */
    SSPADD = I2C_SSPADD_VALUE;
    
    /* Disable Slew Rate Control for 100kHz */
    SET_BIT(SSPSTAT, 7); // SMP = 1
}

void I2C_Master_Wait(void)
{
    /* Wait for the I2C module to be idle */
    while ((SSPCON2 & 0x1F) || (SSPSTAT & 0x04));
}

void I2C_Master_Start(void)
{
    I2C_Master_Wait();
    SET_BIT(SSPCON2, SEN);
}

void I2C_Master_RepeatedStart(void)
{
    I2C_Master_Wait();
    SET_BIT(SSPCON2, RSEN);
}

void I2C_Master_Stop(void)
{
    I2C_Master_Wait();
    SET_BIT(SSPCON2, PEN);
}

u8 I2C_Master_Write(u8 Data)
{
    I2C_Master_Wait();
    SSPBUF = Data;
    I2C_Master_Wait();
    
    /* Return ACKSTAT bit (0 = ACK received, 1 = NACK received) */
    return GET_BIT(SSPCON2, ACKSTAT);
}

u8 I2C_Master_Read(u8 Ack)
{
    u8 Data;
    I2C_Master_Wait();
    
    /* Enable Receive Mode */
    SET_BIT(SSPCON2, RCEN);
    
    I2C_Master_Wait();
    Data = SSPBUF;
    I2C_Master_Wait();
    
    if (Ack)
    {
        CLR_BIT(SSPCON2, ACKDT); // Send ACK
    }
    else
    {
        SET_BIT(SSPCON2, ACKDT); // Send NACK
    }
    
    /* Initiate Acknowledge sequence */
    SET_BIT(SSPCON2, ACKEN);
    
    return Data;
}
