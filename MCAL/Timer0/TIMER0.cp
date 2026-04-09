#line 1 "D:/new study/sem2/ES/Drivers/ES_Drivers/MCAL/Timer0/TIMER0.c"
#line 1 "d:/new study/sem2/es/drivers/es_drivers/mcal/timer0/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 1 "d:/new study/sem2/es/drivers/es_drivers/mcal/timer0/../../services/bit_math.h"
#line 1 "d:/new study/sem2/es/drivers/es_drivers/mcal/timer0/timer0_interface.h"
#line 1 "d:/new study/sem2/es/drivers/es_drivers/mcal/timer0/../../services/std_types.h"
#line 10 "d:/new study/sem2/es/drivers/es_drivers/mcal/timer0/timer0_interface.h"
void Timer0_Init(void);
void Timer0_EnableInterrupt(void);
void Timer0_Reset(void);

void Timer0_DisableInterrupt(void);
void TIMER0_ISR(void);
void Timer0_SetCallback(void (*ptr)(void));
void Timer0_EnableGlobalInterrupts(void);
#line 1 "d:/new study/sem2/es/drivers/es_drivers/mcal/timer0/timer0_config.h"
#line 1 "d:/new study/sem2/es/drivers/es_drivers/mcal/timer0/timer0_private.h"
#line 8 "D:/new study/sem2/ES/Drivers/ES_Drivers/MCAL/Timer0/TIMER0.c"
static void (*TIMER0_Callback)(void) = 0;

void Timer0_Init(void)
{


  ( (OPTION_REG) &= ~(1U << ( 5 )) ) ;
#line 20 "D:/new study/sem2/ES/Drivers/ES_Drivers/MCAL/Timer0/TIMER0.c"
  ( (OPTION_REG) &= ~(1U << ( 3 )) ) ;


 OPTION_REG &= 0xF8;
 OPTION_REG |=  0b111 ;


 TMR0 =  61 ;
}


void Timer0_EnableInterrupt(void)
{
  ( (INTCON) |= (1U << ( 5 )) ) ;
  ( (INTCON) |= (1U << ( 7 )) ) ;
}

void Timer0_DisableInterrupt(void)
{
  ( (INTCON) &= ~(1U << ( 5 )) ) ;
}


void Timer0_Reset(void)
{

 TMR0 =  61 ;
}

void Timer0_SetCallback(void (*ptr)(void))
{
 if (ptr != 0)
 {
 TIMER0_Callback = ptr;
 }
}

void TIMER0_ISR(void)
{

 TMR0 = 6;


  ( (INTCON) &= ~(1U << ( 2 )) ) ;


 if (TIMER0_Callback != 0)
 {
 TIMER0_Callback();
 }
}

void Timer0_EnableGlobalInterrupts(void)
{
  ( (INTCON) |= (1U << ( 7 )) ) ;
  ( (INTCON) |= (1U << (PEIE)) ) ;
}
