#include "I2C_interface.h"
#include "I2C_config.h"
#include "I2C_private.h"
#include "../../SERVICES/Bit_Math.h"

void I2C_Init(void)
{
    /* Configure SDA and SCL as inputs before enabling MSSP in I2C mode */
    TRISC_REG |= (1 << SDA_BIT) | (1 << SCL_BIT);

    /* I2C Master mode, clock = Fosc / (4 * (SSPADD + 1)), enable MSSP */
    SSPCON_REG = (1 << SSPEN_BIT) | 0x08;
    SSPADD_REG = I2C_BRG_VALUE;

    /* Use standard speed and sample from middle of data output time */
    SSPSTAT_REG &= ~(1 << 7);
}

void I2C_Start(void)
{
    SET_BIT(SSPCON2_REG, SEN_BIT);
    while (GET_BIT(SSPCON2_REG, SEN_BIT));
}

void I2C_ReStart(void)
{
    SET_BIT(SSPCON2_REG, RSEN_BIT);
    while (GET_BIT(SSPCON2_REG, RSEN_BIT));
}

void I2C_Stop(void)
{
    SET_BIT(SSPCON2_REG, PEN_BIT);
    while (GET_BIT(SSPCON2_REG, PEN_BIT));
}

u8 I2C_WriteByte(u8 data)
{
    SSPBUF_REG = data;
    while (GET_BIT(SSPSTAT_REG, BF_BIT));
    while (SSPCON2_REG & ((1 << SEN_BIT) | (1 << RSEN_BIT) | (1 << PEN_BIT) | (1 << RCEN_BIT) | (1 << ACKEN_BIT)));
    return GET_BIT(SSPCON2_REG, ACKSTAT_BIT);
}

u8 I2C_ReadByte(void)
{
    SET_BIT(SSPCON2_REG, RCEN_BIT);
    while (!GET_BIT(SSPSTAT_REG, BF_BIT));
    return SSPBUF_REG;
}

void I2C_SendAck(void)
{
    CLR_BIT(SSPCON2_REG, ACKDT_BIT);
    SET_BIT(SSPCON2_REG, ACKEN_BIT);
    while (GET_BIT(SSPCON2_REG, ACKEN_BIT));
}

void I2C_SendNack(void)
{
    SET_BIT(SSPCON2_REG, ACKDT_BIT);
    SET_BIT(SSPCON2_REG, ACKEN_BIT);
    while (GET_BIT(SSPCON2_REG, ACKEN_BIT));
}
