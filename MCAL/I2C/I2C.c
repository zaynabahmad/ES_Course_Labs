#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"

void MI2C_voidWait(void)
{
    /* Wait until bus is idle (transmit/receive/start/stop operations finish) [cite: 415] */
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void MI2C_voidMasterInit(void)
{
    /* 1. Select I2C Master Mode (SSPM = 1000) [cite: 421] */
    SSPCON = 0x28;
    SSPCON2 = 0x00;
    SSPSTAT = 0x00;

    /* 2. Set Baud Rate [cite: 424] */
    SSPADD = (u8)(((_XTAL_FREQ / 4) / I2C_BAUD_RATE) - 1);

    /* 3. Configure RC3(SCL) and RC4(SDA) as inputs [cite: 425, 426] */
    SET_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);
}

void MI2C_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
    /* 1. Configure RC3 and RC4 as inputs [cite: 533, 534] */
    SET_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);

    /* 2. Set Slave Address [cite: 535] */
    SSPADD = Copy_u8SlaveAddress;

    /* 3. Disable Slew Rate Control (Standard Mode) [cite: 536] */
    SSPSTAT = 0x80;

    /* 4. Select I2C Slave Mode (7-bit) [cite: 537] */
    SSPCON = 0x36;

    /* 5. Enable Clock Stretching [cite: 538] */
    SSPCON2 = 0x01;
}

void MI2C_voidStart(void)
{
    MI2C_voidWait();
    SET_BIT(SSPCON2, SEN); /* Initiate Start condition [cite: 434] */
}

void MI2C_voidRepeatedStart(void)
{
    MI2C_voidWait();
    SET_BIT(SSPCON2, RSEN); /* Initiate Repeated Start [cite: 442] */
}

void MI2C_voidStop(void)
{
    MI2C_voidWait();
    SET_BIT(SSPCON2, PEN); /* Initiate Stop condition [cite: 409] */
}

u8 MI2C_u8WriteByte(u8 Copy_u8Data)
{
    MI2C_voidWait();
    SSPBUF = Copy_u8Data;   /* Load buffer [cite: 478] */
    MI2C_voidWait();

    return GET_BIT(SSPCON2, ACKSTAT); /* Return ACK/NACK status [cite: 480] */
}

u8 MI2C_u8ReadByte(u8 Copy_u8AckParam)
{
    u8 Local_u8Data;

    MI2C_voidWait();
    SET_BIT(SSPCON2, RCEN); /* Enable Reception [cite: 487] */

    MI2C_voidWait();
    Local_u8Data = SSPBUF;  /* Read received byte [cite: 490] */

    MI2C_voidWait();
    if(Copy_u8AckParam == 0)
    {
        CLR_BIT(SSPCON2, ACKDT); /* Prepare ACK [cite: 450] */
    }
    else
    {
        SET_BIT(SSPCON2, ACKDT); /* Prepare NACK [cite: 459] */
    }
    SET_BIT(SSPCON2, ACKEN);     /* Send ACK/NACK [cite: 451, 460] */

    return Local_u8Data;
}