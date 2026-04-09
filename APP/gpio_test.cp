#line 1 "E:/embedded/Drivers_Project/APP/gpio_test.c"
#line 1 "e:/embedded/drivers_project/app/gpio_test.h"



void GPIO_Test(void);
#line 1 "e:/embedded/drivers_project/app/../mcal/gpio/gpio_interface.h"
#line 27 "e:/embedded/drivers_project/app/../mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(unsigned char port, unsigned char pin, unsigned char direction);
void GPIO_WritePin(unsigned char port, unsigned char pin, unsigned char value);
unsigned char GPIO_ReadPin(unsigned char port, unsigned char pin);
void GPIO_TogglePin(unsigned char port, unsigned char pin);
#line 4 "E:/embedded/Drivers_Project/APP/gpio_test.c"
void GPIO_Test(void)
{
 GPIO_SetPinDirection( 1 ,  0 ,  0 );

 while(1)
 {
 GPIO_WritePin( 1 ,  0 ,  1 );
 Delay_ms(500);

 GPIO_WritePin( 1 ,  0 ,  0 );
 Delay_ms(500);
 }
}
