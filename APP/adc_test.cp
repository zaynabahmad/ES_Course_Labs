#line 1 "D:/Uni/Y4 S2/Embedded Systems/Final/APP/adc_test.c"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/gpio/gpio_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"



typedef unsigned char u8;
typedef unsigned int u16;
#line 12 "d:/uni/y4 s2/embedded systems/final/mcal/gpio/gpio_interface.h"
unsigned char GPIO_voidSetPinDirection(unsigned char port,
 unsigned char pin,
 unsigned char dir);

unsigned char GPIO_voidSetPinValue(unsigned char port,
 unsigned char pin,
 unsigned char val);


unsigned char GPIO_u8GetPinValue(unsigned char port,
 unsigned char pin);

unsigned char GPIO_voidTogglePin(unsigned char port,
 unsigned char pin);

unsigned char GPIO_voidSetPortDirection(unsigned char port,
 unsigned char dir_mask);

unsigned char GPIO_voidSetPortValue(unsigned char port,
 unsigned char value);
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/adc/adc_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"
#line 8 "d:/uni/y4 s2/embedded systems/final/mcal/adc/adc_interface.h"
void ADC_voidInit(void);

unsigned int ADC_u16Read(unsigned char channel);

float ADC_f32ToVoltage(unsigned int raw_value);
#line 4 "D:/Uni/Y4 S2/Embedded Systems/Final/APP/adc_test.c"
void ADC_Test(void)
{
 unsigned int adc_raw;
 float voltage_mv;


 GPIO_voidSetPinDirection('B', 0, 0);
 GPIO_voidSetPinDirection('B', 1, 0);


 ADC_voidInit();

 while (1)
 {

 adc_raw = ADC_u16Read(0);


 if (adc_raw ==  0xFFFFu )
 {

 GPIO_voidSetPinValue('B', 0, 0);
 GPIO_voidSetPinValue('B', 1, 0);
 continue;
 }


 voltage_mv = ADC_f32ToVoltage(adc_raw);
 (void)voltage_mv;


 if (adc_raw > 512u)
 {

 GPIO_voidSetPinValue('B', 0, 1);
 GPIO_voidSetPinValue('B', 1, 0);
 }
 else if (adc_raw > 256u)
 {

 GPIO_voidSetPinValue('B', 0, 0);
 GPIO_voidSetPinValue('B', 1, 1);
 }
 else
 {

 GPIO_voidSetPinValue('B', 0, 0);
 GPIO_voidSetPinValue('B', 1, 0);
 }
 }
}
