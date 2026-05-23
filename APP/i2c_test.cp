#line 1 "D:/Uni/Y4 S2/Embedded Systems/Final/APP/i2c_test.c"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/i2c/i2c_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"



typedef unsigned char u8;
typedef unsigned int u16;
#line 18 "d:/uni/y4 s2/embedded systems/final/mcal/i2c/i2c_interface.h"
void I2C_voidInit(void);

void I2C_voidStart(void);

void I2C_voidRepeatedStart(void);

void I2C_voidStop(void);

unsigned char I2C_u8Write(unsigned char data);

unsigned char I2C_u8Read(unsigned char send_ack);

void I2C_voidWaitIdle(void);
#line 3 "D:/Uni/Y4 S2/Embedded Systems/Final/APP/i2c_test.c"
void I2C_Test(void)
{
 unsigned char status;

 I2C_voidInit();

 while (1)
 {
 I2C_voidStart();

 status = I2C_u8Write(0xA0);
 if (status ==  0u )
 {
 I2C_u8Write('M');
 }

 I2C_voidStop();
 }
}
