/**
 * @file    I2C.c
 * @brief   MSSP I2C (master) driver implementation for the PIC16F877A.
 *
 * @details Every master event -- start, stop, byte transfer, ack -- ends by
 *          raising SSPIF. The driver funnels all of them through one wait
 *          helper, so each public function reads as "trigger, then settle"
 *          and the flag handling lives in exactly one place.
 */
#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_cfg.h"
#include "../SERVICES/Macros.h"

/**
 * @brief  Block until the MSSP signals the current event is done, then drop
 *         the flag so the next event starts from a clean state.
 */
static void vWaitEvent(void)
{
    while (BIT_IS_CLEARED(I2C_REG_PIR1, I2C_BIT_SSPIF))
    {
        /* spin */
    }

    BIT_LOW(I2C_REG_PIR1, I2C_BIT_SSPIF);
}

void vI2C_MasterInit(void)
{
    /* SCL and SDA must be inputs -- the MSSP drives them, not the port latch. */
    BIT_HIGH(I2C_REG_TRISC, I2C_PIN_SCL);
    BIT_HIGH(I2C_REG_TRISC, I2C_PIN_SDA);

    /* SSPADD = Fosc / (4 * Fscl) - 1; integer divide is exact for the usual
     * 100 k / 400 k targets at 20 MHz. */
    I2C_REG_SSPADD = (byte_t)((I2C_FOSC_HZ / (4uL * I2C_SCL_FREQ)) - 1uL);

    I2C_REG_SSPCON = I2C_MODE_MASTER;           /* SSPM3:0 = I2C master. */
    BIT_HIGH(I2C_REG_SSPCON, I2C_BIT_SSPEN);    /* enable the port.      */
}

void vI2C_Start(void)
{
    BIT_HIGH(I2C_REG_SSPCON2, I2C_BIT_SEN);     /* arm the start condition. */
    vWaitEvent();
}

void vI2C_Stop(void)
{
    BIT_HIGH(I2C_REG_SSPCON2, I2C_BIT_PEN);     /* arm the stop condition. */
    vWaitEvent();
}

eOutcome_t u8I2C_Write(byte_t u8Data)
{
    I2C_REG_SSPBUF = u8Data;                    /* loading the buffer sends it. */
    vWaitEvent();

    /* ACKSTAT mirrors the slave's response: 0 means it acknowledged. */
    return BIT_IS_CLEARED(I2C_REG_SSPCON2, I2C_BIT_ACKSTAT) ? OUTCOME_OK
                                                            : OUTCOME_FAIL;
}

byte_t u8I2C_Read(flag_t bAck)
{
    byte_t u8Received;

    BIT_HIGH(I2C_REG_SSPCON2, I2C_BIT_RCEN);    /* enable one receive cycle. */
    vWaitEvent();
    u8Received = I2C_REG_SSPBUF;                /* latch the byte before ack. */

    /* ACKDT chooses the level: 0 acknowledges, 1 signals "no more, please". */
    switch (bAck)
    {
        case FLAG_RAISED:  BIT_LOW(I2C_REG_SSPCON2, I2C_BIT_ACKDT);  break;
        default:           BIT_HIGH(I2C_REG_SSPCON2, I2C_BIT_ACKDT); break;
    }

    BIT_HIGH(I2C_REG_SSPCON2, I2C_BIT_ACKEN);   /* clock out the ack bit. */
    vWaitEvent();

    return u8Received;
}
