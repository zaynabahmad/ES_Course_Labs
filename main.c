
#define LED1 PORTB.F0
#define LED2 PORTB.F1


#define SW1  PORTA.F0
#define SW2  PORTA.F1

void short_sequence() {
     LED1 = 1;
     LED2 = 1;
     Delay_ms(200);

     LED1 = 0;
     LED2 = 0;
     Delay_ms(200);
}

void long_sequence() {
     LED1 = 1;
     LED2 = 1;
     Delay_ms(500);

     LED1 = 0;
     LED2 = 0;
     Delay_ms(500);
}

void main() {


     TRISB.F0 = 0;
     TRISB.F1 = 0;


     TRISA.F0 = 1;
     TRISA.F1 = 1;


     LED1 = 0;
     LED2 = 0;

     while(1) {

         if(SW1 == 1) {
              short_sequence();
         }

         else if(SW2 == 1) {
              long_sequence();
         }

         else {
              LED1 = 0;
              LED2 = 0;
         }
     }
}