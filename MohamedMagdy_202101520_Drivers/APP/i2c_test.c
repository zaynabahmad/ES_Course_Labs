#include "../MCAL/I2C/I2C_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "i2c_test.h"

#define I2C_SLAVE_ADDR  0x20

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

    I2C_MasterInit();

    delay();

    I2C_Start();
    ack = I2C_WriteByte(I2C_WRITE_ADDR);
    if(ack == 0)
    {
        I2C_WriteByte(0xAA);
    }
    I2C_Stop();
    delay();

    I2C_Start();
    ack = I2C_WriteByte(I2C_READ_ADDR);
    if(ack == 0)
    {
        rx_data = I2C_ReadByte(I2C_SEND_NACK);
        (void)rx_data;
    }
    I2C_Stop();
    delay();

    I2C_Start();
    I2C_WriteByte(I2C_WRITE_ADDR);
    I2C_WriteByte(0x00);
    I2C_RepeatedStart();
    I2C_WriteByte(I2C_READ_ADDR);
    rx_data = I2C_ReadByte(I2C_SEND_NACK);
    (void)rx_data;
    I2C_Stop();

    I2C_Disable();
}
