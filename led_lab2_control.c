void main() {
    // 1. الإعدادات (Setup)
    ANSEL  = 0x00;        
    ANSELH = 0x00;

    TRISB = 0x03;     
    TRISD = 0x00;      

    OPTION_REG.F7 = 0; 
    WPUB = 0x03;

    PORTD = 0x00;      

    while(1) {         

        if (PORTB.F0 == 0) { 
            PORTD = 0x03;
            delay_ms(200);
            PORTD = 0x00;
            delay_ms(200);
        }
        else if (PORTB.F1 == 0) {
            PORTD = 0x03;
            delay_ms(500);
            PORTD = 0x00;
            delay_ms(500);
        }
        else {
            PORTD = 0x00;    
        }

    } 


} // قفلة الـ main (اتأكدي إن القوس ده موجود ومفيش حاجة بعده)}
