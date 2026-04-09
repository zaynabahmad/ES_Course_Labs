#line 1 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/MCAL/ADC/ADC.c"
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
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/adc/adc_private.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/adc/../../services/std_types.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/adc/../../services/bit_math.h"
#line 5 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/MCAL/ADC/ADC.c"
void ADC_Init(void) {

  (*((volatile u8*)0x9F))  = 0x80;


  ( ( (*((volatile u8*)0x1F)) ) |= (1U << ( 0 )) ) ;
}

u16 ADC_ReadChannel(u8 Channel) {
 u16 result = 0;


  (*((volatile u8*)0x1F))  &= 0xC7;
  (*((volatile u8*)0x1F))  |= (Channel << 3);




  ( ( (*((volatile u8*)0x1F)) ) |= (1U << ( 2 )) ) ;


 while ( ( (( (*((volatile u8*)0x1F)) ) >> ( 2 )) & 1U )  == 1);


 result = ((u16) (*((volatile u8*)0x1E))  << 8) |  (*((volatile u8*)0x9E)) ;

 return result;
}
