#line 1 "D:/ES-Project-Lab/APP/motor_test .c"
#line 1 "d:/es-project-lab/services/std_types.h"



typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
#line 1 "d:/es-project-lab/hal/motor_interface.h"
#line 1 "d:/es-project-lab/services/std_types.h"
#line 6 "d:/es-project-lab/hal/motor_interface.h"
void MOTOR_Init(u8 port1, u8 pin1, u8 port2, u8 pin2);
void MOTOR_Forward(u8 port1, u8 pin1, u8 port2, u8 pin2);
void MOTOR_Reverse(u8 port1, u8 pin1, u8 port2, u8 pin2);
void MOTOR_Stop(u8 port1, u8 pin1, u8 port2, u8 pin2);
#line 1 "d:/es-project-lab/mcal/gpio/gpio.h"
#line 1 "d:/es-project-lab/services/std_types.h"
#line 27 "d:/es-project-lab/mcal/gpio/gpio.h"
void GPIO_setPinDirection(u8 port, u8 pin, u8 direction);
void GPIO_setPinValue(u8 port, u8 pin, u8 value);
u8 GPIO_getPinValue(u8 port, u8 pin);
void GPIO_setPortDirection(u8 port, u8 direction);
void GPIO_setPortValue(u8 port, u8 value);
#line 4 "D:/ES-Project-Lab/APP/motor_test .c"
void app_motor_test(void)
{
 u16 delayValue = 0;

 MOTOR_Init( 3 ,  0 ,  3 ,  1 );

 while(1)
 {
 MOTOR_Forward( 3 ,  0 ,  3 ,  1 );
 for(delayValue = 0; delayValue < 20000; delayValue++) { ; }

 MOTOR_Stop( 3 ,  0 ,  3 ,  1 );
 for(delayValue = 0; delayValue < 10000; delayValue++) { ; }

 MOTOR_Reverse( 3 ,  0 ,  3 ,  1 );
 for(delayValue = 0; delayValue < 20000; delayValue++) { ; }

 MOTOR_Stop( 3 ,  0 ,  3 ,  1 );
 for(delayValue = 0; delayValue < 10000; delayValue++) { ; }
 }
}
