#line 1 "D:/ES-Project-Lab/APP/i2c_test.c"
#line 1 "d:/es-project-lab/services/std_types.h"



typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
#line 1 "d:/es-project-lab/mcal/gpio/gpio.h"
#line 1 "d:/es-project-lab/services/std_types.h"
#line 27 "d:/es-project-lab/mcal/gpio/gpio.h"
void GPIO_setPinDirection(u8 port, u8 pin, u8 direction);
void GPIO_setPinValue(u8 port, u8 pin, u8 value);
u8 GPIO_getPinValue(u8 port, u8 pin);
void GPIO_setPortDirection(u8 port, u8 direction);
void GPIO_setPortValue(u8 port, u8 value);
#line 1 "d:/es-project-lab/mcal/i2c/i2c_interface.h"
#line 1 "d:/es-project-lab/services/std_types.h"
#line 6 "d:/es-project-lab/mcal/i2c/i2c_interface.h"
void I2C_Init(void);
void I2C_Start(void);
void I2C_RepeatedStart(void);
void I2C_Stop(void);

u8 I2C_Write(u8 txValue);
u8 I2C_ReadAck(void);
u8 I2C_ReadNack(void);
#line 1 "d:/es-project-lab/hal/led_interface.h"
void LED_Init(u8 port, u8 pin);
void LED_On(u8 port, u8 pin);
void LED_Off(u8 port, u8 pin);
void LED_Toggle(u8 port, u8 pin);
#line 5 "D:/ES-Project-Lab/APP/i2c_test.c"
void app_i2c_test(void)
{
 u8 ackStatus = 0;
 u16 delayValue = 0;

 GPIO_setPinDirection( 3 ,  0 ,  0 );

 I2C_Init();

 while(1)
 {
 I2C_Start();


 ackStatus = I2C_Write(0xA0);

 if(ackStatus == 0)
 {
 I2C_Write(0x00);
 I2C_Write(0x55);
 LED_On( 3 ,  0 );
 }
 else
 {
 LED_Off( 3 ,  0 );
 }

 I2C_Stop();

 for(delayValue = 0; delayValue < 10000; delayValue++)
 {
 ;
 }
 }
}
