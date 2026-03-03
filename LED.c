 void LED_Init() {
    TRISD.F0 = 0; // Let's assume LED is on RD0 (based on your snippet)
    PORTD.F0 = 0;
}

void LED_Toggle() {
    PORTD.F0 = ~PORTD.F0;
}