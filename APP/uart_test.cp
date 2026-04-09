#line 1 "E:/embedded/Drivers_Project/APP/uart_test.c"
#line 1 "e:/embedded/drivers_project/app/uart_test.h"



void UART_Test(void);
#line 1 "e:/embedded/drivers_project/app/../mcal/uart/uart_interface.h"



void UART_Init(void);
void UART_SendChar(char d);
char UART_ReceiveChar(void);
void UART_SendString(char* str);
#line 4 "E:/embedded/Drivers_Project/APP/uart_test.c"
void UART_Test(void)
{
 UART_Init();
 UART_SendString("UART Test Started...\n");

 while(1)
 {
 char received = UART_ReceiveChar();
 UART_SendChar(received);
 }
}
