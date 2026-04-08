#include "../MCAL/I2C/I2C_interface.h"

void I2C_Test(void)
{
    u8 Local_ReceivedData = 0;

    /* Initialize I2C */
    I2C_Init();

    /* Send Start condition */
    I2C_Start();

    /* Send device address with write bit (0x50 << 1) */
    I2C_SendByte(0xA0);

    /* Send register address */
    I2C_SendByte(0x00);

    /* Send Repeated Start */
    I2C_RepeatedStart();

    /* Send device address with read bit */
    I2C_SendByte(0xA1);

    /* Receive one byte with NACK */
    Local_ReceivedData = I2C_ReceiveByte(0);

    /* Send Stop condition */
    I2C_Stop();
}