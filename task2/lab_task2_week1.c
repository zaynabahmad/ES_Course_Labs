
void interrupt()
{
    if (INTCON.INTF == 1)
    {
        PORTD.F0 = ~PORTD.F0;
        INTCON.INTF = 0;        // Clear interrupt flag
    }
}

void main()
{
    ADCON1 = 0x06;

    TRISD.F0 = 0;    // RD0 as output (LED)
    PORTD.F0 = 0;

    TRISB.F0 = 1;    // RB0 as input (INT0)

    OPTION_REG.INTEDG = 1;

    INTCON.INTF = 0;
    INTCON.INTE = 1;  // Enable INT0
    INTCON.GIE  = 1;  // Enable Global Interrupt

    while(1)
    {

    }
}