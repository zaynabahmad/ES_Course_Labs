#line 1 "C:/Users/Z B O O K/Downloads/Week2/ES_Course_Labs-main/MCAL/GIE/GIE_program.c"
#line 1 "c:/users/z b o o k/downloads/week2/es_course_labs-main/mcal/gie/gie_interface.h"



void GIE_voidEnable(void);
void GIE_voidDisable(void);
#line 5 "C:/Users/Z B O O K/Downloads/Week2/ES_Course_Labs-main/MCAL/GIE/GIE_program.c"
void GIE_voidEnable(void) {
  *((volatile unsigned char*)0x0B)  |= (1 << 7);
}

void GIE_voidDisable(void) {
  *((volatile unsigned char*)0x0B)  &= ~(1 << 7);
}
