#line 1 "D:/Uni/Y4 S2/Embedded Systems/Final/MCAL/GPIO/GPIO_program.c"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"



typedef unsigned char u8;
typedef unsigned int u16;
#line 1 "d:/uni/y4 s2/embedded systems/final/services/bit_math.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/gpio/gpio_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"
#line 12 "d:/uni/y4 s2/embedded systems/final/mcal/gpio/gpio_interface.h"
unsigned char GPIO_voidSetPinDirection(unsigned char port,
 unsigned char pin,
 unsigned char dir);

unsigned char GPIO_voidSetPinValue(unsigned char port,
 unsigned char pin,
 unsigned char val);


unsigned char GPIO_u8GetPinValue(unsigned char port,
 unsigned char pin);

unsigned char GPIO_voidTogglePin(unsigned char port,
 unsigned char pin);

unsigned char GPIO_voidSetPortDirection(unsigned char port,
 unsigned char dir_mask);

unsigned char GPIO_voidSetPortValue(unsigned char port,
 unsigned char value);
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/gpio/gpio_private.h"
#line 6 "D:/Uni/Y4 S2/Embedded Systems/Final/MCAL/GPIO/GPIO_program.c"
static volatile unsigned char* GPIO_prvGetTRIS(unsigned char port)
{
 switch (port)
 {
 case 'A': return & (*(volatile unsigned char*)0x85) ;
 case 'B': return & (*(volatile unsigned char*)0x86) ;
 case 'C': return & (*(volatile unsigned char*)0x87) ;
 case 'D': return & (*(volatile unsigned char*)0x88) ;
 case 'E': return & (*(volatile unsigned char*)0x89) ;
 default: return 0;
 }
}


static volatile unsigned char* GPIO_prvGetPORT(unsigned char port)
{
 switch (port)
 {
 case 'A': return & (*(volatile unsigned char*)0x05) ;
 case 'B': return & (*(volatile unsigned char*)0x06) ;
 case 'C': return & (*(volatile unsigned char*)0x07) ;
 case 'D': return & (*(volatile unsigned char*)0x08) ;
 case 'E': return & (*(volatile unsigned char*)0x09) ;
 default: return 0;
 }
}


unsigned char GPIO_voidSetPinDirection(unsigned char port,
 unsigned char pin,
 unsigned char dir)
{
 volatile unsigned char *tris;


 if (pin >  7u ) { return  0xFFu ; }

 tris = GPIO_prvGetTRIS(port);
 if (tris == 0) { return  0xFFu ; }

 if (dir ==  1u )
  *tris |= (1<<pin) ;
 else
  *tris &= ~(1<<pin) ;

 return  0u ;
}


unsigned char GPIO_voidSetPinValue(unsigned char port,
 unsigned char pin,
 unsigned char val)
{
 volatile unsigned char *preg;

 if (pin >  7u ) { return  0xFFu ; }

 preg = GPIO_prvGetPORT(port);
 if (preg == 0) { return  0xFFu ; }

 if (val ==  1u )
  *preg |= (1<<pin) ;
 else
  *preg &= ~(1<<pin) ;

 return  0u ;
}


unsigned char GPIO_u8GetPinValue(unsigned char port,
 unsigned char pin)
{
 volatile unsigned char *preg;

 if (pin >  7u ) { return  0xFFu ; }

 preg = GPIO_prvGetPORT(port);
 if (preg == 0) { return  0xFFu ; }

 return  ((*preg>>pin)&1) ;
}


unsigned char GPIO_voidTogglePin(unsigned char port,
 unsigned char pin)
{
 volatile unsigned char *preg;

 if (pin >  7u ) { return  0xFFu ; }

 preg = GPIO_prvGetPORT(port);
 if (preg == 0) { return  0xFFu ; }


 TOG_BIT(*preg, pin);

 return  0u ;
}


unsigned char GPIO_voidSetPortDirection(unsigned char port,
 unsigned char dir_mask)
{
 volatile unsigned char *tris = GPIO_prvGetTRIS(port);
 if (tris == 0) { return  0xFFu ; }

 *tris = dir_mask;
 return  0u ;
}


unsigned char GPIO_voidSetPortValue(unsigned char port,
 unsigned char value)
{
 volatile unsigned char *preg = GPIO_prvGetPORT(port);
 if (preg == 0) { return  0xFFu ; }

 *preg = value;
 return  0u ;
}
