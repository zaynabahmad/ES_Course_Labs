#line 1 "C:/Users/Amr/OneDrive/Desktop/Lab 1 Taskkk1/MyProject.c"
void short_sequence() {
 PORTB.B0 = 1;
 PORTB.B1 = 0;
 Delay_ms(200);
 PORTB.B0 = 0;
 PORTB.B1 = 1;
 Delay_ms(200);
}

void long_sequence() {
 PORTB.B0 = 1;
 PORTB.B1 = 0;
 Delay_ms(500);
 PORTB.B0 = 0;
 PORTB.B1 = 1;
 Delay_ms(500);
}

void main() {

 TRISB = 0x00;
 TRISD = 0xFF;

 PORTB = 0x00;

 while(1) {

 if(PORTD.B0 == 1) {
 short_sequence();
 }

 else if(PORTD.B1 == 1) {
 long_sequence();
 }

 else {
 PORTB.B0 = 0;
 PORTB.B1 = 0;
 }
 }
}
