#line 1 "D:/Timer-week3/Timer/TIMER.c"
#line 1 "d:/timer-week3/timer/timer_interface.h"
#line 1 "d:/timer-week3/services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 5 "d:/timer-week3/timer/timer_interface.h"
void TIMER0_Init(void);
void TIMER0_SetCallback_1Sec(void (*ptr)(void));
void TIMER0_SetCallback_2Sec(void (*ptr)(void));
#line 1 "d:/timer-week3/services/bit_math.h"
#line 5 "D:/Timer-week3/Timer/TIMER.c"
volatile u8 count = 0;
volatile u8 sec = 0;

static void (*TIMER_1Sec_Callback)(void) = 0;
static void (*TIMER_2Sec_Callback)(void) = 0;

void TIMER0_Init(void)
{
  ((INTCON) |= (1 << (5))) ;
  ((INTCON) &= ~(1 << (2))) ;
  ((OPTION_REG) &= ~(1 << (5))) ;
  ((INTCON) |= (1 << (7))) ;
  ((OPTION_REG) &= ~(1 << (3))) ;


  ((OPTION_REG) |= (1 << (0))) ;
  ((OPTION_REG) |= (1 << (1))) ;
  ((OPTION_REG) |= (1 << (2))) ;

 TMR0 = 0;
 count = 0;
 sec = 0;
}

void TIMER0_SetCallback_1Sec(void (*ptr)(void)) { TIMER_1Sec_Callback = ptr; }
void TIMER0_SetCallback_2Sec(void (*ptr)(void)) { TIMER_2Sec_Callback = ptr; }

void interrupt()
{
 if( (((INTCON) >> (2)) & 1) )
 {
  ((INTCON) &= ~(1 << (2))) ;

 if(count < 30) {
 TMR0 = 0;
 count++;
 }
 else if(count == 30) {
 TMR0 = 125;
 count++;
 }
 else {
 count = 0;


 if(TIMER_1Sec_Callback != 0) {
 TIMER_1Sec_Callback();
 }

 sec++;

 if(sec >= 2) {
 if(TIMER_2Sec_Callback != 0) {
 TIMER_2Sec_Callback();
 }
 sec = 0;
 }
 }
 }
}
