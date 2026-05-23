#line 1 "D:/Uni/Y4 S2/Embedded Systems/Final/MCAL/ADC/ADC_program.c"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"



typedef unsigned char u8;
typedef unsigned int u16;
#line 1 "d:/uni/y4 s2/embedded systems/final/services/bit_math.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/adc/adc_private.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/adc/adc_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"
#line 8 "d:/uni/y4 s2/embedded systems/final/mcal/adc/adc_interface.h"
void ADC_voidInit(void);

unsigned int ADC_u16Read(unsigned char channel);

float ADC_f32ToVoltage(unsigned int raw_value);
#line 7 "D:/Uni/Y4 S2/Embedded Systems/Final/MCAL/ADC/ADC_program.c"
void ADC_voidInit(void)
{
  (*(volatile unsigned char*)0x9F)  =  0x8E ;

  (*(volatile unsigned char*)0x1F)  = 0x00;

  (*(volatile unsigned char*)0x1F)  |= (unsigned char)( 0x01  <<  6 );

  (*(volatile unsigned char*)0x1F)  |= (1<< 0 ) ;
}


unsigned int ADC_u16Read(unsigned char channel)
{
 unsigned int result;
 unsigned char delay_cnt;


 if (channel >  7u )
 {
 return  0xFFFFu ;
 }

  (*(volatile unsigned char*)0x1F)  &=  0b11000111 ;
  (*(volatile unsigned char*)0x1F)  |= (unsigned char)(channel <<  3 );

 for (delay_cnt = 0; delay_cnt <  40u ; delay_cnt++)
 {

 }


  (*(volatile unsigned char*)0x1F)  |= (1<< 2 ) ;


 while ( (( (*(volatile unsigned char*)0x1F) >> 2 )&1) )
 {

 }


 result = (unsigned int)(((unsigned int)( (*(volatile unsigned char*)0x1E)  & 0x03u) << 8u)
 | (unsigned int) (*(volatile unsigned char*)0x9E) );

 return result;
}


float ADC_f32ToVoltage(unsigned int raw_value)
{

 return (float)raw_value * 4.8828f;
}
