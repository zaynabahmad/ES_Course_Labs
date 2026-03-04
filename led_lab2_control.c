void main() {
    // 1. «·≈⁄œ«œ«  (Setup)
    ANSEL  = 0x00;        //  ÕÊÌ· «·√—Ã· ·œÌÃÌ «·
    ANSELH = 0x00;

    TRISB = 0x03;      // RB0 Ê RB1 „œ«Œ· ··“—«Ì—
    TRISD = 0x00;      // »Ê—  D ﬂ·Â „Œ«—Ã ··Ìœ« 

    OPTION_REG.F7 = 0; //  ›⁄Ì· «·‹ Pull-ups
    WPUB = 0x03;

    PORTD = 0x00;      //  ’›Ì— «··Ìœ« 

    while(1) {         // »œ«Ì… «·Õ·ﬁ… «·„” „—…

        if (PORTB.F0 == 0) { // ›Õ’ «·“—«— «·√Ê·
            PORTD = 0x03;
            delay_ms(200);
            PORTD = 0x00;
            delay_ms(200);
        }
        else if (PORTB.F1 == 0) { // ›Õ’ «·“—«— «·À«‰Ì
            PORTD = 0x03;
            delay_ms(500);
            PORTD = 0x00;
            delay_ms(500);
        }
        else {
            PORTD = 0x00;    // ·Ê „›Ì‘ ÷€ÿ
        }

    } // ﬁ›·… «·‹ while

} // ﬁ›·… «·‹ main (« √ﬂœÌ ≈‰ «·ﬁÊ” œÂ „ÊÃÊœ Ê„›Ì‘ Õ«Ã… »⁄œÂ)}