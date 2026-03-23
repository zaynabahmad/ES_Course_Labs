// Variable declarations
unsigned int adc_res;
float temp;
char txt[15];

void main() {
    // 1. ADC Configuration
    // ADCON1: Bit 7 = 1 (Right justified result)
    // Bits 3-0 = 0000 (Configures all RA pins as Analog)
    ADCON1 = 0x80;
    TRISA0_bit = 1;            // Set RA0 as input for LM35

    // 2. UART Configuration
    // Initialize UART at 9600 baud rate
    UART1_Init(9600);
    Delay_ms(100);             // Wait for UART module to stabilize

    UART1_Write_Text("--- Temperature Monitor ---");
    UART1_Write(13);           // Carriage Return (Enter)
    UART1_Write(10);           // Line Feed (New Line)

    while(1) {
        // 3. Read Analog Value from AN0 (0 to 1023)
        adc_res = ADC_Read(0);

        // 4. Calculate Temperature in Celsius
        // Formula: (ADC_Value * 500) / 1024
        // Based on LM35 (10mV/C) and Vref = 5V
        temp = (adc_res * 500.0) / 1024.0;

        // 5. Convert numeric float to a string for transmission
        FloatToStr(temp, txt);

        // 6. Send data to Proteus Virtual Terminal
        UART1_Write_Text("Temp: ");
        UART1_Write_Text(txt);
        UART1_Write_Text(" C");

        // Send New Line characters
        UART1_Write(13);
        UART1_Write(10);

        Delay_ms(1000);        // Wait 1 second before next reading
    }
}