void main() {
    // 1. Configure Pin Directions
    TRISB = 0x03;    // Set RB0 and RB1 as Inputs (0000 0011), others as Outputs
    TRISD = 0x00;    // Set all of PORTD (where LEDs are) as Outputs

    // 2. Initialize Pins
    PORTD = 0x00;    // Ensure all LEDs are OFF at the start

    while(1) {
        // --- Logic for Switch 1 (RB0) ---
        if (PORTB.F0 == 1) {
            PORTD = 0x03;     // Turn ON RD0 and RD1 (0000 0011)
            Delay_ms(200);    // Wait 0.2 seconds
            PORTD = 0x00;     // Turn OFF LEDs
            Delay_ms(200);    // Wait 0.2 seconds
        }

        // --- Logic for Switch 2 (RB1) ---
        else if (PORTB.F1 == 1) {
            PORTD = 0x03;     // Turn ON RD0 and RD1
            Delay_ms(500);    // Wait 0.5 seconds
            PORTD = 0x00;     // Turn OFF LEDs
            Delay_ms(500);    // Wait 0.5 seconds
        }

        // --- Logic for No Switch Pressed ---
        else {
            PORTD = 0x00;     // Keep LEDs OFF
        }
    }
}