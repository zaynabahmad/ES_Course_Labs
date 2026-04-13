#include "../MCAL/I2C/I2C_interface.h"

void I2C_Test(void)
{
    u8 Status;
    u8 RxData;

    /* Test 1: Initialize I2C as Master with 100 kHz speed */
    I2C_Init(I2C_SPEED_100KHZ, 0x50);

    /* Test 2: Generate START condition */
    I2C_MasterStart();

    /* Test 3: Send slave address with write bit */
    I2C_MasterWrite(0x50);  /* Address 0x50 with write bit (0x50 << 1) | 0 */

    /* Test 4: Send data byte */
    I2C_MasterWrite(0xAA);

    /* Test 5: Generate REPEATED START condition */
    I2C_MasterRepeatedStart();

    /* Test 6: Send slave address with read bit */
    I2C_MasterWrite(0x51);  /* Address 0x50 with read bit (0x50 << 1) | 1 */

    /* Test 7: Read data with ACK */
    RxData = I2C_MasterRead(1);  /* ACK required */

    /* Test 8: Read data with NACK */
    RxData = I2C_MasterRead(0);  /* NACK - last byte */

    /* Test 9: Generate STOP condition */
    I2C_MasterStop();

    /* Test 10: Get I2C status */
    Status = I2C_GetStatus();

    /* Test 11: Set interrupt callback */
    I2C_SetCallback(NULL_PTR);
}
