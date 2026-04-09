#line 1 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/APP/adc_test.c"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/adc/adc_interface.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/adc/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 16 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/adc/adc_interface.h"
void ADC_Init(void);
u16 ADC_ReadChannel(u8 Channel);
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/usart/usart_interface.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/usart/usart_private.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/usart/usart_config.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/usart/../../services/std_types.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/usart/../../services/bit_math.h"
#line 10 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/usart/usart_interface.h"
void UART_RX_Init(void);
void UART_TX_Init(void);


void UART_Write(u8 Data);
u8 UART_Read(void);


u8 UART_TX_Empty(void);

void UART_SetCallback(void (*Callback)(u8));
void UART_ISR(void);
#line 4 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/APP/adc_test.c"
void adc_test_run(void) {
 u16 adc_val;
 ADC_Init();


 adc_val = ADC_ReadChannel(0);
 UART_Write((u8)(adc_val >> 2));
}
