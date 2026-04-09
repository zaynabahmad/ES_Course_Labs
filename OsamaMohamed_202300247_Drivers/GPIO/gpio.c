#include "gpio.h"
#include "../common_macros.h"


static volatile unsigned char* getTRIS(GPIO_PortID port) {
    switch (port) {
        case PORTA_ID: return &TRISA;
        case PORTB_ID: return &TRISB;
        case PORTC_ID: return &TRISC;
        case PORTD_ID: return &TRISD;
        case PORTE_ID: return &TRISE;
        default:       return &TRISA;
    }
}

static volatile unsigned char* getPORT(GPIO_PortID port) {
    switch (port) {
        case PORTA_ID: return &PORTA;
        case PORTB_ID: return &PORTB;
        case PORTC_ID: return &PORTC;
        case PORTD_ID: return &PORTD;
        case PORTE_ID: return &PORTE;
        default:       return &PORTA;
    }
}


void GPIO_setupPinDirection(GPIO_PortID port, GPIO_PinID pin, GPIO_PinDirection dir) {
    volatile unsigned char *tris = getTRIS(port);
    if (dir == PIN_INPUT)
        SET_BIT(*tris, pin);    /* 1 = Input  */
    else
        CLEAR_BIT(*tris, pin);  /* 0 = Output */
}

void GPIO_writePin(GPIO_PortID port, GPIO_PinID pin, uint8 value) {
    volatile unsigned char *p = getPORT(port);
    if (value)
        SET_BIT(*p, pin);
    else
        CLEAR_BIT(*p, pin);
}

uint8 GPIO_readPin(GPIO_PortID port, GPIO_PinID pin) {
    return GET_BIT(*getPORT(port), pin);
}

void GPIO_setupPortDirection(GPIO_PortID port, GPIO_PortDirection dir) {
    *getTRIS(port) = (unsigned char)dir;
}

void GPIO_writePort(GPIO_PortID port, uint8 value) {
    *getPORT(port) = value;
}

uint8 GPIO_readPort(GPIO_PortID port) {
    return *getPORT(port);
}
