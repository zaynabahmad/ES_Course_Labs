#line 1 "D:/Uni/Y4 S2/Embedded Systems/Final/MCAL/TIMER0/TIMER0_program.c"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"



typedef unsigned char u8;
typedef unsigned int u16;
#line 1 "d:/uni/y4 s2/embedded systems/final/services/bit_math.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/timer0/timer0_private.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/timer0/timer0_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"
#line 12 "d:/uni/y4 s2/embedded systems/final/mcal/timer0/timer0_interface.h"
void TIMER0_voidInit(void);

void TIMER0_voidDelayMs(unsigned char ms);

void TIMER0_voidSetPreload(unsigned char preload);

void TIMER0_voidEnableInterrupt(void);

void TIMER0_voidDisableInterrupt(void);

void TIMER0_voidClearFlag(void);

unsigned char TIMER0_u8GetFlag(void);
#line 7 "D:/Uni/Y4 S2/Embedded Systems/Final/MCAL/TIMER0/TIMER0_program.c"
void TIMER0_voidInit(void)
{

  (*(volatile unsigned char*)0x81)  &= ~(1<< 5 ) ;

  (*(volatile unsigned char*)0x81)  &= ~(1<< 3 ) ;

  (*(volatile unsigned char*)0x81)  &= ~(0x07u);
  (*(volatile unsigned char*)0x81)  |=  0x02u ;


  (*(volatile unsigned char*)0x01)  =  6u ;


  (*(volatile unsigned char*)0x0B)  &= ~(1<< 2 ) ;
}


void TIMER0_voidDelayMs(unsigned char ms)
{
 unsigned char i;


 for (i = 0u; i < ms; i++)
 {

  (*(volatile unsigned char*)0x01)  =  6u ;


  (*(volatile unsigned char*)0x0B)  &= ~(1<< 2 ) ;


 while ( (( (*(volatile unsigned char*)0x0B) >> 2 )&1)  == 0u)
 {

 }
 }


  (*(volatile unsigned char*)0x0B)  &= ~(1<< 2 ) ;
}


void TIMER0_voidSetPreload(unsigned char preload)
{

  (*(volatile unsigned char*)0x01)  = preload;
}


void TIMER0_voidEnableInterrupt(void)
{

  (*(volatile unsigned char*)0x0B)  &= ~(1<< 2 ) ;


  (*(volatile unsigned char*)0x0B)  |= (1<< 5 ) ;


  (*(volatile unsigned char*)0x0B)  |= (1<< 7 ) ;
}


void TIMER0_voidDisableInterrupt(void)
{

  (*(volatile unsigned char*)0x0B)  &= ~(1<< 5 ) ;
}


void TIMER0_voidClearFlag(void)
{

  (*(volatile unsigned char*)0x0B)  &= ~(1<< 2 ) ;
}


unsigned char TIMER0_u8GetFlag(void)
{
 return  (( (*(volatile unsigned char*)0x0B) >> 2 )&1) ;
}
