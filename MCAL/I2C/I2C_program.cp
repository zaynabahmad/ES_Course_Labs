#line 1 "D:/Uni/Y4 S2/Embedded Systems/Final/MCAL/I2C/I2C_program.c"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"



typedef unsigned char u8;
typedef unsigned int u16;
#line 1 "d:/uni/y4 s2/embedded systems/final/services/bit_math.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/i2c/i2c_private.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/i2c/i2c_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"
#line 18 "d:/uni/y4 s2/embedded systems/final/mcal/i2c/i2c_interface.h"
void I2C_voidInit(void);

void I2C_voidStart(void);

void I2C_voidRepeatedStart(void);

void I2C_voidStop(void);

unsigned char I2C_u8Write(unsigned char data);

unsigned char I2C_u8Read(unsigned char send_ack);

void I2C_voidWaitIdle(void);
#line 7 "D:/Uni/Y4 S2/Embedded Systems/Final/MCAL/I2C/I2C_program.c"
void I2C_voidWaitIdle(void)
{

 while ((( (*(volatile unsigned char*)0x91)  & 0x1Fu) != 0u) ||
 ( (( (*(volatile unsigned char*)0x94) >> 2 )&1)  != 0u))
 {

 }
}


void I2C_voidInit(void)
{

  (*(volatile unsigned char*)0x87)  |= (1<< 3u ) ;
  (*(volatile unsigned char*)0x87)  |= (1<< 4u ) ;

  (*(volatile unsigned char*)0x14)  =  0x08u ;

  (*(volatile unsigned char*)0x93)  =  19u ;

  (*(volatile unsigned char*)0x14)  |= (1<<5u) ;

  (*(volatile unsigned char*)0x0C)  &= ~(1<< 3 ) ;
}


void I2C_voidStart(void)
{

 I2C_voidWaitIdle();


  (*(volatile unsigned char*)0x91)  |= (1<< 0 ) ;


 while ( (( (*(volatile unsigned char*)0x91) >> 0 )&1) )
 {

 }
}


void I2C_voidRepeatedStart(void)
{
 I2C_voidWaitIdle();
  (*(volatile unsigned char*)0x91)  |= (1<< 1 ) ;
 while ( (( (*(volatile unsigned char*)0x91) >> 1 )&1) )
 {

 }
}


void I2C_voidStop(void)
{
 I2C_voidWaitIdle();


  (*(volatile unsigned char*)0x91)  |= (1<< 2 ) ;


 while ( (( (*(volatile unsigned char*)0x91) >> 2 )&1) )
 {

 }
}


unsigned char I2C_u8Write(unsigned char data)
{

 I2C_voidWaitIdle();


  (*(volatile unsigned char*)0x13)  = data;

 while ( (( (*(volatile unsigned char*)0x94) >> 0 )&1) )
 {

 }


 I2C_voidWaitIdle();


 if ( (( (*(volatile unsigned char*)0x91) >> 6 )&1)  == 1u)
 {
 return  1u ;
 }

 return  0u ;
}


unsigned char I2C_u8Read(unsigned char send_ack)
{
 unsigned char received;

 I2C_voidWaitIdle();


  (*(volatile unsigned char*)0x91)  |= (1<< 3 ) ;


 while (! (( (*(volatile unsigned char*)0x94) >> 0 )&1) )
 {

 }


 received =  (*(volatile unsigned char*)0x13) ;

 I2C_voidWaitIdle();


 if (send_ack == 1u)
  (*(volatile unsigned char*)0x91)  &= ~(1<< 5 ) ;
 else
  (*(volatile unsigned char*)0x91)  |= (1<< 5 ) ;


  (*(volatile unsigned char*)0x91)  |= (1<< 4 ) ;


 while ( (( (*(volatile unsigned char*)0x91) >> 4 )&1) )
 {

 }

 return received;
}
