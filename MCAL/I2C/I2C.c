#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "I2C_private.h"
#include "I2C_config.h"
#include "I2C_interface.h"

/* ================= WAIT FUNCTION ================= */
static void I2C_voidWait(void)
{
    /* Wait until idle */
    while ((SSPCON2 & 0x1F) || (GET_BIT(SSPSTAT, 2)));
}

/* ================= INIT ================= */
void I2C_voidInitMaster(void)
{
    /* 1. Configure Pins (I2C requires input) */
    SET_BIT(TRISC, 3); // SCL
    SET_BIT(TRISC, 4); // SDA

    /* 2. Set Master Mode */
    SSPCON &= 0b11110000;
    SSPCON |= 0b00001000;

    /* 3. Set Baud Rate */
    SSPADD = (u8)((I2C_F_OSC / (4UL * I2C_CLOCK_SPEED)) - 1);

    /* 4. Slew Rate */
#if (I2C_CLOCK_SPEED == 100000UL)
    SET_BIT(SSPSTAT, SMP);   // Standard mode
#else
    CLR_BIT(SSPSTAT, SMP);   // High speed
#endif

    /* 5. Enable MSSP */
    SET_BIT(SSPCON, SSPEN);
}

/* ================= START ================= */
void I2C_voidStart(void)
{
    I2C_voidWait();
    SET_BIT(SSPCON2, SEN);
}

/* ================= REPEATED START ================= */
void I2C_voidRepeatedStart(void)
{
    I2C_voidWait();
    SET_BIT(SSPCON2, RSEN);
}

/* ================= STOP ================= */
void I2C_voidStop(void)
{
    I2C_voidWait();
    SET_BIT(SSPCON2, PEN);
}

/* ================= WRITE ================= */
u8 I2C_u8WriteByte(u8 Copy_u8Data)
{
    I2C_voidWait();

    SSPBUF = Copy_u8Data;

    I2C_voidWait();

    /* Return ACK status */
    return GET_BIT(SSPCON2, ACKSTAT);
}

/* ================= READ ================= */
u8 I2C_u8ReadByte(u8 Copy_u8AckNack)
{
    u8 Local_u8Data;

    I2C_voidWait();

    /* Enable Receive */
    SET_BIT(SSPCON2, RCEN);

    I2C_voidWait();

    /* Read data */
    Local_u8Data = SSPBUF;

    I2C_voidWait();

    /* Prepare ACK/NACK */
    if (Copy_u8AckNack == I2C_ACK)
    {
        CLR_BIT(SSPCON2, ACKDT);
    }
    else
    {
        SET_BIT(SSPCON2, ACKDT);
    }

    /* Send ACK/NACK */
    SET_BIT(SSPCON2, ACKEN);

    return Local_u8Data;
}