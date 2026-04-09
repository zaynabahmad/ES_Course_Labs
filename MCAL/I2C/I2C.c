#include "I2C_Interface.h"
#include "I2C_Private.h"
#include "I2C_Config.h"

#include "../../SERVICES/BIT_MATH.h"

void I2C_MasterInit(u32 ClockHz)
{
    if (ClockHz == 0UL)
    {
        ClockHz = I2C_DEFAULT_CLK;
    }

    SET_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);

    SSPCON = 0x28;
    SSPSTAT = 0x00;
    SSPADD = (u8)((I2C_FOSC_HZ / (4UL * ClockHz)) - 1UL);
}

void I2C_Start(void)
{
    SET_BIT(SSPCON2, SEN_BIT);
    while (GET_BIT(SSPCON2, SEN_BIT) != 0U)
    {
    }
}

void I2C_RepeatedStart(void)
{
    SET_BIT(SSPCON2, RSEN_BIT);
    while (GET_BIT(SSPCON2, RSEN_BIT) != 0U)
    {
    }
}

void I2C_Stop(void)
{
    SET_BIT(SSPCON2, PEN_BIT);
    while (GET_BIT(SSPCON2, PEN_BIT) != 0U)
    {
    }
}

u8 I2C_Write(u8 Data)
{
    CLR_BIT(PIR1, SSPIF_BIT);
    SSPBUF = Data;

    while (GET_BIT(PIR1, SSPIF_BIT) == 0U)
    {
    }

    return GET_BIT(SSPCON2, ACKSTAT_BIT);
}

u8 I2C_ReadAck(void)
{
    u8 Local_Data;

    SET_BIT(SSPCON2, RCEN_BIT);
    while (GET_BIT(SSPSTAT, BF_BIT) == 0U)
    {
    }

    Local_Data = SSPBUF;

    CLR_BIT(SSPCON2, ACKDT_BIT);
    SET_BIT(SSPCON2, ACKEN_BIT);
    while (GET_BIT(SSPCON2, ACKEN_BIT) != 0U)
    {
    }

    return Local_Data;
}

u8 I2C_ReadNack(void)
{
    u8 Local_Data;

    SET_BIT(SSPCON2, RCEN_BIT);
    while (GET_BIT(SSPSTAT, BF_BIT) == 0U)
    {
    }

    Local_Data = SSPBUF;

    SET_BIT(SSPCON2, ACKDT_BIT);
    SET_BIT(SSPCON2, ACKEN_BIT);
    while (GET_BIT(SSPCON2, ACKEN_BIT) != 0U)
    {
    }

    return Local_Data;
}
