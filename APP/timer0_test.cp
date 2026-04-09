#line 1 "E:/embedded/Drivers_Project/APP/timer0_test.c"
#line 1 "e:/embedded/drivers_project/app/timer_test.h"



void TIMER_Test(void);
#line 1 "e:/embedded/drivers_project/app/../mcal/gpio/gpio_interface.h"
#line 27 "e:/embedded/drivers_project/app/../mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(unsigned char port, unsigned char pin, unsigned char direction);
void GPIO_WritePin(unsigned char port, unsigned char pin, unsigned char value);
unsigned char GPIO_ReadPin(unsigned char port, unsigned char pin);
void GPIO_TogglePin(unsigned char port, unsigned char pin);
#line 1 "e:/embedded/drivers_project/app/../mcal/timer0/timer0_interface.h"



void TIMER0_Init(void);
void TIMER0_Start(void);
void TIMER0_Stop(void);
#line 1 "e:/embedded/drivers_project/app/timer_test.h"
#line 7 "E:/embedded/Drivers_Project/APP/timer0_test.c"
void TIMER_Test(void)
{
 GPIO_SetPinDirection( 1 ,  0 ,  0 );

 TIMER0_Init();
 TIMER0_Start();

 while(1)
 {

 }
}
