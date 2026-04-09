#line 1 "D:/ES-Project-Lab/APP/main.c"
#line 1 "d:/es-project-lab/services/std_types.h"



typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
#line 5 "D:/ES-Project-Lab/APP/main.c"
extern void app_gpio_test(void);
extern void app_exti_test(void);
extern void app_timer0_test(void);
extern void app_adc_test(void);
extern void app_uart_test(void);
extern void app_i2c_test(void);
extern void app_spi_test(void);
extern void app_pwm_test(void);
extern void app_switch_test(void);
 extern void app_motor_test(void);
 extern void app_led_test(void);
void main(void)
{
 app_led_test();

 while(1)
 {
 ;
 }
}
