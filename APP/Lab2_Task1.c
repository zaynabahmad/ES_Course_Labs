void main()
{
TRISB = 0B00001100;
while (1)
{
if (PORTB.RB2==0b1)
{
PORTB.RB0 = 0b1 ;
PORTB.RB1= 0b1 ;
Delay_ms(200);
PORTB.RB0 = 0b0;
PORTB.RB1= 0b0;
Delay_ms(200);
}
else if (PORTB.RB3==0b1)
{
PORTB.RB1= 0b1;
PORTB.RB0= 0b1;
Delay_ms(500);
PORTB.RB1= 0b0;
PORTB.RB0= 0b0;
Delay_ms(500);
}
else
{
 PORTB.RB1= 0b0;
PORTB.RB0 = 0b0;
}
}
}