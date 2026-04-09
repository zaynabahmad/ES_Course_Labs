#include "../MCAL/I2C/I2C_interface.h"
#include "../SERVICES/STD_TYPES.h"

void I2C_Test(void)
{
    u8 received_data;

    I2C_Init();

    while(1)
    {
        /* --- Write 0x55 to slave address 0x50 --- */
        I2C_Start();
        I2C_Write(0x50 << 1);   /* slave address + write bit */
        I2C_Write(0x55);        /* data to send */
        I2C_Stop();

        /* --- Read back from slave address 0x50 --- */
        I2C_Start();
        I2C_Write((0x50 << 1) | 0x01);  /* slave address + read bit */
        received_data = I2C_Read();
        I2C_Stop();
    }
}