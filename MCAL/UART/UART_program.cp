#line 1 "D:/Uni/Y4 S2/Embedded Systems/Final/MCAL/UART/UART_program.c"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"



typedef unsigned char u8;
typedef unsigned int u16;
#line 1 "d:/uni/y4 s2/embedded systems/final/services/bit_math.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/uart/uart_private.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/uart/uart_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"
#line 14 "d:/uni/y4 s2/embedded systems/final/mcal/uart/uart_interface.h"
void UART_voidInit(void);

void UART_voidSendChar(unsigned char data);

void UART_voidSendString(const unsigned char *str);

void UART_voidSendNumber(unsigned int number);

unsigned char UART_u8ReceiveChar(unsigned char *received);

unsigned char UART_u8ReceiveCharTimeout(unsigned char *received);

void UART_voidClearErrors(void);
#line 7 "D:/Uni/Y4 S2/Embedded Systems/Final/MCAL/UART/UART_program.c"
void UART_voidClearErrors(void)
{
  (*(volatile unsigned char*)0x18)  &= ~(1<< 4 ) ;
  (*(volatile unsigned char*)0x18)  |= (1<< 4 ) ;
}


void UART_voidInit(void)
{
  (*(volatile unsigned char*)0x87)  |= (1<< 7u ) ;
  (*(volatile unsigned char*)0x87)  &= ~(1<< 6u ) ;

  (*(volatile unsigned char*)0x99)  =  51u ;

  (*(volatile unsigned char*)0x98)  &= ~(1<< 4 ) ;
  (*(volatile unsigned char*)0x98)  |= (1<< 2 ) ;
  (*(volatile unsigned char*)0x98)  &= ~(1<< 6 ) ;
  (*(volatile unsigned char*)0x98)  |= (1<< 5 ) ;

  (*(volatile unsigned char*)0x18)  |= (1<< 7 ) ;
  (*(volatile unsigned char*)0x18)  &= ~(1<< 6 ) ;
  (*(volatile unsigned char*)0x18)  |= (1<< 4 ) ;
}


void UART_voidSendChar(unsigned char data)
{

 while ( (( (*(volatile unsigned char*)0x0C) >> 4 )&1)  == 0u)
 {

 }
  (*(volatile unsigned char*)0x19)  = data;
}


void UART_voidSendString(const unsigned char *str)
{

 while (*str != '\0')
 {
 UART_voidSendChar(*str);
 str++;
 }
}


void UART_voidSendNumber(unsigned int number)
{
 unsigned char digits[5];
 unsigned char count = 0u;
 unsigned char i;


 if (number == 0u)
 {
 UART_voidSendChar('0');
 return;
 }


 while (number > 0u)
 {
 digits[count] = (unsigned char)((number % 10u) + '0');
 number /= 10u;
 count++;
 }


 for (i = count; i > 0u; i--)
 {
 UART_voidSendChar(digits[i - 1u]);
 }
}


unsigned char UART_u8ReceiveChar(unsigned char *received)
{

 if ( (( (*(volatile unsigned char*)0x18) >> 1 )&1) )
 {
 UART_voidClearErrors();
 return  1u ;
 }


 while ( (( (*(volatile unsigned char*)0x0C) >> 5 )&1)  == 0u)
 {

 }


 if ( (( (*(volatile unsigned char*)0x18) >> 2 )&1) )
 {
 *received =  (*(volatile unsigned char*)0x1A) ;
 return  2u ;
 }

 *received =  (*(volatile unsigned char*)0x1A) ;
 return  0u ;
}


unsigned char UART_u8ReceiveCharTimeout(unsigned char *received)
{
 unsigned int timeout =  60000u ;


 if ( (( (*(volatile unsigned char*)0x18) >> 1 )&1) )
 {
 UART_voidClearErrors();
 return  1u ;
 }


 while ( (( (*(volatile unsigned char*)0x0C) >> 5 )&1)  == 0u)
 {
 timeout--;
 if (timeout == 0u)
 {
 return  3u ;
 }
 }

 *received =  (*(volatile unsigned char*)0x1A) ;
 return  0u ;
}
