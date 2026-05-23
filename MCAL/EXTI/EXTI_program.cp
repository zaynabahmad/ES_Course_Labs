#line 1 "D:/Uni/Y4 S2/Embedded Systems/Final/MCAL/EXTI/EXTI_program.c"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"



typedef unsigned char u8;
typedef unsigned int u16;
#line 1 "d:/uni/y4 s2/embedded systems/final/services/bit_math.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/exti/exti_private.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/exti/exti_interface.h"



void EXTI_voidEnable(void);
#line 7 "D:/Uni/Y4 S2/Embedded Systems/Final/MCAL/EXTI/EXTI_program.c"
void EXTI_voidEnable(void)
{
  (*(volatile unsigned char*)0x0B)  |= (1<<7) ;
  (*(volatile unsigned char*)0x0B)  |= (1<<4) ;
}
