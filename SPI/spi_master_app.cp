#line 1 "D:/microc/mikroC PRO for PIC/Examples/spi_master_app.c"
#line 1 "d:/microc/mikroc pro for pic/examples/spi.h"
#line 1 "d:/microc/mikroc pro for pic/examples/std_types.h"




typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned int uint16;
typedef signed int sint16;
typedef unsigned long uint32;
typedef signed long sint32;
#line 1 "d:/microc/mikroc pro for pic/examples/pic_config.h"
#line 9 "d:/microc/mikroc pro for pic/examples/spi.h"
void SPI_MasterInit(void);
void SPI_SlaveInit(void);
uint8 SPI_Transfer(uint8 data);
void SPI_Write(uint8 data);
uint8 SPI_Read(void);
#line 1 "d:/microc/mikroc pro for pic/examples/gpio.h"
#line 1 "d:/microc/mikroc pro for pic/examples/std_types.h"
#line 1 "d:/microc/mikroc pro for pic/examples/common_macros.h"
#line 1 "d:/microc/mikroc pro for pic/examples/pic_config.h"
#line 31 "d:/microc/mikroc pro for pic/examples/gpio.h"
void GPIO_SetPinDirection(uint8 port_id, uint8 pin_num, uint8 direction);
void GPIO_WritePin(uint8 port_id, uint8 pin_num, uint8 value);
uint8 GPIO_ReadPin(uint8 port_id, uint8 pin_num);
void GPIO_TogglePin(uint8 port_id, uint8 pin_num);
#line 7 "D:/microc/mikroC PRO for PIC/Examples/spi_master_app.c"
void SPI_MasterTest(void) {
 uint8 counter = 0;

 SPI_MasterInit();


 GPIO_SetPinDirection( 1 ,  2 ,  0 );
 GPIO_WritePin( 1 ,  2 ,  1 );

 while(1) {
 GPIO_WritePin( 1 ,  2 ,  0 );


 uint8 received = SPI_Transfer(counter);

 GPIO_WritePin( 1 ,  2 ,  1 );

 counter++;
 __delay_ms(500);
 }
}
