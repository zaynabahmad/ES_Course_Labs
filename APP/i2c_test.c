#include "../MCAL/I2C/I2C_interface.h"
#include "i2c_test.h"

/* Example: write a byte to a slave at address 0x50 (EEPROM) */
#define I2C_SLAVE_ADDR  0x50

void i2c_test_run(void)
{
    u8 rx;
    u8 status;

    I2C_Init();

    /* --- Write transaction --- */
    I2C_Start();
    status = I2C_WriteByte((I2C_SLAVE_ADDR << 1) | 0);  /* address + write bit */
    if (status == I2C_OK)
    {
        I2C_WriteByte(0x00);    /* memory address high */
        I2C_WriteByte(0x00);    /* memory address low  */
        I2C_WriteByte(0xAB);    /* data byte           */
    }
    I2C_Stop();

    /* --- Read transaction --- */
    I2C_Start();
    status = I2C_WriteByte((I2C_SLAVE_ADDR << 1) | 0);
    if (status == I2C_OK)
    {
        I2C_WriteByte(0x00);
        I2C_WriteByte(0x00);
        I2C_RepeatedStart();
        I2C_WriteByte((I2C_SLAVE_ADDR << 1) | 1);  /* address + read bit */
        rx = I2C_ReadByte(0);                        /* read with NACK */
    }
    I2C_Stop();

    (void)rx;
    (void)status;
}
