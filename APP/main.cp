#line 1 "D:/Uni/Y4 S2/Embedded Systems/Final/APP/main.c"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/gpio/gpio_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"



typedef unsigned char u8;
typedef unsigned int u16;
#line 12 "d:/uni/y4 s2/embedded systems/final/mcal/gpio/gpio_interface.h"
unsigned char GPIO_voidSetPinDirection(unsigned char port,
 unsigned char pin,
 unsigned char dir);

unsigned char GPIO_voidSetPinValue(unsigned char port,
 unsigned char pin,
 unsigned char val);


unsigned char GPIO_u8GetPinValue(unsigned char port,
 unsigned char pin);

unsigned char GPIO_voidTogglePin(unsigned char port,
 unsigned char pin);

unsigned char GPIO_voidSetPortDirection(unsigned char port,
 unsigned char dir_mask);

unsigned char GPIO_voidSetPortValue(unsigned char port,
 unsigned char value);
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/timer0/timer0_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"
#line 12 "d:/uni/y4 s2/embedded systems/final/mcal/timer0/timer0_interface.h"
void TIMER0_voidInit(void);

void TIMER0_voidDelayMs(unsigned char ms);

void TIMER0_voidSetPreload(unsigned char preload);

void TIMER0_voidEnableInterrupt(void);

void TIMER0_voidDisableInterrupt(void);

void TIMER0_voidClearFlag(void);

unsigned char TIMER0_u8GetFlag(void);
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/adc/adc_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"
#line 8 "d:/uni/y4 s2/embedded systems/final/mcal/adc/adc_interface.h"
void ADC_voidInit(void);

unsigned int ADC_u16Read(unsigned char channel);

float ADC_f32ToVoltage(unsigned int raw_value);
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/uart/uart_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"
#line 14 "d:/uni/y4 s2/embedded systems/final/mcal/uart/uart_interface.h"
void UART_voidInit(void);

void UART_voidSendChar(unsigned char data);

void UART_voidSendString(const unsigned char *str);

void UART_voidSendNumber(unsigned int number);

unsigned char UART_u8ReceiveChar(unsigned char *received);

unsigned char UART_u8ReceiveCharTimeout(unsigned char *received);

void UART_voidClearErrors(void);
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/i2c/i2c_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"
#line 18 "d:/uni/y4 s2/embedded systems/final/mcal/i2c/i2c_interface.h"
void I2C_voidInit(void);

void I2C_voidStart(void);

void I2C_voidRepeatedStart(void);

void I2C_voidStop(void);

unsigned char I2C_u8Write(unsigned char data);

unsigned char I2C_u8Read(unsigned char send_ack);

void I2C_voidWaitIdle(void);
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/pwm/pwm_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"
#line 15 "d:/uni/y4 s2/embedded systems/final/mcal/pwm/pwm_interface.h"
void PWM_voidInit(void);

unsigned char PWM_voidSetDuty(unsigned char duty_percent);

void PWM_voidSetDutyRaw(unsigned char raw);

void PWM_voidStop(void);
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/exti/exti_interface.h"



void EXTI_voidEnable(void);
#line 9 "D:/Uni/Y4 S2/Embedded Systems/Final/APP/main.c"
void GPIO_Test(void);
void TIMER_Test(void);
void ADC_Test(void);
void UART_Test(void);
void I2C_Test(void);
void PWM_Test(void);
void EXTI_Test(void);

void main(void)
{
 GPIO_Test();
 TIMER_Test();
 ADC_Test();
 UART_Test();
 I2C_Test();
 PWM_Test();
 EXTI_Test();
}
