#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"
#include "../../SERVICES/BIT_MATH.h"

static u8 I2C_SlaveAddr = I2C_SLAVE_ADDRESS;
static u8 I2C_Mode = I2C_MASTER_SLAVE;

void I2C_Init(u8 Mode, u8 Address)
{
    I2C_Mode = Mode;
    I2C_SlaveAddr = Address;

    SET_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);

    if (Mode == I2C_MODE_MASTER)
    {
        SSPCON = 0x28;
    }
    else
    {
        SSPCON = 0x36;
    }

    SSPSTAT = 0x00;

    if (Mode == I2C_MODE_MASTER)
    {
        I2C_SetSpeed(I2C_CLOCK_SPEED);
    }
    else
    {
        SSPADD = (Address << 1);
    }

    CLR_BIT(PIR1, SSPIF);

    if (I2C_INTERRUPT_ENABLE)
    {
        SET_BIT(PIE1, SSIE);
    }
}

void I2C_SetSpeed(u32 SpeedHz)
{
    u8 BaudValue;

    if (SpeedHz == I2C_SPEED_400KHZ)
    {
        BaudValue = 12;
    }
    else
    {
        BaudValue = 49;
    }

    SSPADD = BaudValue;
}

void I2C_Start(void)
{
    SET_BIT(SSPCON, 0);

    while (GET_BIT(SSPCON, 0));

    CLR_BIT(PIR1, SSPIF);
}

void I2C_Stop(void)
{
    SET_BIT(SSPCON, 2);

    while (GET_BIT(SSPCON, 2));

    CLR_BIT(PIR1, SSPIF);
}

u8 I2C_WriteByte(u8 Data)
{
    u8 Timeout = 0;

    SSPBUF = Data;

    while (GET_BIT(SSPSTAT, BF))
    {
        Timeout++;
        if (Timeout > 100)
            return I2C_ERROR_TIMEOUT;
    }

    CLR_BIT(PIR1, SSPIF);

    if (GET_BIT(SSPCON, WCOL))
    {
        CLR_BIT(SSPCON, WCOL);
        return I2C_ERROR_BUSY;
    }

    return I2C_SUCCESS;
}

u8 I2C_ReadByte(u8 ACK)
{
    u8 ReceivedData;

    SET_BIT(SSPCON, 3);

    while (GET_BIT(SSPCON, 3));

    ReceivedData = SSPBUF;

    if (ACK)
        I2C_SendACK();
    else
        I2C_SendNACK();

    return ReceivedData;
}

void I2C_SendACK(void)
{
    CLR_BIT(SSPCON, 5);
    SET_BIT(SSPCON, 4);

    while (GET_BIT(SSPCON, 4));

    CLR_BIT(PIR1, SSPIF);
}

void I2C_SendNACK(void)
{
    SET_BIT(SSPCON, 5);
    SET_BIT(SSPCON, 4);

    while (GET_BIT(SSPCON, 4));

    CLR_BIT(PIR1, SSPIF);
}

u8 I2C_WriteAddress(u8 Address, u8 ReadWrite)
{
    u8 AddressFrame;

    AddressFrame = (Address << 1) | (ReadWrite & 0x01);
    return I2C_WriteByte(AddressFrame);
}

u8 I2C_IsACKReceived(void)
{
    return (GET_BIT(SSPSTAT, 6) == 0);
}

void I2C_SetAddress(u8 Address)
{
    I2C_SlaveAddr = Address;
    if (I2C_Mode == I2C_MODE_SLAVE)
    {
        SSPADD = (Address << 1);
    }
}
