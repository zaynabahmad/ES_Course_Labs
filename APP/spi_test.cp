#line 1 "D:/ES-Project-Lab/APP/spi_test.c"
#line 1 "d:/es-project-lab/services/std_types.h"



typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
#line 1 "d:/es-project-lab/mcal/gpio/gpio.h"
#line 1 "d:/es-project-lab/services/std_types.h"
#line 27 "d:/es-project-lab/mcal/gpio/gpio.h"
void GPIO_setPinDirection(u8 port, u8 pin, u8 direction);
void GPIO_setPinValue(u8 port, u8 pin, u8 value);
u8 GPIO_getPinValue(u8 port, u8 pin);
void GPIO_setPortDirection(u8 port, u8 direction);
void GPIO_setPortValue(u8 port, u8 value);
#line 1 "d:/es-project-lab/mcal/spi/spi_interface.h"
#line 1 "d:/es-project-lab/services/std_types.h"
#line 6 "d:/es-project-lab/mcal/spi/spi_interface.h"
void SPI_Init(void);
u8 SPI_Transfer(u8 txValue);
#line 1 "d:/es-project-lab/hal/led_interface.h"
void LED_Init(u8 port, u8 pin);
void LED_On(u8 port, u8 pin);
void LED_Off(u8 port, u8 pin);
void LED_Toggle(u8 port, u8 pin);
#line 5 "D:/ES-Project-Lab/APP/spi_test.c"
void app_spi_test(void)
{
 u8 txValue = 0;
 u8 rxValue = 0;
 u8 ledState = 0;
 u16 delayValue = 0;

 LED_Init( 3 ,  0 );

 SPI_Init();

 while(1)
 {
 rxValue = SPI_Transfer(txValue);
 (void)rxValue;

 ledState ^= 1;
 GPIO_setPinValue( 3 ,  0 , ledState);

 txValue++;

 for(delayValue = 0; delayValue < 10000; delayValue++)
 {
 ;
 }
 }
}
