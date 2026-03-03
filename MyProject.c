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

     TRISB = 0x00;   // PORTB = output (LEDs)
     TRISD = 0xFF;   // PORTD = input (buttons)

     PORTB = 0x00;   // LEDs off

     while(1) {

         if(PORTD.B0 == 1) {          // Button 1
             short_sequence();
         }

         else if(PORTD.B1 == 1) {     // Button 2
             long_sequence();
         }

         else {
             PORTB.B0 = 0;
             PORTB.B1 = 0;
         }
     }
}