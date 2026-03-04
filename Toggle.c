
void EXTI_INT0_Init();
void LED_Init();
void LED_Toggle();

void interrupt() {
    if (INTCON.INTF == 1) {
        LED_Toggle();
        INTCON.INTF = 0;
    }
}

void main() {
    EXTI_INT0_Init();
    LED_Init();
    while(1);
}