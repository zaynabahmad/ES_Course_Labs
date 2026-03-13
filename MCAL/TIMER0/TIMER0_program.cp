#line 1 "C:/Users/HP/Desktop/Drivers/MCAL/TIMER0/TIMER0_program.c"
#line 1 "c:/users/hp/desktop/drivers/mcal/timer0/timer0_interface.h"
#line 1 "c:/users/hp/desktop/drivers/mcal/timer0/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 26 "c:/users/hp/desktop/drivers/mcal/timer0/timer0_interface.h"
void TIMER0_Init(u8 Mode, u8 PrescalerEnable, u8 PrescalerValue);
void TIMER0_Start(void);
void TIMER0_Stop(void);
void TIMER0_SetValue(u8 Value);
u8 TIMER0_GetValue(void);
void TIMER0_SetCallback(void (*Callback)(void));
#line 1 "c:/users/hp/desktop/drivers/mcal/timer0/timer0_private.h"
#line 1 "c:/users/hp/desktop/drivers/mcal/timer0/../../services/bit_math.h"
#line 1 "c:/users/hp/desktop/drivers/mcal/timer0/../../services/std_types.h"
#line 6 "C:/Users/HP/Desktop/Drivers/MCAL/TIMER0/TIMER0_program.c"
void (*TIMER0_Callback)(void) =  ((void*)0) ;

void TIMER0_Init(u8 Mode, u8 PrescalerEnable, u8 PrescalerValue)
{
  ( ( (*((volatile u8*)0x81)) ) &= ~(1U << ( 5 )) ) ;

 if(PrescalerEnable)  ( ( (*((volatile u8*)0x81)) ) &= ~(1U << ( 3 )) ) ;
 else  ( ( (*((volatile u8*)0x81)) ) |= (1U << ( 3 )) ) ;

  (*((volatile u8*)0x81))  &= 0xF8;
  (*((volatile u8*)0x81))  |= (PrescalerValue & 0x07);

  (*((volatile u8*)0x01))  = 0;
 T0IE_bit = 0;
}

void TIMER0_Start(void)
{
 T0IE_bit = 1;
}

void TIMER0_Stop(void)
{
 T0IE_bit = 0;
}

void TIMER0_SetValue(u8 Value)
{
  (*((volatile u8*)0x01))  = Value;
}

u8 TIMER0_GetValue(void)
{
 return  (*((volatile u8*)0x01)) ;
}

void TIMER0_SetCallback(void (*Callback)(void))
{
 TIMER0_Callback = Callback;
}
