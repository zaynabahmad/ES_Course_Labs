#line 1 "D:/Education/LAB1/MCAL/GPIO/GPIO.c"
#line 1 "d:/education/lab1/mcal/gpio/gpio_interface.h"









void GPIO_SetPinDirection(char port, char pin, char direction);
void GPIO_WritePin(char port, char pin, char value);
char GPIO_ReadPin(char port, char pin);
#line 3 "D:/Education/LAB1/MCAL/GPIO/GPIO.c"
void GPIO_SetPinDirection(char port, char pin, char direction)
{
 if(port == 'A')
 {
 if(direction ==  1 )
 TRISA |= (1 << pin);
 else
 TRISA &= ~(1 << pin);
 }

 else if(port == 'B')
 {
 if(direction ==  1 )
 TRISB |= (1 << pin);
 else
 TRISB &= ~(1 << pin);
 }
}

void GPIO_WritePin(char port, char pin, char value)
{
 if(port == 'B')
 {
 if(value ==  1 )
 PORTB |= (1 << pin);
 else
 PORTB &= ~(1 << pin);
 }
}

char GPIO_ReadPin(char port, char pin)
{
 if(port == 'A')
 return (PORTA >> pin) & 1;

 return 0;
}
