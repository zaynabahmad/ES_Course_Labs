#line 1 "D:/University/Spring_26/Embedded/Task_2/MCAL/TIMER/timer_implementation.c"
#line 1 "d:/university/spring_26/embedded/task_2/mcal/timer/../../services/std_types.h"




typedef unsigned char u8;
typedef signed short int s16;
typedef unsigned short int u16;
typedef unsigned long int u32;




typedef unsigned char bool_t;
#line 1 "d:/university/spring_26/embedded/task_2/mcal/timer/../../services/bit_math.h"
#line 1 "d:/university/spring_26/embedded/task_2/mcal/timer/timer_interface.h"
#line 1 "d:/university/spring_26/embedded/task_2/mcal/timer/../../services/std_types.h"
#line 6 "d:/university/spring_26/embedded/task_2/mcal/timer/timer_interface.h"
void TIMER0_Init(void);
void TIMER0_SetPreload(u8 preload);
void TIMER0_SetCallback(void (*ptr)(void));
void TIMER0_ISR_Handler(void);
#line 7 "D:/University/Spring_26/Embedded/Task_2/MCAL/TIMER/timer_implementation.c"
static void (*timer_callback)(void) = 0;

void TIMER0_ISR_Handler(void)
{

 if(timer_callback != 0)
 {
 timer_callback();
 }
}

void TIMER0_Init(void)
{

  (OPTION_REG &= ~(1 << 5)) ;


  (OPTION_REG &= ~(1 << 3)) ;


  (OPTION_REG |= (1 << 2)) ;
  (OPTION_REG |= (1 << 1)) ;
  (OPTION_REG |= (1 << 0)) ;


  (INTCON |= (1 << 5)) ;


  (INTCON |= (1 << 7)) ;
}

void TIMER0_SetPreload(u8 preload)
{
 TMR0 = preload;
}

void TIMER0_SetCallback(void (*ptr)(void))
{

 timer_callback = ptr;
}
