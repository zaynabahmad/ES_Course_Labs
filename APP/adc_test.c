 #include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"

void ADC_Test_voidInit(void) {
    GPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT); // LM35
    GPIO_voidSetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_OUTPUT); // Alarm LED
    ADC_voidInit();
}

void ADC_Test_voidRun(void) {
    u16 Local_u16Result = ADC_u16ReadChannel(ADC_CHANNEL0);
    u16 Local_u16Temp = (u16)((u32)Local_u16Result * 500 / 1024);

    if (Local_u16Temp > 35) {
        GPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN0, GPIO_HIGH);
    } else {
        GPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN0, GPIO_LOW);
    }
}