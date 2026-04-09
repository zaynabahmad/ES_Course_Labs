#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/*
    Mode Selection
    0 = SPI Master mode, clock = FOSC/4
    1 = SPI Master mode, clock = FOSC/16
    2 = SPI Master mode, clock = FOSC/64
    3 = SPI Master mode, clock = TMR2 output/2
    4 = SPI Slave mode, clock = SCK pin, SS pin control enabled
    5 = SPI Slave mode, clock = SCK pin, SS pin control disabled
*/
#define SPI_MODE_SELECT         0

/* 
    Clock Polarity 
    0 = Idle state for clock is a low level
    1 = Idle state for clock is a high level
*/
#define SPI_CLOCK_POLARITY      0

/*
    Clock Edge
    0 = Transmit occurs on transition from Idle to active clock state
    1 = Transmit occurs on transition from active to Idle clock state
*/
#define SPI_CLOCK_PHASE         0

/* 
    Data Input Sample Phase 
    (Must be 0 in Slave Mode)
    0 = Input data sampled at middle of data output time
    1 = Input data sampled at end of data output time
*/
#define SPI_DATA_SAMPLE         0

#endif
