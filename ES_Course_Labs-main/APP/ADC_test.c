#include "ADC_test_interface.h"
void ADC_test(){
unsigned int adc_value;
float temp;

GPIO_SetPinDirection(GPIO_PORTA,0,1);
UART_TX_init();
GPIO_SetPinDirection(GPIO_PORTC,7,1);
GPIO_SetPinDirection(GPIO_PORTC,6,0);
Delay_ms(100);
while(1){

adc_value=ADConversion();
temp=adc_value*0.488;
UART_Write(temp);
Delay_ms(1000);


}










}