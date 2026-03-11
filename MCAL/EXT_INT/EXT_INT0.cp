#line 1 "C:/Users/Z B O O K/Downloads/Week2/ES_Course_Labs-main/MCAL/EXT_INT/EXT_INT0.c"
#line 1 "c:/users/z b o o k/downloads/week2/es_course_labs-main/mcal/ext_int/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 1 "c:/users/z b o o k/downloads/week2/es_course_labs-main/mcal/ext_int/ext_int0_interface.h"
#line 1 "c:/users/z b o o k/downloads/week2/es_course_labs-main/mcal/ext_int/../../services/std_types.h"
#line 11 "c:/users/z b o o k/downloads/week2/es_course_labs-main/mcal/ext_int/ext_int0_interface.h"
void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);
void EXT_INT0_SetEdge(u8 edge_type);
void EXT_INT0_SetCallback(void (*ptr)(void));
#line 1 "c:/users/z b o o k/downloads/week2/es_course_labs-main/mcal/ext_int/ext_int0_config.h"
#line 6 "C:/Users/Z B O O K/Downloads/Week2/ES_Course_Labs-main/MCAL/EXT_INT/EXT_INT0.c"
static void (*EXT_INT0_Callback)(void) = 0;

void EXT_INT0_Init(void) {

 TRISB0_bit = 1;





 INTEDG_bit = 0;



 INTF_bit = 0;
}

void EXT_INT0_Enable(void) {
 INTE_bit = 1;
 GIE_bit = 1;
}

void EXT_INT0_Disable(void) {
 INTE_bit = 0;
}

void EXT_INT0_SetEdge(u8 edge_type) {
 if (edge_type ==  1 ) {
 INTEDG_bit = 1;
 } else if (edge_type ==  0 ) {
 INTEDG_bit = 0;
 }
}

void EXT_INT0_SetCallback(void (*ptr)(void)) {
 if (ptr != 0) {
 EXT_INT0_Callback = ptr;
 }
}


void interrupt(void) {

 if (INTF_bit == 1) {

 INTF_bit = 0;


 if (EXT_INT0_Callback != 0) {
 EXT_INT0_Callback();
 }
 }
}
