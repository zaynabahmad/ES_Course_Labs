#include "../HAL/PWM Control/PWM.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/Timer/Timer_Interface.h"
#include "../HAL/Switch/Switch_interface.h"
#include "../MCAL/Interrupt Manager/Interrupt_manager.h"
#include "../HAL/LM35/LM35.h"
volatile u8 flag=0;
void ADC_ConversionComplete_ISR() {
    // This function will be called when ADC conversion completes
    // You can read the ADC result here if needed, or just set a flag
    // For example:
    // g_ADCResult = ADC_u16GetConversionResult(); // Store result in a global variable
    // g_ADCConversionCompleteFlag = 1; // Set a flag to indicate new data is ready
    flag=1;
}

void ADC_Test(void) {
    //LM35 connected to A0 and temperature displayed on virtual terminal via UART
    LM35_init(GPIO_PORTA, GPIO_PIN0);
    LED_Init(GPIO_PORTC, GPIO_PIN2);
    LED_Init(GPIO_PORTC, GPIO_PIN3);

    ADC_SetConversionComplete_SetCallback(ADC_ConversionComplete_ISR); // Register the ADC conversion complete callback
    while(1) {
        u16 temp = LM35_u16GetTemp();

        delay_ms(1000);
        // Here you would send 'temp' to your UART transmit function to display it
        // i WANT ANYWAY TO SEE THE VALUE WHEN RUNNING ON PROTEUS, SO I WILL JUST TOGGLE AN LED BASED ON TEMPERATURE THRESHOLD
        if(temp > 37) {
            LED_On(GPIO_PORTC, GPIO_PIN2); // Turn on LED if temp > 30°C
        } else {
            LED_Off(GPIO_PORTC, GPIO_PIN2); // Turn off LED if temp <= 30°C
        }
        if (flag){
           LED_Toggle(GPIO_PORTC, GPIO_PIN3); // Toggle LED to indicate conversion complete (for testing)
            flag=0;
        }
    }
}