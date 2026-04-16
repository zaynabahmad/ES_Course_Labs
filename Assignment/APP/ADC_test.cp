#line 1 "D:/mikroC PRO for PIC/Examples/APP/ADC_test.c"
#line 1 "d:/mikroc pro for pic/examples/app/../mcal/adc/adc_interface.h"





void ADC_voidInit(void);
u16 ADC_u16ReadChannel(u8 channel);
#line 3 "D:/mikroC PRO for PIC/Examples/APP/ADC_test.c"
void ADC_Test(void)
{
 ADC_voidInit();

 u16 value;

 while(1)
 {
 value = ADC_u16ReadChannel(0);
 }
}
