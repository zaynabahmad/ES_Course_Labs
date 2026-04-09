#include "../../MCAL/ADC/ADC_interface.h"
#include "../../MCAL/Interrupt Manager/Interrupt_manager.h" 
#include "LM35.h"

#define LM35_CHANNEL    0
#define V_REF           5000  // 5000mV (5V)
void LM35_Init(u8 port, u8 pin) {
    ADC_voidInit(); // Initialize ADC with default settings
    GPIO_SetPinDirection(port, pin, GPIO_INPUT); // Set pin as input
}
u16 LM35_u16GetTemp(void) {
    u16 local_u16ADCResult;
    u32 local_u32Voltage_mV;
    u8  local_u8Temp;

    /* 1. Get raw digital value from MCAL */
    local_u16ADCResult = ADC_u16Read(LM35_CHANNEL);

    /* 2. Convert to millivolts (using u32 to prevent overflow during math) */
    local_u32Voltage_mV = (u32)local_u16ADCResult * V_REF / 1024;

    /* 3. LM35 Scale: 10mV = 1 degree Celsius */
    local_u8Temp = (u16)(local_u32Voltage_mV / 10);

    return local_u8Temp;
}