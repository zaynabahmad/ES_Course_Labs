#include "I2C_private.h"
#include "I2C_config.h"
#include "I2C_interface.h"
#include "../GPIO/GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"

#if MSSP_ACTIVE_MODE != MSSP_MODE_I2C

/* --- I2C disabled: MSSP configured for SPI --- */
void I2C_Init(void)                      {}
void I2C_Start(void)                     {}
void I2C_Stop(void)                      {}
void I2C_RepeatedStart(void)             {}
u8   I2C_WriteByte(u8 Data)              { (void)Data; return I2C_OK; }
u8   I2C_ReadByte(u8 SendAck)            { (void)SendAck; return 0; }

#else

/* --- Full I2C Master implementation --- */

/* Wait until the MSSP is idle (no operation in progress) */
static void i2c_wait(void)
{
    while ((SSPCON2 & 0x1F) || GET_BIT(SSPSTAT, 2)) {}
}

void I2C_Init(void)
{
    /* RC3=SCL, RC4=SDA — open-drain, set as inputs initially */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);

    /* SSPADD: baud rate */
    SSPADD = I2C_SSPADD_VALUE;

    /* SSPSTAT: slew rate */
#if I2C_SMP_BIT_VALUE
    SET_BIT(SSPSTAT, SMP_BIT);
#else
    CLR_BIT(SSPSTAT, SMP_BIT);
#endif

    /* SSPCON: I2C Master mode — SSPM<3:0> = 1000 */
    SSPCON = (SSPCON & 0xF0) | 0x08;

    /* Enable MSSP */
    SET_BIT(SSPCON, SSPEN_BIT);
}

void I2C_Start(void)
{
    i2c_wait();
    SET_BIT(SSPCON2, SEN_BIT);
    i2c_wait();
}

void I2C_Stop(void)
{
    i2c_wait();
    SET_BIT(SSPCON2, PEN_BIT);
    i2c_wait();
}

void I2C_RepeatedStart(void)
{
    i2c_wait();
    SET_BIT(SSPCON2, RSEN_BIT);
    i2c_wait();
}

u8 I2C_WriteByte(u8 Data)
{
    i2c_wait();
    SSPBUF = Data;
    i2c_wait();
    /* ACKSTAT: 0=ACK received, 1=NACK */
    return GET_BIT(SSPCON2, ACKSTAT_BIT) ? I2C_NACK : I2C_OK;
}

u8 I2C_ReadByte(u8 SendAck)
{
    u8 data;

    i2c_wait();
    SET_BIT(SSPCON2, RCEN_BIT);    /* Enable receive */
    i2c_wait();

    data = SSPBUF;

    /* Send ACK or NACK */
    if (SendAck)
        CLR_BIT(SSPCON2, ACKDT_BIT);  /* ACK */
    else
        SET_BIT(SSPCON2, ACKDT_BIT);  /* NACK */

    SET_BIT(SSPCON2, ACKEN_BIT);
    i2c_wait();

    return data;
}

#endif /* MSSP_ACTIVE_MODE */
