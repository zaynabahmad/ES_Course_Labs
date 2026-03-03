#line 1 "C:/Users/Amr/OneDrive/Desktop/Lab 1 Taskk 2/LED.c"
 void LED_Init() {
 TRISD.F0 = 0;
 PORTD.F0 = 0;
}

void LED_Toggle() {
 PORTD.F0 = ~PORTD.F0;
}
