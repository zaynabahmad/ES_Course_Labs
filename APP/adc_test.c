#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"


void ADC_Test(void) {
    u16 adc_value = 0;
    float temperature = 0.0;

    /* 1. Initialize the ADC module */
    ADC_voidInit();

    /* 2. Read from Channel 0 (AN0) where LM35 is connected */
    adc_value = ADC_u16ReadChannel(0);

    /* 3. Convert digital value to Temperature */
    temperature = adc_value * 0.488;


}