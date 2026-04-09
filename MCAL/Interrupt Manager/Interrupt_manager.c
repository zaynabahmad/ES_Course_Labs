#include "Interrupt_manager.h"

/* Global function pointers for callbacks */
static void (*TMR_INT_Callback)(void) = 0;
static void (*EXT_INT_Callback)(void) = 0;
static void (*ADC_ConversionComplete_Callback)(void) = 0; // New callback for ADC
static void (*UART_Callback)(void) = 0; // Callback for UART data reception
static void (*I2C_Callback)(void) = 0; // Callback for I2C
static void (*SPI_Callback)(void) = 0; // New callback for SPI
/* Timer0 counting variables */
volatile u16 TMR0_Counter = 0;
volatile u16 target_overflows = 0;

//Store ADC result in a global variable for retrieval in main loop
volatile u16 ADC_Result = 0; // New global variable to store ADC result

void TMR_INT_SetCallback(void (*ptr)(void)) {
    if (ptr) TMR_INT_Callback = ptr;
}

void EXT_INT_SetCallback(void (*ptr)(void)) {
    if (ptr) EXT_INT_Callback = ptr;
}

void ADC_SetConversionComplete_SetCallback(void (*ptr)(void)) {
    if (ptr) ADC_ConversionComplete_Callback = ptr;
}

void I2C_SetCallback(void (*ptr)(void)) {
    if (ptr) I2C_Callback = ptr;
}

void interrupt() {
    // Check if Timer0 overflow interrupt occurred and is enabled
    if (GET_BIT(INTCON, TMR0IF_BIT) && GET_BIT(INTCON, TMR0IE_BIT)) {
        TMR0 = 0;           //Reset Timer0 count to 0 for next cycle
        TMR0_Counter++;     // increment overflow counter

        // Call callback when target overflows reached
        if (TMR0_Counter >= target_overflows) {
            TMR0_Counter = 0;       // reset counter
            if (TMR_INT_Callback) {
                TMR_INT_Callback(); // fire Timer0 callback
            }
        }
        
        CLR_BIT(INTCON, TMR0IF_BIT); // clear Timer0 interrupt flag
    }

    // Check if External interrupt occurred and is enabled
    if (GET_BIT(INTCON, INTF_BIT) && GET_BIT(INTCON, INTE_BIT)) {

        if (EXT_INT_Callback) {
            EXT_INT_Callback();      // fire External interrupt callback
        }

        CLR_BIT(INTCON, INTF_BIT);   // clear INT0 interrupt flag
    }
    if (GET_BIT(PIR1, ADIF_BIT) && GET_BIT(PIE1, ADIE_BIT)) { // Check if ADC interrupt flag is set
        if (ADC_ConversionComplete_Callback) {
            ADC_Result = ADC_u16GetConversionResult(); // Store the ADC result
            ADC_ConversionComplete_Callback(); // Call the registered callback
        }
        CLR_BIT(PIR1, ADIF_BIT); // Clear ADC interrupt flag
    }

    if(GET_BIT(PIR1 , RCIF))
    {

        if(UART_Callback != 0)
        {
            UART_Callback();   // Call user function
        }

    }

    if(GET_BIT(PIR1, SSPIF) && GET_BIT(PIE1, SSPIE)) { // Check if SPI interrupt flag is set
        if (SPI_Callback) {
            SPI_Callback(); // Call the registered callback
        }
        else if (I2C_Callback) {
            I2C_Callback(); // Call the registered I2C callback
        }
        else {
            // No callback registered, just clear the flag
        }
    CLR_BIT(PIR1, SSPIF); // Clear SPI interrupt flag
    }
}

