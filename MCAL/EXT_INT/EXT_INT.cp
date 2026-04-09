#line 1 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/MCAL/EXT_INT/EXT_INT.c"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/ext_int/ext_int_interface.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/ext_int/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/ext_int/../gpio/gpio_interface.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/ext_int/../gpio/../../services/std_types.h"
#line 31 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/ext_int/../gpio/gpio_interface.h"
void GPIO_SetPinDirection(unsigned char Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8 GPIO_GetPinValue(u8 Port, u8 Pin);
void GPIO_Init(void);
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/ext_int/../../services/bit_math.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/ext_int/ext_int_config.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/ext_int/ext_int_private.h"
#line 22 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/ext_int/ext_int_interface.h"
void EXT_INT_Init(void);
void EXT_INT_Enable(void);
void EXT_INT_Disable(void);
void EXT_INT_SetEdge(u8 Edgetype);
void EXT_INT_SetCallback(void (*Callback)(void));
void EXT_INT_ISR(void);
#line 4 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/MCAL/EXT_INT/EXT_INT.c"
void EXT_INT_Init(void)
{

 GPIO_SetPinDirection( 1 ,  0 ,  1 );

 EXT_INT_SetEdge( 0 );


  ( ( (*((volatile u8*)0x18B)) ) &= ~(1U << ( 1 )) ) ;
  ( ( (*((volatile u8*)0x18B)) ) &= ~(1U << ( 4 )) ) ;

}

void EXT_INT_Enable(void)
{

  ( ( (*((volatile u8*)0x18B)) ) |= (1U << ( 4 )) ) ;

  ( ( (*((volatile u8*)0x18B)) ) |= (1U << ( 7 )) ) ;

  ( ( (*((volatile u8*)0x18B)) ) &= ~(1U << ( 1 )) ) ;
}

void EXT_INT_Disable(void)
{

  ( ( (*((volatile u8*)0x18B)) ) &= ~(1U << ( 1 )) ) ;

  ( ( (*((volatile u8*)0x18B)) ) &= ~(1U << ( 4 )) ) ;

}

void EXT_INT_SetEdge(u8 Edgetype)
{
 if (Edgetype ==  1 )
 {

  ( ( (*((volatile u8*)0x181)) ) &= ~(1U << ( 6 )) ) ;
 }
 else if (Edgetype ==  0 )
 {

  ( ( (*((volatile u8*)0x181)) ) |= (1U << ( 6 )) ) ;
 }
}

void (*EXT_INT_Callback)(void) = 0;

void EXT_INT_SetCallback(void (*ptr)(void)) {
 if (ptr != 0) {
 EXT_INT_Callback = ptr;
 }
}

void EXT_INT_ISR(void)
{

  ( ( (*((volatile u8*)0x18B)) ) &= ~(1U << ( 1 )) ) ;

 if(EXT_INT_Callback != 0)
 {
 EXT_INT_Callback();
 }

}
