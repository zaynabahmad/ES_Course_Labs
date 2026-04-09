#line 1 "D:/ES-Project-Lab/MCAL/ADC/adc_program.c"
#line 1 "d:/es-project-lab/services/std_types.h"



typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
#line 1 "d:/es-project-lab/services/bit_math.h"
#line 1 "d:/es-project-lab/mcal/adc/adc_prv.h"
#line 1 "d:/es-project-lab/services/std_types.h"
#line 1 "d:/es-project-lab/mcal/adc/adc_interface.h"
#line 1 "d:/es-project-lab/services/std_types.h"
#line 15 "d:/es-project-lab/mcal/adc/adc_interface.h"
void ADC_Init(void);
u16 ADC_Read(u8 channel);
#line 6 "D:/ES-Project-Lab/MCAL/ADC/adc_program.c"
void ADC_Init(void)
{

  (( (*((volatile u8*)0x9F)) ) |= (1 << ( 7 ))) ;


  (( (*((volatile u8*)0x9F)) ) &= ~(1 << ( 6 ))) ;
  (( (*((volatile u8*)0x1F)) ) |= (1 << ( 7 ))) ;
  (( (*((volatile u8*)0x1F)) ) &= ~(1 << ( 6 ))) ;


  (( (*((volatile u8*)0x1F)) ) |= (1 << ( 0 ))) ;
}

u16 ADC_Read(u8 channel)
{
 u8 local_u8Counter = 0;
 u16 result = 0;


  (( (*((volatile u8*)0x1F)) ) &= ~(1 << ( 3 ))) ;
  (( (*((volatile u8*)0x1F)) ) &= ~(1 << ( 4 ))) ;
  (( (*((volatile u8*)0x1F)) ) &= ~(1 << ( 5 ))) ;


 if(channel & 0x01)  (( (*((volatile u8*)0x1F)) ) |= (1 << ( 3 ))) ;
 if(channel & 0x02)  (( (*((volatile u8*)0x1F)) ) |= (1 << ( 4 ))) ;
 if(channel & 0x04)  (( (*((volatile u8*)0x1F)) ) |= (1 << ( 5 ))) ;


 for(local_u8Counter = 0; local_u8Counter < 20; local_u8Counter++)
 {
 ;
 }


  (( (*((volatile u8*)0x1F)) ) |= (1 << ( 2 ))) ;


 while( ((( (*((volatile u8*)0x1F)) ) >> ( 2 )) & 0x01)  == 1)
 {
 ;
 }


 result = ((u16) (*((volatile u8*)0x1E))  << 8) |  (*((volatile u8*)0x9E)) ;

 return result;
}
