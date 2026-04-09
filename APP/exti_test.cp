#line 1 "E:/embedded/Drivers_Project/APP/exti_test.c"
#line 1 "e:/embedded/drivers_project/app/exti_test.h"



void EXTI_Test(void);
#line 1 "e:/embedded/drivers_project/app/../mcal/gpio/gpio_interface.h"
#line 27 "e:/embedded/drivers_project/app/../mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(unsigned char port, unsigned char pin, unsigned char direction);
void GPIO_WritePin(unsigned char port, unsigned char pin, unsigned char value);
unsigned char GPIO_ReadPin(unsigned char port, unsigned char pin);
void GPIO_TogglePin(unsigned char port, unsigned char pin);
#line 1 "e:/embedded/drivers_project/app/../mcal/exti/exti_interface.h"






void EXTI_Init(unsigned char edge);
void EXTI_Enable(void);
void EXTI_Disable(void);
#line 5 "E:/embedded/Drivers_Project/APP/exti_test.c"
void EXTI_Test(void)
{
 GPIO_SetPinDirection( 1 ,  0 ,  0 );
 GPIO_SetPinDirection( 1 ,  0 ,  1 );

 EXTI_Init( 1 );
 EXTI_Enable();

 while(1)
 {

 }
}
