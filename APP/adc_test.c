#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/UART/UART_interface.h"


volatile u8 Local_u8Delay;
     
/* Helper to convert integer to string (Saves RAM) */
void vidIntToString(u32 Copy_u32Number, u8* Add_u8String) {
    u8 Local_u8Index = 0;
    u8 Local_u8TempIndex = 0;
    u8 Local_chTemp[11];

    if (Copy_u32Number == 0) {
        Add_u8String[0] = '0';
        Add_u8String[1] = '\0';
        return;
    }

    while (Copy_u32Number > 0) {
        Local_chTemp[Local_u8TempIndex++] = (u8)((Copy_u32Number % 10) + '0');
        Copy_u32Number /= 10;
    }

    while (Local_u8TempIndex > 0) {
        Add_u8String[Local_u8Index++] = Local_chTemp[--Local_u8TempIndex];
    }
    Add_u8String[Local_u8Index] = '\0';
}

/* Helper specifically for sending RAM buffers */
void vidSendRamString(u8* Copy_u8RamString) {
    u8 i = 0;
    while(Copy_u8RamString[i] != '\0') {
        UART_SendByte(Copy_u8RamString[i]);
        i++;
    }
}

void APP_vidAdcTest(void) {
    /* Declare ALL variables at the very top */
    u16 Local_u16AdcReading;
    u32 Local_u32TempScaled;
    u8 Local_u8Buffer[10];
    u16 i; /* <-- Declared the loop counter here! */

    /* 1. Initialize Peripherals */
    ADC_Init();
    UART_Init(9600);

    /* This uses the ROM string sender (from UART.c) */
    UART_SendString("--- Temperature Monitor ---\r\n");

    while(1) {
        Local_u16AdcReading = ADC_GetChannelValue(ADC_CHANNEL0);

        /* Calculate Temperature: (ADC * 5000) / 1024 for 1 decimal point */
        /* Add UL to force true 32-bit arithmetic */
Local_u32TempScaled = ((u32)Local_u16AdcReading * 5000UL) / 1024UL;

        UART_SendString("Temp = ");

        /* Send Integer part using the new RAM sender */
        vidIntToString(Local_u32TempScaled / 10, Local_u8Buffer);
        vidSendRamString(Local_u8Buffer);

        UART_SendString(".");

        /* Send Decimal part using the new RAM sender */
        vidIntToString(Local_u32TempScaled % 10, Local_u8Buffer);
        vidSendRamString(Local_u8Buffer);

        UART_SendString(" C\r\n");



    /* At 8MHz, one instruction is 0.5us.
     * A loop takes a few instructions, so counting to 30 is more than enough
     * to give the ADC capacitor time to charge.
     */
    for (Local_u8Delay = 0; Local_u8Delay < 30; Local_u8Delay++) {
        /* Do nothing, just waste time */
    }


    }
}