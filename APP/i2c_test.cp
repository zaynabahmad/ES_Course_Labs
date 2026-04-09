#line 1 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/APP/i2c_test.c"
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
#line 3 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/APP/i2c_test.c"
void i2c_test_run(void) {
 I2C_Master_Init(100000);
 I2C_Master_Start();
 I2C_Master_Write(0xA0);
 I2C_Master_Write(0x00);
 I2C_Master_Write(0xFF);
 I2C_Master_Stop();
}
