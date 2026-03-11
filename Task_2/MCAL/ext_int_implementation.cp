#line 1 "D:/University/Spring_26/Embedded/Task_2/MCAL/ext_int_implementation.c"
#line 1 "d:/university/spring_26/embedded/task_2/mcal/../services/std_types.h"




typedef unsigned char u8;
typedef signed short int s16;
typedef unsigned short int u16;
typedef unsigned long int u32;




typedef unsigned char bool_t;
#line 1 "d:/university/spring_26/embedded/task_2/mcal/ext_int_interface.h"
#line 1 "d:/university/spring_26/embedded/task_2/mcal/../services/std_types.h"
#line 1 "d:/university/spring_26/embedded/task_2/mcal/gpio/gpio_interface.h"
#line 1 "d:/university/spring_26/embedded/task_2/mcal/gpio/../../services/std_types.h"
#line 24 "d:/university/spring_26/embedded/task_2/mcal/gpio/gpio_interface.h"
void set_pin_direction(u8 port, u8 pin, u8 direction);
void set_pin_value(u8 port, u8 pin, u8 value);
u8 get_pin_value(u8 port, u8 pin);
void toggle_pin(u8 port, u8 pin);
#line 7 "d:/university/spring_26/embedded/task_2/mcal/ext_int_interface.h"
void EXT_INTO_Init(void);
void EXT_INTO_Enable(void);
void EXT_INTO_SetEdge(u8 edge_type);
void EXT_INTO_SetCallback(void (*ptr)(void));
#line 1 "d:/university/spring_26/embedded/task_2/mcal//timer/timer_interface.h"
#line 1 "d:/university/spring_26/embedded/task_2/mcal//timer/../../services/std_types.h"
#line 6 "d:/university/spring_26/embedded/task_2/mcal//timer/timer_interface.h"
void TIMER0_Init(void);
void TIMER0_SetPreload(u8 preload);
void TIMER0_SetCallback(void (*ptr)(void));
void TIMER0_ISR_Handler(void);
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stddef.h"




typedef int ptrdiff_t;
typedef int ptrdiffram_t;
typedef long int ptrdiffrom_t;


typedef unsigned int size_t;
typedef unsigned int sizeram_t;
typedef unsigned long int sizerom_t;


typedef unsigned char wchar_t;
#line 7 "D:/University/Spring_26/Embedded/Task_2/MCAL/ext_int_implementation.c"
static void (*ext_int_callback)(void) = 0;

void EXT_INTO_Init(void) {
 set_pin_direction( 1 , 0,  1 );
 INTCON &= ~0x02;
}

void EXT_INTO_Enable(void) {
 INTCON |= 0x10;
 INTCON |= 0x80;
}

void EXT_INTO_SetEdge(u8 edge_type) {
 if(edge_type == 1) {
 OPTION_REG |= 0x40;
 } else {
 OPTION_REG &= ~0x40;
 }
}

void EXT_INTO_SetCallback(void (*ptr)(void)) {
 ext_int_callback = ptr;
}

void interrupt(void) {
 if(INTCON & 0x02) {
 if(ext_int_callback != 0) {
 ext_int_callback();
 }
 INTCON &= ~0x02;
 }
 if(INTCON & 0x04){

 TIMER0_ISR_Handler();

 INTCON &= ~0x04;
 }
}
