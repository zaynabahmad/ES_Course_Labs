#line 1 "D:/Materials/Y4Spring/Embedded/Labs/Lab2Task1/MCAL/GPIO/gpio_impelemntation.c"
#line 1 "d:/materials/y4spring/embedded/labs/lab2task1/mcal/gpio/gpio_interface.h"
#line 1 "d:/materials/y4spring/embedded/labs/lab2task1/mcal/gpio/gpio_private.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdbool.h"



 typedef char _Bool;
#line 7 "d:/materials/y4spring/embedded/labs/lab2task1/mcal/gpio/gpio_interface.h"
void GPIO_Init(void);

void setpindirection(unsigned char port, unsigned char pin,  _Bool  direction);

void setpinvalue(unsigned char port, unsigned char pin,  _Bool  value);

unsigned char getpinvalue(unsigned char port, unsigned char pin);
#line 3 "D:/Materials/Y4Spring/Embedded/Labs/Lab2Task1/MCAL/GPIO/gpio_impelemntation.c"
volatile unsigned char* GPIO_GetTRISRegister(unsigned char port)
{
 switch(port)
 {
 case  1 : return &TRISA;
 case  2 : return &TRISB;
 case  3 : return &TRISC;
 case  4 : return &TRISD;
 case  5 : return &TRISE;
 default: return 0;
 }
}

volatile unsigned char* GPIO_GetPORTRegister(unsigned char port)
{
 switch(port)
 {
 case  1 : return &PORTA;
 case  2 : return &PORTB;
 case  3 : return &PORTC;
 case  4 : return &PORTD;
 case  5 : return &PORTE;
 default: return 0;
 }
}



void GPIO_Init(void)
{
 TRISA = 0xFF;
 TRISB = 0xFF;
 TRISC = 0xFF;
 TRISD = 0xFF;
 TRISE = 0xFF;

 PORTA = 0x00;
 PORTB = 0x00;
 PORTC = 0x00;
 PORTD = 0x00;
 PORTE = 0x00;

 ADCON1 = 0x06;
}

void setpindirection(unsigned char port, unsigned char pin,  _Bool  direction)
{
 volatile unsigned char* TRIS_reg = GPIO_GetTRISRegister(port);
 if(TRIS_reg == 0) return;

 if(direction ==  0 )
 *TRIS_reg &= ~(1 << pin);
 else
 *TRIS_reg |= (1 << pin);
}

void setpinvalue(unsigned char port, unsigned char pin,  _Bool  value)
{
 volatile unsigned char* PORT_reg = GPIO_GetPORTRegister(port);
 if(PORT_reg == 0) return;

 if(value ==  1 )
 *PORT_reg |= (1 << pin);
 else
 *PORT_reg &= ~(1 << pin);
}

unsigned char getpinvalue(unsigned char port, unsigned char pin)
{
 volatile unsigned char* PORT_reg = GPIO_GetPORTRegister(port);
 if(PORT_reg == 0) return 0;

 return ((*PORT_reg >> pin) & 0x01);
}
