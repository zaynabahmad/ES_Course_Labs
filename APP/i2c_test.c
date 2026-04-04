/*
 * i2c_test.c
 * Tests the I2C MCAL driver: master init, START/STOP conditions,
 * write and read byte sequences for a generic 7-bit slave.
 * No direct register access — uses only I2C_Interface.h API.
 */

#include "../MCAL/I2C/I2C_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "i2c_test.h"

/* Example 7-bit slave address (e.g. PCF8574 I/O expander at 0x20) */
#define I2C_SLAVE_ADDR  0x20

/*
 * Build the 8-bit address byte:
 *   bits 7:1 = 7-bit address
 *   bit  0   = 0 (write) or 1 (read)
 */
#define I2C_WRITE_ADDR  (u8)((I2C_SLAVE_ADDR << 1) | 0x00)
#define I2C_READ_ADDR   (u8)((I2C_SLAVE_ADDR << 1) | 0x01)

static void delay(void)
{
    unsigned int i;
    for(i = 0; i < 10000U; i++) { ; }
}

void I2C_Test(void)
{
    u8 ack;
    u8 rx_data;

    /* Initialise I2C master (RC3=SCL, RC4=SDA, 100 kHz) */
    I2C_MasterInit();

    delay();

    /* --- Test 1: Write one byte to the slave --- */
    I2C_Start();

    ack = I2C_WriteByte(I2C_WRITE_ADDR);    /* Send address + write bit */
    if(ack == 0)                             /* 0 = slave ACKed          */
    {
        I2C_WriteByte(0xAA);                 /* Send data byte           */
    }

    I2C_Stop();
    delay();

    /* --- Test 2: Read one byte from the slave --- */
    I2C_Start();

    ack = I2C_WriteByte(I2C_READ_ADDR);     /* Send address + read bit  */
    if(ack == 0)
    {
        rx_data = I2C_ReadByte(I2C_SEND_NACK);   /* Read last byte → NACK */
        (void)rx_data;
    }

    I2C_Stop();
    delay();

    /* --- Test 3: Write then read with repeated START --- */
    I2C_Start();
    I2C_WriteByte(I2C_WRITE_ADDR);
    I2C_WriteByte(0x00);                     /* Register address         */
    I2C_RepeatedStart();
    I2C_WriteByte(I2C_READ_ADDR);
    rx_data = I2C_ReadByte(I2C_SEND_NACK);
    (void)rx_data;
    I2C_Stop();

    /* Disable I2C when done */
    I2C_Disable();
}