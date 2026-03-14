#include "../HAL/LED/LED_interface.h"
#include "../HAL/Timer/Timer_Interface.h"
#include "../MCAL/Interrupt Manager/Interrupt_manager.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"
#include "../MCAL/ADC_interface.h"

// Flags
volatile u8 press_count = 0;
volatile u8 is_locked = 0;
volatile u8 SW_Toggle_Flag = 0;
volatile u8 Timer_Toggle_Flag = 0;

// Data
u16 ADC_Result = 0;
u16 Temperature = 0; // Changed to u16 to avoid "float" memory overhead

/* --- LIGHTWEIGHT UART FUNCTIONS --- */
// This replaces the heavy UART Library
/* --- ULTRA-LIGHTWEIGHT UART (Fixed Syntax) --- */
void Manual_UART_Init() {
    TRISC6_bit = 0; // TX Output
    TRISC7_bit = 1; // RX Input
    SPBRG = 51;     // 9600 Baud @ 8MHz
    TXSTA = 0x24;
    RCSTA = 0x90;
}

void Manual_UART_Write(char data_to_send) { // Renamed from 'data' to avoid conflict
    while(!TXIF_bit);
    TXREG = data_to_send;
}

void Manual_UART_Print(char *p_text) { // Simplified pointer
    while(*p_text) {
        Manual_UART_Write(*p_text);
        p_text++;
    }
}

/* --- Callbacks --- */
void Timer_Callback(void) {
    if (!is_locked) Timer_Toggle_Flag = 1;
}

void SW1_Callback(void) {
    if (!is_locked) {
        SW_Toggle_Flag = 1;
        press_count++;
        if (press_count >= 5) is_locked = 1;
    }
}

void main() {
    GPIO_Init();
    ADC_Init();
    EXT_INT_Init();
    Manual_UART_Init(); // Use our small function instead of UART1_Init

    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB, GPIO_PIN2);
    LED_Init(GPIO_PORTB, GPIO_PIN3);

    Timer0_Init(128);
    Timer0_SetDelay(2500, Timer_Callback);
    EXT_INT_SetEdge(falling_edge);
    EXT_INT_SetCallback(SW1_Callback);
    EXT_INT_Enable();
    SET_BIT(INTCON, GIE_BIT);

    while (1) {
        ADC_Result = ADC_Read(ADC_CHANNEL0);
        // Using integer math to save space: (ADC * 500) / 1024
        Temperature = (u16)((u32)ADC_Result * 500 / 1024);

        /* --- PRINTING WITHOUT LIBRARIES --- */
        Manual_UART_Print("Temp: ");
        Manual_UART_Write((Temperature / 10) + '0'); // Tens
        Manual_UART_Write((Temperature % 10) + '0'); // Units
        Manual_UART_Print(" C\r\n");

        if (Temperature > 35) {
            LED_On(GPIO_PORTB, GPIO_PIN3);
        } else {
            LED_Off(GPIO_PORTB, GPIO_PIN3);
        }

        if (Timer_Toggle_Flag == 1) {
            LED_Toggle(GPIO_PORTB, GPIO_PIN1);
            Timer_Toggle_Flag = 0;
        }

        if (SW_Toggle_Flag == 1) {
            LED_Toggle(GPIO_PORTB, GPIO_PIN2);
            SW_Toggle_Flag = 0;
        }

        if (is_locked) {
            LED_Off(GPIO_PORTB, GPIO_PIN1);
            LED_On(GPIO_PORTB, GPIO_PIN2);
            CLR_BIT(INTCON, TMR0IE_BIT);
        }

        Delay_ms(500);
    }
}