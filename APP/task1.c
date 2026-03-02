
#define SET_BIT(REG,BIT)      ( (REG) |=  (1U << (BIT)) )
#define CLR_BIT(REG,BIT)      ( (REG) &= ~(1U << (BIT)) )
#define TOG_BIT(REG,BIT)      ( (REG) ^=  (1U << (BIT)) )
#define GET_BIT(REG,BIT)      ( ((REG) >> (BIT)) & 1U )


void shortDelay(void) {
     unsigned int i;
     for (i = 0; i < 5000; i++);
}

void longDelay(void) {
     unsigned int i;
     for (i = 0; i < 10000; i++);
}

void main() {
    TRISB = 0x03;   // RB0, RB1 = inputs (switches)
    TRISC = 0x00;   // All RC = outputs (LEDs)
    PORTC = 0x00;   // LEDs off initially

    while (1) {
       if (!GET_BIT(PORTB, 0) && !GET_BIT(PORTB, 1)) {// Switch 1 and 2 pressed
            PORTC = 0x03;                 // LEDs ON (RC1, RC2)
        }
        else if (!GET_BIT(PORTB, 0)) {          // Switch 1 pressed
            PORTC = 0x03;                 // LEDs ON (RC1, RC2)
            shortDelay();
            PORTC = 0x00;                 // LEDs OFF
            shortDelay();
        }
        else if (!GET_BIT(PORTB, 1)) {     // Switch 2 pressed
            PORTC = 0x03;                 // LEDs ON
            longDelay();
            PORTC = 0x00;                 // LEDs OFF
            longDelay();
        }
        else {
            PORTC = 0x00;                 // No switch ? LEDs off
        }
    }
}