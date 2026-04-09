#include "I2C_interface.h"
#include "I2C_private.h"
#include "../../SERVICES/BIT_MATH.h"

/* Wait until MSSP operation completes */
static void I2C_WaitIdle(void)
{
    /* Wait while any operation bit in SSPCON2 is set
     * or while the bus is transmitting (SSPSTAT R/W=1) */
    while ((SSPCON2 & 0x1F) || GET_BIT(SSPSTAT, SSPSTAT_R_W))
        ;
}

void I2C_MasterInit(u32 clock_hz)
{
    /*
     * RC3 = SCL  (set as input — hardware drives it)
     * RC4 = SDA  (set as input — hardware drives it)
     */
    SET_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);

    /* SSPM = 1000 → I2C Master mode, clock = Fosc/(4*(SSPADD+1)) */
    SET_BIT(SSPCON, SSPCON_SSPM3);
    CLR_BIT(SSPCON, SSPCON_SSPM2);
    CLR_BIT(SSPCON, SSPCON_SSPM1);
    CLR_BIT(SSPCON, SSPCON_SSPM0);

    /*
     * SSPADD = (Fosc / (4 * clock_hz)) - 1
     * For Fosc=4MHz, 100kHz: SSPADD = (4000000/(4*100000))-1 = 9
     */
    SSPADD = (u8)((4000000UL / (4UL * clock_hz)) - 1);

    /* Enable MSSP */
    SET_BIT(SSPCON, SSPCON_SSPEN);
}

void I2C_Start(void)
{
    I2C_WaitIdle();
    SET_BIT(SSPCON2, SSPCON2_SEN);
    I2C_WaitIdle();
}

void I2C_Stop(void)
{
    I2C_WaitIdle();
    SET_BIT(SSPCON2, SSPCON2_PEN);
    I2C_WaitIdle();
}

void I2C_RepeatedStart(void)
{
    I2C_WaitIdle();
    SET_BIT(SSPCON2, SSPCON2_RSEN);
    I2C_WaitIdle();
}

u8 I2C_WriteByte(u8 i2cData)
{
    I2C_WaitIdle();
    SSPBUF = i2cData;
    I2C_WaitIdle();
    /* Return ACK status: 0=ACK received, 1=NACK */
    return GET_BIT(SSPCON2, SSPCON2_ACKSTAT);
}
u8 I2C_ReadByte(u8 ack)
{
    /* 1. Declare at the very top, and rename from 'data' */
    u8 receivedData;

    I2C_WaitIdle();
    SET_BIT(SSPCON2, SSPCON2_RCEN); /* Enable receive */
    I2C_WaitIdle();

    /* 2. Assign the value down here */
    receivedData = SSPBUF;

    I2C_WaitIdle();
    /* Send ACK or NACK */
    if (ack == I2C_NACK)
        SET_BIT(SSPCON2, SSPCON2_ACKDT);
    else
        CLR_BIT(SSPCON2, SSPCON2_ACKDT);

    SET_BIT(SSPCON2, SSPCON2_ACKEN); /* Initiate ACK/NACK */
    I2C_WaitIdle();

    return receivedData; /* Return the new variable */
}