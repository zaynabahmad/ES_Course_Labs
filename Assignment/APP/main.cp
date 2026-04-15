#line 1 "D:/mikroC PRO for PIC/Examples/APP/main.c"
#line 1 "d:/mikroc pro for pic/examples/app/../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 1 "d:/mikroc pro for pic/examples/app/../services/bit_math.h"
#line 1 "d:/mikroc pro for pic/examples/app/../hal/led/led_interface.h"
#line 1 "d:/mikroc pro for pic/examples/app/../hal/led/../../services/std_types.h"
#line 10 "d:/mikroc pro for pic/examples/app/../hal/led/led_interface.h"
void LED_Init(u8 Port, u8 Pin);
void LED_On(u8 Port, u8 Pin);
void LED_Off(u8 Port, u8 Pin);
void LED_Toggle(u8 Port, u8 Pin);
#line 1 "d:/mikroc pro for pic/examples/app/../mcal/gpio/gpio_interface.h"
#line 1 "d:/mikroc pro for pic/examples/app/../mcal/gpio/../../services/std_types.h"
#line 31 "d:/mikroc pro for pic/examples/app/../mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(unsigned char Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8 GPIO_GetPinValue(u8 Port, u8 Pin);
void GPIO_Init(void);
#line 1 "d:/mikroc pro for pic/examples/app/../mcal/usart/usart_interface.h"
#line 1 "d:/mikroc pro for pic/examples/app/../mcal/usart/usart_private.h"
#line 1 "d:/mikroc pro for pic/examples/app/../mcal/usart/usart_config.h"
#line 1 "d:/mikroc pro for pic/examples/app/../mcal/usart/../../services/std_types.h"
#line 1 "d:/mikroc pro for pic/examples/app/../mcal/usart/../../services/bit_math.h"
#line 10 "d:/mikroc pro for pic/examples/app/../mcal/usart/usart_interface.h"
void UART_RX_Init(void);
void UART_TX_Init(void);


void UART_Write(u8 Data);
u8 UART_Read(void);


u8 UART_TX_Empty(void);

void UART_SetCallback(void (*Callback)(u8));
void UART_ISR(void);
#line 1 "d:/mikroc pro for pic/examples/app/../mcal/ext_int/ext_int_interface.h"
#line 1 "d:/mikroc pro for pic/examples/app/../mcal/ext_int/../../services/std_types.h"
#line 1 "d:/mikroc pro for pic/examples/app/../mcal/ext_int/../gpio/gpio_interface.h"
#line 1 "d:/mikroc pro for pic/examples/app/../mcal/ext_int/../../services/bit_math.h"
#line 1 "d:/mikroc pro for pic/examples/app/../mcal/ext_int/ext_int_config.h"
#line 1 "d:/mikroc pro for pic/examples/app/../mcal/ext_int/ext_int_private.h"
#line 22 "d:/mikroc pro for pic/examples/app/../mcal/ext_int/ext_int_interface.h"
void EXT_INT_Init(void);
void EXT_INT_Enable(void);
void EXT_INT_Disable(void);
void EXT_INT_SetEdge(u8 Edgetype);
void EXT_INT_SetCallback(void (*Callback)(void));
void EXT_INT_ISR(void);
#line 17 "D:/mikroC PRO for PIC/Examples/APP/main.c"
void Bluetooth_UART_Callback(u8 UART_data)
{

 if (UART_data == 'f')
 {
 GPIO_SetPinValue( 2 ,  0 ,  1 );
 GPIO_SetPinValue( 2 ,  2 ,  0 );
 GPIO_SetPinValue( 2 ,  1 ,  1 );
 }
 else if (UART_data == 's')
 {
 GPIO_SetPinValue( 2 ,  0 ,  0 );
 GPIO_SetPinValue( 2 ,  2 ,  0 );
 GPIO_SetPinValue( 2 ,  1 ,  0 );
 }


}

int main(void)
{

 GPIO_Init();
 GPIO_SetPinDirection( 2 ,  0 ,  0 );
 GPIO_SetPinDirection( 2 ,  2 ,  0 );
 GPIO_SetPinDirection( 2 ,  1 ,  0 );


 UART_RX_Init();
 UART_TX_Init();




 UART_SetCallback(Bluetooth_UART_Callback);


 void SPI_Test(void);
 void ADC_Test(void);
 while(1)
 {

 }

 return 0;
}
