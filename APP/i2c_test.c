#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/I2C/I2C_interface.h"

void I2C_Test(void)
{
    u8 i;
    u32 j;

    I2C_Init(I2C_MODE_MASTER, 0x00);
    I2C_SetSpeed(I2C_SPEED_100KHZ);

    // Test sequence 1: Write to address 0x50
    I2C_Start();
    for (j = 0; j < 10000; j++)
        ;

    I2C_WriteAddress(0x50, 0); // Write mode
    for (j = 0; j < 10000; j++)
        ;

    // Send 3 bytes
    for (i = 0; i < 3; i++)
    {
        I2C_WriteByte(0x10 + i);
        for (j = 0; j < 10000; j++)
            ;
    }

    I2C_Stop();
    for (j = 0; j < 20000; j++)
        ;

    // Test sequence 2: Read from address 0x50
    I2C_Start();
    for (j = 0; j < 10000; j++)
        ;

    I2C_WriteAddress(0x50, 1); // Read mode
    for (j = 0; j < 10000; j++)
        ;

    // Read 2 bytes
    for (i = 0; i < 2; i++)
    {
        (void)I2C_ReadByte(1); // ACK
        for (j = 0; j < 10000; j++)
            ;
    }

    I2C_Stop();
    for (j = 0; j < 20000; j++)
        ;

    // Test at 400kHz
    I2C_SetSpeed(I2C_SPEED_400KHZ);

    I2C_Start();
    I2C_WriteAddress(0x50, 0);
    I2C_WriteByte(0xAA);
    I2C_Stop();

    for (j = 0; j < 30000; j++)
        ;
}
