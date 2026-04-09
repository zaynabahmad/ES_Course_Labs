#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void ADC_Test(void) {
    u16 adc_value = 0;
    ADC_voidInit();
    adc_value = ADC_u16ReadChannel(0);
    (void)adc_value; 
}