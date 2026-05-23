#line 1 "D:/Uni/Y4 S2/Embedded Systems/Final/APP/spi_test.c"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/spi/spi_interface.h"



void SPI_voidInit(void);
unsigned char SPI_u8Transfer(unsigned char data);
#line 3 "D:/Uni/Y4 S2/Embedded Systems/Final/APP/spi_test.c"
void SPI_Test(void)
{
 unsigned char data;

 SPI_voidInit();

 while(1)
 {
 data = SPI_u8Transfer('A');
 }
}
