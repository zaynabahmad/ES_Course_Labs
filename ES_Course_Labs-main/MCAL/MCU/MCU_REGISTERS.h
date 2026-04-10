#ifndef MCU_REGISTERS_H
#define MCU_REGISTERS_H

// GPIO
#define TRISA   (*((volatile u8*)0x85))
#define TRISB   (*((volatile u8*)0x86))
#define TRISC   (*((volatile u8*)0x87))
#define TRISD   (*((volatile u8*)0x88))
#define TRISE   (*((volatile u8*)0x89))

#define PORTA   (*((volatile u8*)0x05))
#define PORTB   (*((volatile u8*)0x06))
#define PORTC   (*((volatile u8*)0x07))
#define PORTD   (*((volatile u8*)0x08))
#define PORTE   (*((volatile u8*)0x09))


//INTERRUPT
#define INTCON  (*((volatile u8*)0x8B))
//TIMER
#define TMR0 (*(volatile u8*)0x01)
#define OPTION_REG  (*((volatile u8*)0x181))



//                INTERRUPT REGISTERS
#define PIR1    (*((volatile u8*)0x0C))
#define PIE1    (*((volatile u8*)0x8C))



//                UART REGISTERS

// Receive Status and Control Register
#define RCSTA   (*((volatile u8*)0x18))

// Transmit Data Register
#define TXREG   (*((volatile u8*)0x19))

// Transmit Status and Control Register
#define TXSTA   (*((volatile u8*)0x98))

// Baud Rate Generator Register
#define SPBRG   (*((volatile u8*)0x99))



//                SPI (SSP) REGISTERS

// SPI Data Buffer
#define SSPBUF   (*((volatile u8*)0x13))

// SPI Control Register
#define SSPCON   (*((volatile u8*)0x14))

// SPI Status Register
#define SSPSTAT  (*((volatile u8*)0x94))

//ADC REGISTERS


// A/D Result High Byte
#define ADRESH   (*((volatile u8*)0x1E))

// A/D Result Low Byte
#define ADRESL   (*((volatile u8*)0x9E))

// A/D Control Register 0
#define ADCON0   (*((volatile u8*)0x1F))

// A/D Control Register 1
#define ADCON1   (*((volatile u8*)0x9F))


#endif // MCU_REGISTERS_H