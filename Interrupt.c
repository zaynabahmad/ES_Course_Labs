void interrupt () {

     if (INTCON.INTF) {

      PORTC.F0 = ~PORTC.F0;

      INTCON.INTF = 0;
      }}


void main () {

  TRISB.F0 = 1;
  TRISC.F0 = 0;

  PORTC.F0 = 0;

  OPTION_REG. INTEDG = 1; // Rising edge interrupt

  INTCON. INTF = 0; // Clear flag
  INTCON. INTE = 1; // Enable external interrupt
  INTCON.GIE = 1;


  while (1) { }

}
