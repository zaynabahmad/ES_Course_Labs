#line 1 "D:/ES-Project-Lab/MCAL/EXTI/exti_program.c"
#line 1 "d:/es-project-lab/mcal/exti/../../services/std_types.h"



typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
#line 1 "d:/es-project-lab/services/bit_math.h"
#line 1 "d:/es-project-lab/mcal/exti/exti_prv.h"
#line 1 "d:/es-project-lab/mcal/exti/exti_interface.h"
#line 1 "d:/es-project-lab/services/std_types.h"
#line 10 "d:/es-project-lab/mcal/exti/exti_interface.h"
void EXTI_init(u8 edge);


void EXTI_setCallback(void (*ptr)(void));


extern volatile u8 exti_flag;
extern volatile u8 timer0_flag;
#line 7 "D:/ES-Project-Lab/MCAL/EXTI/exti_program.c"
static void (*EXTI_CallBackPtr)(void) =  ((void*)0) ;

void EXTI_init(u8 edge) {

  (( *((volatile u8*)0x0B) ) |= (1 << ( 7 ))) ;


  (( *((volatile u8*)0x0B) ) |= (1 << ( 4 ))) ;


 if(edge ==  1 ) {
  (( *((volatile u8*)0x81) ) |= (1 << ( 6 ))) ;
 } else {
  (( *((volatile u8*)0x81) ) &= ~(1 << ( 6 ))) ;
 }
}

void EXTI_setCallback(void (*ptr)(void)) {
 if(ptr !=  ((void*)0) ) {
 EXTI_CallBackPtr = ptr;
 }
}



volatile u8 exti_flag = 0;
volatile u8 timer0_flag = 0;



void interrupt() {


 if ( ((( *((volatile u8*)0x0B) ) >> ( 1 )) & 0x01)  == 1) {
 exti_flag = 1;
  (( *((volatile u8*)0x0B) ) &= ~(1 << ( 1 ))) ;
 }


 if ( ((( *((volatile u8*)0x0B) ) >> (TMR0IF)) & 0x01)  == 1) {
 timer0_flag = 1;
  (( *((volatile u8*)0x0B) ) &= ~(1 << (TMR0IF))) ;
 }
}
