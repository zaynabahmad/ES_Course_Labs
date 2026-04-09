#line 1 "D:/ES-Project-Lab/APP/adc_test.c"
#line 1 "d:/es-project-lab/services/std_types.h"



typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
#line 1 "d:/es-project-lab/mcal/gpio/gpio.h"
#line 1 "d:/es-project-lab/services/std_types.h"
#line 27 "d:/es-project-lab/mcal/gpio/gpio.h"
void GPIO_setPinDirection(u8 port, u8 pin, u8 direction);
void GPIO_setPinValue(u8 port, u8 pin, u8 value);
u8 GPIO_getPinValue(u8 port, u8 pin);
void GPIO_setPortDirection(u8 port, u8 direction);
void GPIO_setPortValue(u8 port, u8 value);
#line 1 "d:/es-project-lab/mcal/adc/adc_interface.h"
#line 1 "d:/es-project-lab/services/std_types.h"
#line 15 "d:/es-project-lab/mcal/adc/adc_interface.h"
void ADC_Init(void);
u16 ADC_Read(u8 channel);
#line 1 "d:/es-project-lab/hal/led_interface.h"
void LED_Init(u8 port, u8 pin);
void LED_On(u8 port, u8 pin);
void LED_Off(u8 port, u8 pin);
void LED_Toggle(u8 port, u8 pin);
#line 5 "D:/ES-Project-Lab/APP/adc_test.c"
void app_adc_test(void)
{
 u16 adc_value = 0;


 GPIO_setPinDirection( 0 ,  0 ,  1 );


 LED_Init( 3 ,  0 );

 ADC_Init();

 while(1)
 {
 adc_value = ADC_Read( 0 );


 if(adc_value > 512)
 {
 LED_On( 3 ,  0 );
 }
 else
 {
 LED_Off( 3 ,  0 );
 }
 }
}
