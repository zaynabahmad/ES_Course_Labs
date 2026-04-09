#line 1 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/MCAL/i2c/I2C.c"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/i2c/i2c_interface.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/i2c/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 6 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/i2c/i2c_interface.h"
void I2C_Master_Init(u32 Clock);
void I2C_Master_Wait(void);
void I2C_Master_Start(void);
void I2C_Master_RepeatedStart(void);
void I2C_Master_Stop(void);
void I2C_Master_Write(u8 Data);
u8 I2C_Master_Read(u8 Ack);
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/i2c/i2c_private.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/i2c/../../services/std_types.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/i2c/../gpio/gpio_interface.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/i2c/../gpio/../../services/std_types.h"
#line 31 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/i2c/../gpio/gpio_interface.h"
void GPIO_SetPinDirection(unsigned char Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8 GPIO_GetPinValue(u8 Port, u8 Pin);
void GPIO_Init(void);
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/i2c/../../services/bit_math.h"
#line 6 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/MCAL/i2c/I2C.c"
void I2C_Master_Init(u32 Clock) {

 GPIO_SetPinDirection( 1 ,  0 ,  1 );
 GPIO_SetPinDirection( 1 ,  1 ,  1 );


  (*((volatile u8*)0x14))  = 0x28;


  (*((volatile u8*)0x93))  = (u8)((4000000 / (4 * Clock)) - 1);


  (*((volatile u8*)0x94))  = 0x80;
}

void I2C_Master_Wait(void) {

 while (( (*((volatile u8*)0x94))  & 0x04) || ( (*((volatile u8*)0x91))  & 0x1F));
}

void I2C_Master_Start(void) {
 I2C_Master_Wait();
  ( ( (*((volatile u8*)0x91)) ) |= (1U << ( 0 )) ) ;
}

void I2C_Master_RepeatedStart(void) {
 I2C_Master_Wait();
  ( ( (*((volatile u8*)0x91)) ) |= (1U << ( 1 )) ) ;
}

void I2C_Master_Stop(void) {
 I2C_Master_Wait();
  ( ( (*((volatile u8*)0x91)) ) |= (1U << ( 2 )) ) ;
}

void I2C_Master_Write(u8 Data) {
 I2C_Master_Wait();
  (*((volatile u8*)0x13))  = Data;
}

u8 I2C_Master_Read(u8 Ack) {
 u8 local_data;
 I2C_Master_Wait();

  ( ( (*((volatile u8*)0x91)) ) |= (1U << ( 3 )) ) ;

 I2C_Master_Wait();
 local_data =  (*((volatile u8*)0x13)) ;

 I2C_Master_Wait();

 if(Ack)  ( ( (*((volatile u8*)0x91)) ) &= ~(1U << ( 5 )) ) ;
 else  ( ( (*((volatile u8*)0x91)) ) |= (1U << ( 5 )) ) ;

  ( ( (*((volatile u8*)0x91)) ) |= (1U << ( 4 )) ) ;

 return local_data;
}
