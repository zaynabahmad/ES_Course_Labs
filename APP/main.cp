#line 1 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/APP/main.c"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/gpio/gpio_interface.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/gpio/../../services/std_types.h"
#line 31 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(unsigned char Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8 GPIO_GetPinValue(u8 Port, u8 Pin);
void GPIO_Init(void);
#line 5 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/APP/main.c"
extern void usart_test_run(void);
extern void adc_test_run(void);
extern void pwm_test_run(void);
extern void spi_test_run(void);
extern void i2c_test_run(void);
extern void timer0_test_run(void);
extern void ext_int_test_run(void);

void main(void) {

 GPIO_Init();


 usart_test_run();
 spi_test_run();
 i2c_test_run();


 adc_test_run();
 pwm_test_run();


 timer0_test_run();
 ext_int_test_run();

 while(1) {

 }
}
