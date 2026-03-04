void EXTI_INT0_Init() {
    TRISB.F0 = 1;
    ANSELH.F4 = 0;
    NOT_RBPU_bit = 0;
    INTEDG_bit = 0;

    INTCON.INTE = 1;
    INTCON.GIE = 1;
}