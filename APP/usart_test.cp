#line 1 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/APP/usart_test.c"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/usart/usart_interface.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/usart/usart_private.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/usart/usart_config.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/usart/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/usart/../../services/bit_math.h"
#line 10 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/usart/usart_interface.h"
void UART_RX_Init(void);
void UART_TX_Init(void);


void UART_Write(u8 Data);
u8 UART_Read(void);


u8 UART_TX_Empty(void);

void UART_SetCallback(void (*Callback)(u8));
void UART_ISR(void);
#line 3 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/APP/usart_test.c"
void usart_test_run(void) {

 UART_TX_Init();
 UART_RX_Init();

 UART_Write('U');
 UART_Write('A');
 UART_Write('R');
 UART_Write('T');
 UART_Write(' ');
 UART_Write('O');
 UART_Write('K');
}
