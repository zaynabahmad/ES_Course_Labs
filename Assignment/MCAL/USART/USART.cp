#line 1 "D:/mikroC PRO for PIC/Examples/MCAL/USART/USART.c"
#line 1 "d:/mikroc pro for pic/examples/mcal/usart/usart_interface.h"
#line 1 "d:/mikroc pro for pic/examples/mcal/usart/usart_private.h"
#line 1 "d:/mikroc pro for pic/examples/mcal/usart/usart_config.h"
#line 1 "d:/mikroc pro for pic/examples/mcal/usart/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 1 "d:/mikroc pro for pic/examples/mcal/usart/../../services/bit_math.h"
#line 10 "d:/mikroc pro for pic/examples/mcal/usart/usart_interface.h"
void UART_RX_Init(void);
void UART_TX_Init(void);


void UART_Write(u8 Data);
u8 UART_Read(void);


u8 UART_TX_Empty(void);

void UART_SetCallback(void (*Callback)(u8));
void UART_ISR(void);
#line 8 "D:/mikroC PRO for PIC/Examples/MCAL/USART/USART.c"
void (*UART_Callback)(u8) = 0;
#line 14 "D:/mikroC PRO for PIC/Examples/MCAL/USART/USART.c"
void UART_RX_Init(void)
{

  ( ( (*(volatile unsigned char*)0x98) ) |= (1U << ( 2 )) ) ;

  (*(volatile unsigned char*)0x99)  = 25;

  ( ( (*(volatile unsigned char*)0x98) ) &= ~(1U << ( 4 )) ) ;

  ( ( (*(volatile unsigned char*)0x18) ) |= (1U << ( 7 )) ) ;

  ( ( (*(volatile unsigned char*)0x18) ) |= (1U << ( 4 )) ) ;

  ( ( (*(volatile unsigned char*)0x8C) ) |= (1U << ( 5 )) ) ;

  ( (INTCON) |= (1U << ( 6 )) ) ;
  ( (INTCON) |= (1U << ( 7 )) ) ;
}
#line 37 "D:/mikroC PRO for PIC/Examples/MCAL/USART/USART.c"
void UART_TX_Init(void)
{

  ( ( (*(volatile unsigned char*)0x98) ) |= (1U << ( 2 )) ) ;

  (*(volatile unsigned char*)0x99)  = 25;

  ( ( (*(volatile unsigned char*)0x98) ) &= ~(1U << ( 4 )) ) ;

  ( ( (*(volatile unsigned char*)0x18) ) |= (1U << ( 7 )) ) ;

  ( ( (*(volatile unsigned char*)0x98) ) |= (1U << ( 5 )) ) ;
}
#line 55 "D:/mikroC PRO for PIC/Examples/MCAL/USART/USART.c"
void UART_Write(u8 Data)
{

 while(! ( (( (*(volatile unsigned char*)0x98) ) >> ( 1 )) & 1U ) );

  (*(volatile unsigned char*)0x19)  = Data;
}
#line 67 "D:/mikroC PRO for PIC/Examples/MCAL/USART/USART.c"
u8 UART_Read(void)
{

 while(! ( (( (*(volatile unsigned char*)0x0C) ) >> ( 5 )) & 1U ) );

 return  (*(volatile unsigned char*)0x1A) ;
}
#line 79 "D:/mikroC PRO for PIC/Examples/MCAL/USART/USART.c"
u8 UART_TX_Empty(void)
{

 return  ( (( (*(volatile unsigned char*)0x98) ) >> ( 1 )) & 1U ) ;
}
#line 89 "D:/mikroC PRO for PIC/Examples/MCAL/USART/USART.c"
void UART_SetCallback(void (*Callback)(u8))
{

 if(Callback != 0)
 {
 UART_Callback = Callback;
 }

}

void UART_ISR(void)
{

 u8 UART_data =  (*(volatile unsigned char*)0x1A) ;
 if(UART_Callback != 0)
 {
 UART_Callback(UART_data);
 }

}
