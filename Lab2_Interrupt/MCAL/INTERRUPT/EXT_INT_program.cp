#line 1 "D:/Lab2_Interrupt/MCAL/INTERRUPT/EXT_INT_program.c"
#line 1 "d:/lab2_interrupt/mcal/interrupt/ext_int_interface.h"
#line 1 "d:/lab2_interrupt/mcal/interrupt/../../services/std_types.h"



typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long uint32;
#line 11 "d:/lab2_interrupt/mcal/interrupt/ext_int_interface.h"
void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);
void EXT_INT0_SetEdge(uint8 edge_type);
void EXT_INT0_ClearFlag(void);
void EXT_INT0_SetCallback(void (*ptr)(void));
#line 1 "d:/lab2_interrupt/mcal/interrupt/../../services/bit_math.h"
#line 23 "D:/Lab2_Interrupt/MCAL/INTERRUPT/EXT_INT_program.c"
static void (*EXT_INT0_Callback)(void) = 0;


void EXT_INT0_SetCallback(void (*ptr)(void))
{
 EXT_INT0_Callback = ptr;
}


void EXT_INT0_Init(void)
{

  ((TRISB) |= (1 << (0))) ;


  ((OPTION_REG) &= ~(1 << ( 6 ))) ;


 EXT_INT0_ClearFlag();
}


void EXT_INT0_SetEdge(uint8 edge_type)
{
 if(edge_type ==  1 )
  ((OPTION_REG) |= (1 << ( 6 ))) ;
 else
  ((OPTION_REG) &= ~(1 << ( 6 ))) ;
}


void EXT_INT0_Enable(void)
{
  ((INTCON) |= (1 << ( 4 ))) ;
  ((INTCON) |= (1 << ( 7 ))) ;
}


void EXT_INT0_Disable(void)
{
  ((INTCON) &= ~(1 << ( 4 ))) ;
}


void EXT_INT0_ClearFlag(void)
{
  ((INTCON) &= ~(1 << ( 1 ))) ;
}
#line 80 "D:/Lab2_Interrupt/MCAL/INTERRUPT/EXT_INT_program.c"
void interrupt(void)
{

 if( (((INTCON) >> ( 1 )) & 1) )
 {

 if(EXT_INT0_Callback != 0)
 {
 EXT_INT0_Callback();
 }


 EXT_INT0_ClearFlag();
 }
}
