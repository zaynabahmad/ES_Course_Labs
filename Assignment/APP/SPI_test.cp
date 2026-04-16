#line 1 "D:/mikroC PRO for PIC/Examples/APP/SPI_test.c"
#line 1 "d:/mikroc pro for pic/examples/app/../mcal/spi/spi_interface.h"





void SPI_InitMaster(void);
void SPI_InitSlave(void);

u8 SPI_u8SendRcve(u8 data);
#line 3 "D:/mikroC PRO for PIC/Examples/APP/SPI_test.c"
void SPI_Test(void)
{
 SPI_voidInitMaster();

 u8 received;

 while(1)
 {
 received = SPI_u8SendReceive(0x55);
 }
}
