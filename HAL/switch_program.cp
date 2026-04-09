#line 1 "D:/ES-Project-Lab/HAL/switch_program.c"
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
#line 1 "d:/es-project-lab/hal/switch_interface.h"
#line 1 "d:/es-project-lab/services/std_types.h"
#line 5 "d:/es-project-lab/hal/switch_interface.h"
void SWITCH_Init(u8 port, u8 pin);
u8 SWITCH_GetState(u8 port, u8 pin);
#line 5 "D:/ES-Project-Lab/HAL/switch_program.c"
void SWITCH_Init(u8 port, u8 pin)
{
 GPIO_setPinDirection(port, pin,  1 );
}

u8 SWITCH_GetState(u8 port, u8 pin)
{
 return GPIO_getPinValue(port, pin);
}
