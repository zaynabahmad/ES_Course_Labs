#line 1 "D:/University/Spring_26/Embedded/Labs/APP/MyProject.c"
#line 1 "d:/university/spring_26/embedded/labs/app/../hal/led/led_interface.h"
#line 1 "d:/university/spring_26/embedded/labs/app/../hal/led/../../services/std_types.h"




typedef unsigned char u8;
typedef signed short int s16;
typedef unsigned short int u16;
typedef unsigned long int u32;




typedef unsigned char bool_t;
#line 1 "d:/university/spring_26/embedded/labs/app/../hal/led/../../mcal/gpio/gpio_interface.h"
#line 1 "d:/university/spring_26/embedded/labs/app/../hal/led/../../mcal/gpio/../../services/std_types.h"
#line 24 "d:/university/spring_26/embedded/labs/app/../hal/led/../../mcal/gpio/gpio_interface.h"
void set_pin_direction(u8 port, u8 pin, u8 direction);
void set_pin_value(u8 port, u8 pin, u8 value);
u8 get_pin_value(u8 port, u8 pin);
#line 7 "d:/university/spring_26/embedded/labs/app/../hal/led/led_interface.h"
void LED_Init(u8 port, u8 pin);
void LED_ON(u8 port, u8 pin);
void LED_OFF(u8 port, u8 pin);
#line 1 "d:/university/spring_26/embedded/labs/app/../mcal/ext_int_interface.h"
#line 1 "d:/university/spring_26/embedded/labs/app/../mcal/../services/std_types.h"
#line 1 "d:/university/spring_26/embedded/labs/app/../mcal/gpio/gpio_interface.h"
#line 7 "d:/university/spring_26/embedded/labs/app/../mcal/ext_int_interface.h"
void EXT_INTO_Init(void);
void EXT_INTO_Enable(void);
void EXT_INTO_SetEdge(u8 edge_type);
void EXT_INTO_SetCallback(void (*ptr)(void));
#line 4 "D:/University/Spring_26/Embedded/Labs/APP/MyProject.c"
u16 interrupt_count = 0;
u8 seconds_elapsed = 0;





void Toggle_LED_Callback(void) {

 PORTA ^= (1 << 2);
}

int main() {

 LED_Init( 0 , 2);


 EXT_INTO_Init();
 EXT_INTO_SetEdge(1);


 EXT_INTO_SetCallback(Toggle_LED_Callback);


 EXT_INTO_Enable();

 while(1) {

 }

 return 0;
}
