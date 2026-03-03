#line 1 "C:/Users/Youssef Zaher/Downloads/LAB 1/HAL/BUTTON.c"
#line 1 "c:/users/youssef zaher/downloads/lab 1/hal/button.h"





void Button_Init(unsigned short *tris, unsigned short pin);
unsigned short Button_Read(unsigned short *port, unsigned short pin);
#line 3 "C:/Users/Youssef Zaher/Downloads/LAB 1/HAL/BUTTON.c"
void Button_Init(unsigned short *tris, unsigned short pin)
{
 GPIO_SetPinDirection(tris, pin, INPUT);
}

unsigned short Button_Read(unsigned short *port, unsigned short pin)
{
 return GPIO_ReadPin(port, pin);
}
