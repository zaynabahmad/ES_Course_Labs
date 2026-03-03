#line 1 "C:/Users/DELL/Downloads/ES_Course_Labs-main/LAB11/EXTI.c"
#line 1 "c:/users/dell/downloads/es_course_labs-main/lab11/exti_interface.h"



void EXTI_Init(void);
void EXTI_SetCallBack(void (*Copy_ptr)(void));
#line 1 "c:/users/dell/downloads/es_course_labs-main/lab11/exti_config.h"
#line 1 "c:/users/dell/downloads/es_course_labs-main/lab11/services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 5 "C:/Users/DELL/Downloads/ES_Course_Labs-main/LAB11/EXTI.c"
static void (*EXTI_CallBack)(void) = 0;

void EXTI_Init(void)
{
 TRISB.F0 = 1;


 OPTION_REG.INTEDG = 1;
#line 17 "C:/Users/DELL/Downloads/ES_Course_Labs-main/LAB11/EXTI.c"
 INTCON.INTE = 1;
 INTCON.GIE = 1;
}

void EXTI_SetCallBack(void (*Copy_ptr)(void))
{
 if(Copy_ptr != 0)
 {
 EXTI_CallBack = Copy_ptr;
 }
}


void interrupt()
{
 if(INTCON.INTF == 1)
 {
 INTCON.INTF = 0;

 if(EXTI_CallBack != 0)
 {
 EXTI_CallBack();
 }
 }
}
