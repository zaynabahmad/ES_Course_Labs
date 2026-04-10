//INTCON
#define GIE   7
#define PEIE  6
#define T0IE  5
#define INTE  4
#define RBIE  3
#define T0IF  2
#define INTF  1
#define RBIF  0


//PIR1

#define PSPIF  7
#define ADIF   6
#define RCIF   5
#define TXIF   4
#define SSPIF  3
#define CCP1IF 2
#define TMR2IF 1
#define TMR1IF 0


//PIE1
#define PSPIE  7
#define ADIE   6
#define RCIE   5
#define TXIE   4
#define SSPIE  3
#define CCP1IE 2
#define TMR2IE 1
#define TMR1IE 0


//RCSTA
#define SPEN 7
#define RX9  6
#define SREN 5
#define CREN 4
// bit 3 unused
#define FERR 2
#define OERR 1
#define RX9D 0


// TXSTA
#define CSRC 7
#define TX9  6
#define TXEN 5
#define SYNC 4
// bit 3 unused
#define BRGH 2
#define TRMT 1
#define TX9D 0