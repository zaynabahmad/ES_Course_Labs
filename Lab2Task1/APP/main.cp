#line 1 "D:/Materials/Y4Spring/Embedded/Labs/Lab2Task1/APP/main.c"
#line 1 "d:/materials/y4spring/embedded/labs/lab2task1/app/../mcal/gpio/gpio_interface.h"
#line 1 "d:/materials/y4spring/embedded/labs/lab2task1/app/../mcal/gpio/gpio_private.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdbool.h"



 typedef char _Bool;
#line 7 "d:/materials/y4spring/embedded/labs/lab2task1/app/../mcal/gpio/gpio_interface.h"
void GPIO_Init(void);

void setpindirection(unsigned char port, unsigned char pin,  _Bool  direction);

void setpinvalue(unsigned char port, unsigned char pin,  _Bool  value);

unsigned char getpinvalue(unsigned char port, unsigned char pin);
#line 1 "d:/materials/y4spring/embedded/labs/lab2task1/app/../hal/led/led_interface.h"
#line 1 "d:/materials/y4spring/embedded/labs/lab2task1/app/../hal/led/../../mcal/gpio/gpio_interface.h"
#line 6 "d:/materials/y4spring/embedded/labs/lab2task1/app/../hal/led/led_interface.h"
void LED_Init(unsigned char port1, unsigned char pin1,
 unsigned char port2, unsigned char pin2);

void LED_On(unsigned char port, unsigned char pin);

void LED_Off(unsigned char port, unsigned char pin);
#line 5 "D:/Materials/Y4Spring/Embedded/Labs/Lab2Task1/APP/main.c"
void delay_ms(int ms)
{
 volatile int i, j;
 for(i = 0; i < ms; i++)
 for(j = 0; j < 1000; j++);
}
#line 24 "D:/Materials/Y4Spring/Embedded/Labs/Lab2Task1/APP/main.c"
int main()
{

 ADCON1 = 0x06;


 GPIO_Init();
 LED_Init( 1 ,  0 ,  1 ,  1 );


 setpindirection( 1 ,  2 ,  1 );
 setpindirection( 1 ,  3 ,  1 );

 while(1)
 {

 if(getpinvalue( 1 ,  2 ) == 0)
 {

 LED_On( 1 ,  0 );
 LED_Off( 1 ,  1 );
 delay_ms(200);

 LED_Off( 1 ,  0 );
 LED_On( 1 ,  1 );
 delay_ms(200);
 }

 else if(getpinvalue( 1 ,  3 ) == 0)
 {

 LED_On( 1 ,  0 );
 LED_Off( 1 ,  1 );
 delay_ms(500);

 LED_Off( 1 ,  0 );
 LED_On( 1 ,  1 );
 delay_ms(500);
 }
 else
 {

 LED_Off( 1 ,  0 );
 LED_Off( 1 ,  1 );
 }
 }

 return 0;
}
