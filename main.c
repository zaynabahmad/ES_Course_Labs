
unsigned int v_counter = 0;

void main() {
    TRISB0_bit = 0;
    PORTB.F0 = 0;

    OPTION_REG = 0x87;

    TMR0 = 0;

    while(1) {

        if (INTCON.T0IF) {
            v_counter++;
            INTCON.T0IF = 0;
            TMR0 = 0;
        }


        if (v_counter >= 31) {
            PORTB.F0 = ~PORTB.F0;
            v_counter = 0;
        }
    }
}