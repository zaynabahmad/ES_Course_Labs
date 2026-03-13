#line 1 "C:/Users/HP/Desktop/Drivers/MCAL/INTERRUPT/INT_program.c"
#line 1 "c:/users/hp/desktop/drivers/mcal/interrupt/int_interface.h"
#line 1 "c:/users/hp/desktop/drivers/mcal/interrupt/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 9 "c:/users/hp/desktop/drivers/mcal/interrupt/int_interface.h"
void EXT_INT_Init(u8 Edge);
void EXT_INT_Enable(void);
void EXT_INT_Disable(void);
void EXT_INT_SetCallback(void (*Callback)(void));
#line 1 "c:/users/hp/desktop/drivers/mcal/interrupt/int_private.h"
#line 1 "c:/users/hp/desktop/drivers/mcal/interrupt/../../services/bit_math.h"
#line 1 "c:/users/hp/desktop/drivers/mcal/interrupt/../../services/std_types.h"
#line 6 "C:/Users/HP/Desktop/Drivers/MCAL/INTERRUPT/INT_program.c"
static void (*EXT0_Callback)(void) =  ((void*)0) ;
extern void (*TIMER0_Callback)(void);
void EXT_INT_Init(u8 Edge)
{
 if(Edge ==  1 )
  ( (OPTION_REG) |= (1U << (6)) ) ;
 else
  ( (OPTION_REG) &= ~(1U << (6)) ) ;
}

void EXT_INT_Enable(void)
{
  ( (INTCON) |= (1U << (4)) ) ;
}

void EXT_INT_Disable(void)
{
  ( (INTCON) &= ~(1U << (4)) ) ;
}

void EXT_INT_SetCallback(void (*Callback)(void))
{
 EXT0_Callback = Callback;
}

void interrupt()
{


 if( INTCON.INTF  && EXT0_Callback !=  ((void*)0) )
 {
  INTCON.INTF  = 0;
 EXT0_Callback();
 }



 if(T0IF_bit)
 {
 T0IF_bit = 0;

 if(TIMER0_Callback !=  ((void*)0) )
 {
 TIMER0_Callback();
 }
 }
}
