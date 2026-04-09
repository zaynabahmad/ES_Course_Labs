#line 1 "E:/embedded/Drivers_Project/APP/i2c_test.c"
#line 1 "e:/embedded/drivers_project/app/../mcal/i2c/i2c_interface.h"



void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(char d);
char I2C_Read(char ack);
#line 1 "e:/embedded/drivers_project/app/i2c_test.h"



void I2C_Test(void);
#line 4 "E:/embedded/Drivers_Project/APP/i2c_test.c"
void I2C_Test(void)
{
 I2C_Init();

 I2C_Start();
 I2C_Write(0xA0);
 I2C_Write(0x00);
 I2C_Stop();
}
