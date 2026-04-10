#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"

void MI2C_voidWait(void)
{
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void MI2C_voidMasterInit(void)
{
    SSPCON = 0x28;
    SSPCON2 = 0x00;
    SSPSTAT = 0x00;

    SSPADD = (u8)(((_XTAL_FREQ / 4) / I2C_BAUD_RATE) - 1);

    SET_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);
}

void MI2C_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
    SET_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);
    
    SSPADD = Copy_u8SlaveAddress;

    SSPSTAT = 0x80;
    SSPCON = 0x36;
    
    SSPCON2 = 0x01;
}

void MI2C_voidStart(void)
{
    MI2C_voidWait();
    SET_BIT(SSPCON2, SEN);
}

void MI2C_voidRepeatedStart(void)
{
    MI2C_voidWait();
    SET_BIT(SSPCON2, RSEN);
}

void MI2C_voidStop(void)
{
    MI2C_voidWait();
    SET_BIT(SSPCON2, PEN);
}

u8 MI2C_u8WriteByte(u8 Copy_u8Data)
{
    MI2C_voidWait();
    SSPBUF = Copy_u8Data;
    MI2C_voidWait();

    return GET_BIT(SSPCON2, ACKSTAT);
}

u8 MI2C_u8ReadByte(u8 Copy_u8AckParam)
{
    u8 Local_u8Data;

    MI2C_voidWait();
    SET_BIT(SSPCON2, RCEN);

    MI2C_voidWait();
    Local_u8Data = SSPBUF;

    MI2C_voidWait();
    if(Copy_u8AckParam == 0)
    {
        CLR_BIT(SSPCON2, ACKDT);
    }
    else
    {
        SET_BIT(SSPCON2, ACKDT);
    }
    SET_BIT(SSPCON2, ACKEN);
    return Local_u8Data;
}