#line 1 "E:/embedded/Drivers_Project/APP/adc_test.c"
#line 1 "e:/embedded/drivers_project/app/adc_test.h"



void ADC_Test(void);
#line 1 "e:/embedded/drivers_project/app/../mcal/adc/adc_interface.h"



void ADC_Init(void);
unsigned int ADC_Read(unsigned char channel);
#line 1 "e:/embedded/drivers_project/app/../mcal/gpio/gpio_interface.h"
#line 27 "e:/embedded/drivers_project/app/../mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(unsigned char port, unsigned char pin, unsigned char direction);
void GPIO_WritePin(unsigned char port, unsigned char pin, unsigned char value);
unsigned char GPIO_ReadPin(unsigned char port, unsigned char pin);
void GPIO_TogglePin(unsigned char port, unsigned char pin);
#line 5 "E:/embedded/Drivers_Project/APP/adc_test.c"
void ADC_Test(void)
{
 unsigned int value;

 GPIO_SetPinDirection( 1 ,  0 ,  0 );

 ADC_Init();

 while(1)
 {
 value = ADC_Read(0);

 if(value > 512)
 GPIO_WritePin( 1 ,  0 ,  1 );
 else
 GPIO_WritePin( 1 ,  0 ,  0 );
 }
}
