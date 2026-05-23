#line 1 "D:/Uni/Y4 S2/Embedded Systems/Final/MCAL/SPI/SPI_program.c"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"



typedef unsigned char u8;
typedef unsigned int u16;
#line 1 "d:/uni/y4 s2/embedded systems/final/services/bit_math.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/spi/spi_private.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/spi/spi_interface.h"



void SPI_voidInit(void);
unsigned char SPI_u8Transfer(unsigned char data);
#line 7 "D:/Uni/Y4 S2/Embedded Systems/Final/MCAL/SPI/SPI_program.c"
void SPI_voidInit(void)
{

  (*(volatile unsigned char*)0x14)  |= (1<<5) ;
  (*(volatile unsigned char*)0x14)  |= (1<<4) ;
}

unsigned char SPI_u8Transfer(unsigned char data)
{
  (*(volatile unsigned char*)0x13)  = data;

 while(! (( (*(volatile unsigned char*)0x94) >>0)&1) );

 return  (*(volatile unsigned char*)0x13) ;
}
