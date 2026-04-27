#line 1 "E:/Drivers/P/APP/spi_test.c"
#line 1 "e:/drivers/p/app/spi_test.h"



void SPI_Test(void);
#line 1 "e:/drivers/p/app/../mcal/spi/spi_interface.h"



void SPI_Init(void);
char SPI_Transmit(char d);
#line 5 "E:/Drivers/P/APP/spi_test.c"
void SPI_Test(void)
{
 char received;

 SPI_Init();


 received = SPI_Transmit(0x55);
 received = SPI_Transmit(0xAA);


 while(1);
}
