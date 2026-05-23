#line 1 "D:/Uni/Y4 S2/Embedded Systems/Final/APP/uart_test.c"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/uart/uart_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"



typedef unsigned char u8;
typedef unsigned int u16;
#line 14 "d:/uni/y4 s2/embedded systems/final/mcal/uart/uart_interface.h"
void UART_voidInit(void);

void UART_voidSendChar(unsigned char data);

void UART_voidSendString(const unsigned char *str);

void UART_voidSendNumber(unsigned int number);

unsigned char UART_u8ReceiveChar(unsigned char *received);

unsigned char UART_u8ReceiveCharTimeout(unsigned char *received);

void UART_voidClearErrors(void);
#line 3 "D:/Uni/Y4 S2/Embedded Systems/Final/APP/uart_test.c"
void UART_Test(void)
{
 unsigned char received;
 unsigned char status;

 UART_voidInit();

 while (1)
 {
 UART_voidSendString((const unsigned char *)"Hello\r\n");

 status = UART_u8ReceiveCharTimeout(&received);
 if (status ==  0u )
 {
 UART_voidSendChar(received);
 }
 }
}
