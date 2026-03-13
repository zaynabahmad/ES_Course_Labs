#ifndef INT_PRIVATE_H
#define INT_PRIVATE_H

/* PIC16F877A External Interrupt Bits for mikroC */
#define INTF_bit     INTCON.INTF      // INT0 flag
#define INTE_bit     INTCON.INTE      // INT0 enable

#define INT1F_bit    INTCON3.INT1F    // INT1 flag
#define INT1E_bit    INTCON3.INT1E    // INT1 enable

#define INT2F_bit    INTCON3.INT2F    // INT2 flag
#define INT2E_bit    INTCON3.INT2E    // INT2 enable

#define INTEDG2_bit  INTCON2.INTEDG2  // INT2 edge select

#endif