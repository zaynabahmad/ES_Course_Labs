#include "../../SERVICES/Bit_Math.h"
#include "GPIO.h"

/* Register Definitions based on Datasheet Memory Map */
#define PORTA    *((volatile u8*)0x05)
#define TRISA    *((volatile u8*)0x85)

#define PORTB    *((volatile u8*)0x06)
#define TRISB    *((volatile u8*)0x86)

#define PORTC    *((volatile u8*)0x07)
#define TRISC    *((volatile u8*)0x87)

#define PORTD    *((volatile u8*)0x08)
#define TRISD    *((volatile u8*)0x88)

#define PORTE    *((volatile u8*)0x09)
#define TRISE    *((volatile u8*)0x89)

void GPIO_voidSetPinDirection(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8Direction) {
    if (copy_u8Direction == OUTPUT) {
        switch(copy_u8PortID) {
            case PORTA_ID: CLR_BIT(TRISA, copy_u8PinID); break;
            case PORTB_ID: CLR_BIT(TRISB, copy_u8PinID); break;
            case PORTC_ID: CLR_BIT(TRISC, copy_u8PinID); break;
            case PORTD_ID: CLR_BIT(TRISD, copy_u8PinID); break;
            case PORTE_ID: CLR_BIT(TRISE, copy_u8PinID); break;
        }
    } else {
        switch(copy_u8PortID) {
            case PORTA_ID: SET_BIT(TRISA, copy_u8PinID); break;
            case PORTB_ID: SET_BIT(TRISB, copy_u8PinID); break;
            case PORTC_ID: SET_BIT(TRISC, copy_u8PinID); break;
            case PORTD_ID: SET_BIT(TRISD, copy_u8PinID); break;
            case PORTE_ID: SET_BIT(TRISE, copy_u8PinID); break;
        }
    }
}

void GPIO_voidSetPinValue(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8Value) {
    if (copy_u8Value == HIGH) {
        switch(copy_u8PortID) {
            case PORTA_ID: SET_BIT(PORTA, copy_u8PinID); break;
            case PORTB_ID: SET_BIT(PORTB, copy_u8PinID); break;
            case PORTC_ID: SET_BIT(PORTC, copy_u8PinID); break;
            case PORTD_ID: SET_BIT(PORTD, copy_u8PinID); break;
            case PORTE_ID: SET_BIT(PORTE, copy_u8PinID); break;
        }
    } else {
        switch(copy_u8PortID) {
            case PORTA_ID: CLR_BIT(PORTA, copy_u8PinID); break;
            case PORTB_ID: CLR_BIT(PORTB, copy_u8PinID); break;
            case PORTC_ID: CLR_BIT(PORTC, copy_u8PinID); break;
            case PORTD_ID: CLR_BIT(PORTD, copy_u8PinID); break;
            case PORTE_ID: CLR_BIT(PORTE, copy_u8PinID); break;
        }
    }
}

/* THIS WAS THE MISSING FUNCTION CAUSING THE LINKER ERROR */
u8 GPIO_u8GetPinValue(u8 copy_u8PortID, u8 copy_u8PinID) {
    u8 local_u8Result = 0;
    switch(copy_u8PortID) {
        case PORTA_ID: local_u8Result = GET_BIT(PORTA, copy_u8PinID); break;
        case PORTB_ID: local_u8Result = GET_BIT(PORTB, copy_u8PinID); break;
        case PORTC_ID: local_u8Result = GET_BIT(PORTC, copy_u8PinID); break;
        case PORTD_ID: local_u8Result = GET_BIT(PORTD, copy_u8PinID); break;
        case PORTE_ID: local_u8Result = GET_BIT(PORTE, copy_u8PinID); break;
    }
    return local_u8Result;
}