void LED_Init() {
    TRISD.F0 = 0;
}
void LED_Toggle() {
    PORTD.F0 = ~PORTD.F0;
}