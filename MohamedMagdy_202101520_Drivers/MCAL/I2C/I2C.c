#include "I2C_Interface.h"

void I2C_MasterInit(void)
{
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);

    SSPADD = I2C_SSPADD_VALUE;

    SSPCON  = (u8)(I2C_MASTER_MODE | (1U << SSPEN_BIT));

    SSPCON2 = 0x00;

    SSPSTAT = 0x00;

    CLR_BIT(PIR1, SSPIF_BIT);
}

void I2C_Start(void)
{
    CLR_BIT(PIR1, SSPIF_BIT);
    SET_BIT(SSPCON2, SEN_BIT);
    while(!GET_BIT(PIR1, SSPIF_BIT)) { ; }
    CLR_BIT(PIR1, SSPIF_BIT);
}

void I2C_Stop(void)
{
    CLR_BIT(PIR1, SSPIF_BIT);
    SET_BIT(SSPCON2, PEN_BIT);
    while(!GET_BIT(PIR1, SSPIF_BIT)) { ; }
    CLR_BIT(PIR1, SSPIF_BIT);
}

void I2C_RepeatedStart(void)
{
    CLR_BIT(PIR1, SSPIF_BIT);
    SET_BIT(SSPCON2, RSEN_BIT);
    while(!GET_BIT(PIR1, SSPIF_BIT)) { ; }
    CLR_BIT(PIR1, SSPIF_BIT);
}

u8 I2C_WriteByte(u8 Data)
{
    CLR_BIT(PIR1, SSPIF_BIT);
    SSPBUF = Data;
    while(!GET_BIT(PIR1, SSPIF_BIT)) { ; }
    CLR_BIT(PIR1, SSPIF_BIT);

    return GET_BIT(SSPCON2, ACKSTAT_BIT);
}

u8 I2C_ReadByte(u8 ack)
{
    u8 data;

    CLR_BIT(PIR1, SSPIF_BIT);
    SET_BIT(SSPCON2, RCEN_BIT);
    while(!GET_BIT(PIR1, SSPIF_BIT)) { ; }
    CLR_BIT(PIR1, SSPIF_BIT);

    data = SSPBUF;

    if(ack == I2C_SEND_ACK)
    {
        CLR_BIT(SSPCON2, ACKDT_BIT);
    }
    else
    {
        SET_BIT(SSPCON2, ACKDT_BIT);
    }

    CLR_BIT(PIR1, SSPIF_BIT);
    SET_BIT(SSPCON2, ACKEN_BIT);
    while(!GET_BIT(PIR1, SSPIF_BIT)) { ; }
    CLR_BIT(PIR1, SSPIF_BIT);

    return data;
}

void I2C_Disable(void)
{
    CLR_BIT(SSPCON, SSPEN_BIT);
}
