#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"

/* SSPADD = (Fosc / (4 * BaudRate)) - 1
 * Example: (4MHz / (4 * 100kHz)) - 1 = 9 */
static u8 sspadd_value = (u8)((I2C_FOSC / (4UL * I2C_BAUDRATE)) - 1);

/*
 * I2C_Wait: blocks until the bus is idle.
 * Checks that no transmit/receive operation is in progress:
 *   - SSPSTAT bit 2 (RW) : transmission in progress
 *   - SSPCON2 bits 4:0   : SEN/RSEN/PEN/RCEN/ACKEN all must be 0
 * (Implementation matches lab slide 53)
 */
static void I2C_Wait(void)
{
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void I2C_Init(void)
{
    /* SCL = RC3, SDA = RC4 — must be inputs (open-drain) */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);

    SSPCON  = I2C_MASTER_MODE;  /* 0x28: SSPEN=1, I2C Master mode */
    SSPCON2 = 0x00;
    SSPSTAT = 0x00;
    SSPADD  = sspadd_value;
}

void I2C_Start(void)
{
    I2C_Wait();
    SET_BIT(SSPCON2, SEN);  /* Assert Start condition */
    I2C_Wait();             /* Wait for hardware to clear SEN */
}

void I2C_Stop(void)
{
    I2C_Wait();
    SET_BIT(SSPCON2, PEN);  /* Assert Stop condition */
    I2C_Wait();             /* Wait for hardware to clear PEN */
}

u8 I2C_Write(u8 Data)
{
    I2C_Wait();
    SSPBUF = Data;          /* Triggers transmission */
    I2C_Wait();             /* Wait for byte + ACK cycle to complete */
    return GET_BIT(SSPCON2, ACKSTAT);  /* 0 = ACK (success), 1 = NACK (error) */
}

u8 I2C_Read(u8 Ack)
{
    u8 data;

    I2C_Wait();
    SET_BIT(SSPCON2, RCEN); /* Enable receive mode */
    I2C_Wait();             /* Wait for full byte to be clocked in */

    data = SSPBUF;          /* Reading SSPBUF clears BF flag */

    /* Prepare and send ACK or NACK */
    if(Ack)
        CLR_BIT(SSPCON2, ACKDT);    /* 0 = ACK  */
    else
        SET_BIT(SSPCON2, ACKDT);    /* 1 = NACK */

    SET_BIT(SSPCON2, ACKEN);        /* Trigger acknowledge sequence */
    I2C_Wait();

    return data;
}

u8 I2C_WriteDevice(u8 Address, u8 *Data, u8 Length)
{
    u8 i;

    I2C_Start();

    /* Send 7-bit address with Write bit (0) */
    if(I2C_Write((u8)((Address << 1) | 0x00))) {
        I2C_Stop();
        return I2C_ERROR;   /* Slave did not acknowledge */
    }

    for(i = 0; i < Length; i++) {
        if(I2C_Write(Data[i])) {
            I2C_Stop();
            return I2C_ERROR;
        }
    }

    I2C_Stop();
    return I2C_SUCCESS;
}

u8 I2C_ReadDevice(u8 Address, u8 *Data, u8 Length)
{
    u8 i;

    I2C_Start();

    /* Send 7-bit address with Read bit (1) */
    if(I2C_Write((u8)((Address << 1) | 0x01))) {
        I2C_Stop();
        return I2C_ERROR;
    }

    for(i = 0; i < Length; i++) {
        /* Send ACK after every byte except the last one (NACK on last) */
        Data[i] = I2C_Read(i < (Length - 1));
    }

    I2C_Stop();
    return I2C_SUCCESS;
}