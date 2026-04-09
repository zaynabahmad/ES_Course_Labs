#line 1 "D:/ES-Project-Lab/APP/uart_test.c"
#line 1 "d:/es-project-lab/services/std_types.h"



typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
#line 1 "d:/es-project-lab/mcal/uart/uart_interface.h"
#line 1 "d:/es-project-lab/services/std_types.h"
#line 6 "d:/es-project-lab/mcal/uart/uart_interface.h"
void UART_Init(void);
void UART_SendChar(u8 txValue);
u8 UART_ReceiveChar(void);
#line 1 "d:/es-project-lab/hal/led_interface.h"
void LED_Init(u8 port, u8 pin);
void LED_On(u8 port, u8 pin);
void LED_Off(u8 port, u8 pin);
void LED_Toggle(u8 port, u8 pin);
#line 4 "D:/ES-Project-Lab/APP/uart_test.c"
void app_uart_test(void)
{
 u8 receivedChar;

 UART_Init();

 while(1)
 {
 receivedChar = UART_ReceiveChar();
 UART_SendChar(receivedChar);
 }
}
