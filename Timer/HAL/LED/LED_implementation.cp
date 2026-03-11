#line 1 "D:/University/Spring_26/Embedded/Task_2/HAL/LED/LED_implementation.c"
#line 1 "d:/university/spring_26/embedded/task_2/hal/led/../../services/std_types.h"




typedef unsigned char u8;
typedef signed short int s16;
typedef unsigned short int u16;
typedef unsigned long int u32;




typedef unsigned char bool_t;
#line 1 "d:/university/spring_26/embedded/task_2/hal/led/led_interface.h"
#line 1 "d:/university/spring_26/embedded/task_2/hal/led/../../services/std_types.h"
#line 1 "d:/university/spring_26/embedded/task_2/hal/led/../../mcal/gpio/gpio_interface.h"
#line 1 "d:/university/spring_26/embedded/task_2/hal/led/../../mcal/gpio/../../services/std_types.h"
#line 24 "d:/university/spring_26/embedded/task_2/hal/led/../../mcal/gpio/gpio_interface.h"
void set_pin_direction(u8 port, u8 pin, u8 direction);
void set_pin_value(u8 port, u8 pin, u8 value);
u8 get_pin_value(u8 port, u8 pin);
void toggle_pin(u8 port, u8 pin);
#line 7 "d:/university/spring_26/embedded/task_2/hal/led/led_interface.h"
void LED_Init(u8 port, u8 pin);
void LED_ON(u8 port, u8 pin);
void LED_OFF(u8 port, u8 pin);
void LED_Toggle(u8 port, u8 pin);
#line 4 "D:/University/Spring_26/Embedded/Task_2/HAL/LED/LED_implementation.c"
void LED_Init(u8 port, u8 pin) {
 set_pin_direction(port, pin,  0 );
}

void LED_ON(u8 port, u8 pin) {
 set_pin_value(port, pin,  1 );
}

void LED_OFF(u8 port, u8 pin) {
 set_pin_value(port, pin,  0 );
}
void LED_Toggle(u8 port, u8 pin) {
 toggle_pin(port, pin);
}
