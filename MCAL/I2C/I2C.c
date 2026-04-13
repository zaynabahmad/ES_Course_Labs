#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"
#include "../../SERVICES/BIT_MATH.h"

static void (*I2C_Callback)(u8) = NULL_PTR;

void I2C_Init(u8 speedMode, u8 slaveAddress)
{
    u8 SSPADD_Value;

    SSPCON = I2C_MASTER_MODE;

    if (speedMode == I2C_SPEED_400KHZ)
        SSPADD_Value = 1;
    else
        SSPADD_Value = 9;

    SSPADD = SSPADD_Value;

    SSPCON2 = 0x00;
    SET_BIT(SSPCON, SSPEN);

    SET_BIT(TRISB, 6);
    SET_BIT(TRISB, 7);

    SET_BIT(INTCON, 7);
    SET_BIT(PIE1, SSPIE);
    CLR_BIT(PIR1, SSPIF);
}

void I2C_MasterStart(void)
{
    SET_BIT(SSPCON2, SEN);
    while (GET_BIT(SSPCON2, SEN));
}

void I2C_MasterStop(void)
{
    SET_BIT(SSPCON2, PEN);
    while (GET_BIT(SSPCON2, PEN));
}

void I2C_MasterRepeatedStart(void)
{
    SET_BIT(SSPCON2, RSEN);
    while (GET_BIT(SSPCON2, RSEN));
}

u8 I2C_MasterWrite(u8 data)
{
    u8 AckStatus;

    SSPBUF = data;

    while (!GET_BIT(PIR1, SSPIF));
    CLR_BIT(PIR1, SSPIF);

    AckStatus = GET_BIT(SSPCON2, ACKSTAT);

    return !AckStatus;
}

u8 I2C_MasterRead(u8 ackRequired)
{
    u8 RxData;

    SET_BIT(SSPCON2, RCEN);
    while (GET_BIT(SSPCON2, RCEN));

    RxData = SSPBUF;

    if (ackRequired)
        CLR_BIT(SSPCON2, ACKDT);
    else
        SET_BIT(SSPCON2, ACKDT);

    SET_BIT(SSPCON2, ACKEN);
    while (GET_BIT(SSPCON2, ACKEN));

    return RxData;
}

u8 I2C_SlaveRead(void)
{
    return SSPBUF;
}

void I2C_SlaveWrite(u8 data)
{
    SSPBUF = data;
}

u8 I2C_GetStatus(void)
{
    u8 Status = 0;

    if (GET_BIT(SSPSTAT, S))
        Status |= I2C_START_BIT;

    if (GET_BIT(SSPSTAT, P))
        Status |= I2C_STOP_BIT;

    if (!GET_BIT(SSPCON2, SEN) && !GET_BIT(SSPCON2, RSEN) &&
        !GET_BIT(SSPCON2, PEN) && !GET_BIT(SSPCON2, RCEN) &&
        !GET_BIT(SSPCON2, ACKEN))
    {
        Status |= I2C_OPERATION_IDLE;
    }

    return Status;
}

void I2C_SetCallback(void (*Callback)(u8))
{
    I2C_Callback = Callback;
}

void I2C_ISR(void)
{
    u8 I2C_Status;

    CLR_BIT(PIR1, SSPIF);
    I2C_Status = I2C_GetStatus();

    if (I2C_Callback != NULL_PTR)
        I2C_Callback(I2C_Status);
}
