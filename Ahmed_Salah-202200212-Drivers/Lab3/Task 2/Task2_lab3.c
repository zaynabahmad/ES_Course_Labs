// Speed levels based on 20MHz clock and PR2 = 249
unsigned char speeds[] = {62, 125, 187, 249}; // 25%, 50%, 75%, 100%
int current_step = 0;

void interrupt() {
    if (INTF_bit) {
        Delay_ms(40); // Debounce
        if (PORTB.F0 == 0) {
            current_step++;
            if (current_step > 3) current_step = 0;
            CCPR1L = speeds[current_step]; // Update Duty Cycle
        }
        INTF_bit = 0;
    }
}

void main() {
    // Port Setup
    TRISB0_bit = 1;      // Button Input
    TRISC = 0x00;        // Outputs
    PORTC = 0x00;

    // Set Motor Direction (RC0 & RC1)
    PORTC.F0 = 1;
    PORTC.F1 = 0;

    // PWM Setup (Section 8.3.3)
    PR2 = 249;           // Frequency ~5kHz
    CCPR1L = speeds[0];  // Initial 25%
    T2CON = 0x05;        // Timer2 ON + Prescaler 4
    CCP1CON = 0x0C;      // PWM Mode ON

    // Interrupt Setup
    OPTION_REG.INTEDG = 0; // Falling Edge
    INTF_bit = 0;
    INTE_bit = 1;
    GIE_bit = 1;

    while(1); // Stay here
}