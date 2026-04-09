#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../GPIO/GPIO_interface.h"
#include "ADC_private.h"
#include "ADC_interface.h"

void ADC_Init(void)
{
    // Configure ADC pins as input (example AN0)
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT);

    // Right justified + configure analog pins
      ADCON1_REG = 0x8E;

    // Select channel 0 + enable ADC
     ADCON0_REG = 0x41;

    // ADC clock (Fosc/32 for 4MHz)
    SET_BIT(ADCON0_REG, 6);
    CLR_BIT(ADCON0_REG, 7);
}

u16 ADC_Read(u8 channel)
{
    // Select channel
     ADCON0_REG &= ~(0x38);
     ADCON0_REG |= (channel << 3);

    // Acquisition delay
    Delay_us(20);

    // Start conversion
    SET_BIT(ADCON0_REG, GO_DONE_BIT);

    // Wait until done
    while(GET_BIT(ADCON0_REG, GO_DONE_BIT));

    // Return result
    return ((ADRESH_REG << 8) | ADRESL_REG);
}