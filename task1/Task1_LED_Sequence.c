void main() {
    TRISB = 0xFF;
    TRISD = 0x00;
    PORTD = 0x00;

    while(1) {
        if(PORTB.F0 == 1) {          // If Switch 1 (RB0) is pressed

            PORTD = 0x03;            // Turn ON RD0 and RD1
            Delay_ms(200);
            PORTD = 0x00;            // Turn OFF RD0 and RD1
            Delay_ms(200);
        }
        else if(PORTB.F1 == 1) {     // If Switch 2 (RB1) is pressed

            PORTD = 0x03;
            Delay_ms(500);
            PORTD = 0x00;
            Delay_ms(500);
        }
        else {                       // If NO switch is pressed
            PORTD = 0x00;            // Keep LEDs OFF
        }
    }
}