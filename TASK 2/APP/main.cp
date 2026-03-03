#line 1 "D:/Education/LAB1/APP/main.c"
#line 1 "d:/education/lab1/app/../hal/led/led_interface.h"



void LED_Init(char port, char pin);
void LED_On(char port, char pin);
void LED_Off(char port, char pin);
#line 1 "d:/education/lab1/app/../hal/switch/switch_interface.h"



void SWITCH_Init(char port, char pin);
char SWITCH_Read(char port, char pin);
#line 1 "d:/education/lab1/app/../mcal/gpio/gpio_interface.h"









void GPIO_SetPinDirection(char port, char pin, char direction);
void GPIO_WritePin(char port, char pin, char value);
char GPIO_ReadPin(char port, char pin);
#line 5 "D:/Education/LAB1/APP/main.c"
void main()
{
 ADCON1 = 0x07;

 TRISA = 0xFF;
 TRISB = 0x00;

 PORTA = 0x00;
 PORTB = 0x00;

 while(1)
 {
 if((PORTA.F0) == 1)
 {
 PORTB.F0 = 1;
 PORTB.F1 = 1;
 Delay_ms(200);

 PORTB.F0 = 0;
 PORTB.F1 = 0;
 Delay_ms(200);
 }

 else if((PORTA.F1) == 1)
 {
 PORTB.F0 = 1;
 PORTB.F1 = 1;
 Delay_ms(500);

 PORTB.F0 = 0;
 PORTB.F1 = 0;
 Delay_ms(500);
 }

 else
 {
 PORTB.F0 = 0;
 PORTB.F1 = 0;
 }
 }
}
