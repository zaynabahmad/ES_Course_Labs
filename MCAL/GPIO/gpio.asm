
_GPIO_setPinDirection:

;gpio.c,7 :: 		void GPIO_setPinDirection(u8 port, u8 pin, u8 direction) {
;gpio.c,8 :: 		if(pin > 7) return;
	MOVF       FARG_GPIO_setPinDirection_pin+0, 0
	SUBLW      7
	BTFSC      STATUS+0, 0
	GOTO       L_GPIO_setPinDirection0
	GOTO       L_end_GPIO_setPinDirection
L_GPIO_setPinDirection0:
;gpio.c,9 :: 		if (direction == GPIO_INPUT) {
	MOVF       FARG_GPIO_setPinDirection_direction+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_setPinDirection1
;gpio.c,10 :: 		switch (port) {
	GOTO       L_GPIO_setPinDirection2
;gpio.c,11 :: 		case GPIO_PORTA: SET_BIT(TRISA_REG, pin); break;
L_GPIO_setPinDirection4:
	MOVF       FARG_GPIO_setPinDirection_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinDirection57:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinDirection58
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinDirection57
L__GPIO_setPinDirection58:
	MOVF       R0+0, 0
	IORWF      133, 1
	GOTO       L_GPIO_setPinDirection3
;gpio.c,12 :: 		case GPIO_PORTB: SET_BIT(TRISB_REG, pin); break;
L_GPIO_setPinDirection5:
	MOVF       FARG_GPIO_setPinDirection_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinDirection59:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinDirection60
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinDirection59
L__GPIO_setPinDirection60:
	MOVF       R0+0, 0
	IORWF      134, 1
	GOTO       L_GPIO_setPinDirection3
;gpio.c,13 :: 		case GPIO_PORTC: SET_BIT(TRISC_REG, pin); break;
L_GPIO_setPinDirection6:
	MOVF       FARG_GPIO_setPinDirection_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinDirection61:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinDirection62
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinDirection61
L__GPIO_setPinDirection62:
	MOVF       R0+0, 0
	IORWF      135, 1
	GOTO       L_GPIO_setPinDirection3
;gpio.c,14 :: 		case GPIO_PORTD: SET_BIT(TRISD_REG, pin); break;
L_GPIO_setPinDirection7:
	MOVF       FARG_GPIO_setPinDirection_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinDirection63:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinDirection64
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinDirection63
L__GPIO_setPinDirection64:
	MOVF       R0+0, 0
	IORWF      136, 1
	GOTO       L_GPIO_setPinDirection3
;gpio.c,15 :: 		case GPIO_PORTE: SET_BIT(TRISE_REG, pin); break;
L_GPIO_setPinDirection8:
	MOVF       FARG_GPIO_setPinDirection_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinDirection65:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinDirection66
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinDirection65
L__GPIO_setPinDirection66:
	MOVF       R0+0, 0
	IORWF      137, 1
	GOTO       L_GPIO_setPinDirection3
;gpio.c,16 :: 		}
L_GPIO_setPinDirection2:
	MOVF       FARG_GPIO_setPinDirection_port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinDirection4
	MOVF       FARG_GPIO_setPinDirection_port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinDirection5
	MOVF       FARG_GPIO_setPinDirection_port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinDirection6
	MOVF       FARG_GPIO_setPinDirection_port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinDirection7
	MOVF       FARG_GPIO_setPinDirection_port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinDirection8
L_GPIO_setPinDirection3:
;gpio.c,17 :: 		} else {
	GOTO       L_GPIO_setPinDirection9
L_GPIO_setPinDirection1:
;gpio.c,18 :: 		switch (port) {
	GOTO       L_GPIO_setPinDirection10
;gpio.c,19 :: 		case GPIO_PORTA: CLR_BIT(TRISA_REG, pin); break;
L_GPIO_setPinDirection12:
	MOVF       FARG_GPIO_setPinDirection_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinDirection67:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinDirection68
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinDirection67
L__GPIO_setPinDirection68:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      133, 1
	GOTO       L_GPIO_setPinDirection11
;gpio.c,20 :: 		case GPIO_PORTB: CLR_BIT(TRISB_REG, pin); break;
L_GPIO_setPinDirection13:
	MOVF       FARG_GPIO_setPinDirection_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinDirection69:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinDirection70
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinDirection69
L__GPIO_setPinDirection70:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      134, 1
	GOTO       L_GPIO_setPinDirection11
;gpio.c,21 :: 		case GPIO_PORTC: CLR_BIT(TRISC_REG, pin); break;
L_GPIO_setPinDirection14:
	MOVF       FARG_GPIO_setPinDirection_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinDirection71:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinDirection72
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinDirection71
L__GPIO_setPinDirection72:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      135, 1
	GOTO       L_GPIO_setPinDirection11
;gpio.c,22 :: 		case GPIO_PORTD: CLR_BIT(TRISD_REG, pin); break;
L_GPIO_setPinDirection15:
	MOVF       FARG_GPIO_setPinDirection_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinDirection73:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinDirection74
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinDirection73
L__GPIO_setPinDirection74:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      136, 1
	GOTO       L_GPIO_setPinDirection11
;gpio.c,23 :: 		case GPIO_PORTE: CLR_BIT(TRISE_REG, pin); break;
L_GPIO_setPinDirection16:
	MOVF       FARG_GPIO_setPinDirection_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinDirection75:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinDirection76
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinDirection75
L__GPIO_setPinDirection76:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      137, 1
	GOTO       L_GPIO_setPinDirection11
;gpio.c,24 :: 		}
L_GPIO_setPinDirection10:
	MOVF       FARG_GPIO_setPinDirection_port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinDirection12
	MOVF       FARG_GPIO_setPinDirection_port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinDirection13
	MOVF       FARG_GPIO_setPinDirection_port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinDirection14
	MOVF       FARG_GPIO_setPinDirection_port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinDirection15
	MOVF       FARG_GPIO_setPinDirection_port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinDirection16
L_GPIO_setPinDirection11:
;gpio.c,25 :: 		}
L_GPIO_setPinDirection9:
;gpio.c,26 :: 		}
L_end_GPIO_setPinDirection:
	RETURN
; end of _GPIO_setPinDirection

_GPIO_setPinValue:

;gpio.c,28 :: 		void GPIO_setPinValue(u8 port, u8 pin, u8 value) {
;gpio.c,29 :: 		if(pin > 7) return;
	MOVF       FARG_GPIO_setPinValue_pin+0, 0
	SUBLW      7
	BTFSC      STATUS+0, 0
	GOTO       L_GPIO_setPinValue17
	GOTO       L_end_GPIO_setPinValue
L_GPIO_setPinValue17:
;gpio.c,30 :: 		if (value == GPIO_HIGH) {
	MOVF       FARG_GPIO_setPinValue_value+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_setPinValue18
;gpio.c,31 :: 		switch (port) {
	GOTO       L_GPIO_setPinValue19
;gpio.c,32 :: 		case GPIO_PORTA: SET_BIT(PORTA_REG, pin); break;
L_GPIO_setPinValue21:
	MOVF       FARG_GPIO_setPinValue_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinValue78:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinValue79
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinValue78
L__GPIO_setPinValue79:
	MOVF       R0+0, 0
	IORWF      5, 1
	GOTO       L_GPIO_setPinValue20
;gpio.c,33 :: 		case GPIO_PORTB: SET_BIT(PORTB_REG, pin); break;
L_GPIO_setPinValue22:
	MOVF       FARG_GPIO_setPinValue_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinValue80:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinValue81
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinValue80
L__GPIO_setPinValue81:
	MOVF       R0+0, 0
	IORWF      6, 1
	GOTO       L_GPIO_setPinValue20
;gpio.c,34 :: 		case GPIO_PORTC: SET_BIT(PORTC_REG, pin); break;
L_GPIO_setPinValue23:
	MOVF       FARG_GPIO_setPinValue_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinValue82:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinValue83
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinValue82
L__GPIO_setPinValue83:
	MOVF       R0+0, 0
	IORWF      7, 1
	GOTO       L_GPIO_setPinValue20
;gpio.c,35 :: 		case GPIO_PORTD: SET_BIT(PORTD_REG, pin); break;
L_GPIO_setPinValue24:
	MOVF       FARG_GPIO_setPinValue_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinValue84:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinValue85
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinValue84
L__GPIO_setPinValue85:
	MOVF       R0+0, 0
	IORWF      8, 1
	GOTO       L_GPIO_setPinValue20
;gpio.c,36 :: 		case GPIO_PORTE: SET_BIT(PORTE_REG, pin); break;
L_GPIO_setPinValue25:
	MOVF       FARG_GPIO_setPinValue_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinValue86:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinValue87
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinValue86
L__GPIO_setPinValue87:
	MOVF       R0+0, 0
	IORWF      9, 1
	GOTO       L_GPIO_setPinValue20
;gpio.c,37 :: 		}
L_GPIO_setPinValue19:
	MOVF       FARG_GPIO_setPinValue_port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinValue21
	MOVF       FARG_GPIO_setPinValue_port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinValue22
	MOVF       FARG_GPIO_setPinValue_port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinValue23
	MOVF       FARG_GPIO_setPinValue_port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinValue24
	MOVF       FARG_GPIO_setPinValue_port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinValue25
L_GPIO_setPinValue20:
;gpio.c,38 :: 		} else {
	GOTO       L_GPIO_setPinValue26
L_GPIO_setPinValue18:
;gpio.c,39 :: 		switch (port) {
	GOTO       L_GPIO_setPinValue27
;gpio.c,40 :: 		case GPIO_PORTA: CLR_BIT(PORTA_REG, pin); break;
L_GPIO_setPinValue29:
	MOVF       FARG_GPIO_setPinValue_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinValue88:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinValue89
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinValue88
L__GPIO_setPinValue89:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      5, 1
	GOTO       L_GPIO_setPinValue28
;gpio.c,41 :: 		case GPIO_PORTB: CLR_BIT(PORTB_REG, pin); break;
L_GPIO_setPinValue30:
	MOVF       FARG_GPIO_setPinValue_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinValue90:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinValue91
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinValue90
L__GPIO_setPinValue91:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      6, 1
	GOTO       L_GPIO_setPinValue28
;gpio.c,42 :: 		case GPIO_PORTC: CLR_BIT(PORTC_REG, pin); break;
L_GPIO_setPinValue31:
	MOVF       FARG_GPIO_setPinValue_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinValue92:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinValue93
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinValue92
L__GPIO_setPinValue93:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      7, 1
	GOTO       L_GPIO_setPinValue28
;gpio.c,43 :: 		case GPIO_PORTD: CLR_BIT(PORTD_REG, pin); break;
L_GPIO_setPinValue32:
	MOVF       FARG_GPIO_setPinValue_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinValue94:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinValue95
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinValue94
L__GPIO_setPinValue95:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      8, 1
	GOTO       L_GPIO_setPinValue28
;gpio.c,44 :: 		case GPIO_PORTE: CLR_BIT(PORTE_REG, pin); break;
L_GPIO_setPinValue33:
	MOVF       FARG_GPIO_setPinValue_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_setPinValue96:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_setPinValue97
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_setPinValue96
L__GPIO_setPinValue97:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      9, 1
	GOTO       L_GPIO_setPinValue28
;gpio.c,45 :: 		}
L_GPIO_setPinValue27:
	MOVF       FARG_GPIO_setPinValue_port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinValue29
	MOVF       FARG_GPIO_setPinValue_port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinValue30
	MOVF       FARG_GPIO_setPinValue_port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinValue31
	MOVF       FARG_GPIO_setPinValue_port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinValue32
	MOVF       FARG_GPIO_setPinValue_port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPinValue33
L_GPIO_setPinValue28:
;gpio.c,46 :: 		}
L_GPIO_setPinValue26:
;gpio.c,47 :: 		}
L_end_GPIO_setPinValue:
	RETURN
; end of _GPIO_setPinValue

_GPIO_getPinValue:

;gpio.c,49 :: 		u8 GPIO_getPinValue(u8 port, u8 pin) {
;gpio.c,50 :: 		u8 pinVal = 0;
	CLRF       GPIO_getPinValue_pinVal_L0+0
;gpio.c,51 :: 		if(pin > 7) return 0;
	MOVF       FARG_GPIO_getPinValue_pin+0, 0
	SUBLW      7
	BTFSC      STATUS+0, 0
	GOTO       L_GPIO_getPinValue34
	CLRF       R0+0
	GOTO       L_end_GPIO_getPinValue
L_GPIO_getPinValue34:
;gpio.c,52 :: 		switch (port) {
	GOTO       L_GPIO_getPinValue35
;gpio.c,53 :: 		case GPIO_PORTA: pinVal = GET_BIT(PORTA_REG, pin); break;
L_GPIO_getPinValue37:
	MOVF       FARG_GPIO_getPinValue_pin+0, 0
	MOVWF      R0+0
	MOVF       5, 0
	MOVWF      GPIO_getPinValue_pinVal_L0+0
	MOVF       R0+0, 0
L__GPIO_getPinValue99:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_getPinValue100
	RRF        GPIO_getPinValue_pinVal_L0+0, 1
	BCF        GPIO_getPinValue_pinVal_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_getPinValue99
L__GPIO_getPinValue100:
	MOVLW      1
	ANDWF      GPIO_getPinValue_pinVal_L0+0, 1
	GOTO       L_GPIO_getPinValue36
;gpio.c,54 :: 		case GPIO_PORTB: pinVal = GET_BIT(PORTB_REG, pin); break;
L_GPIO_getPinValue38:
	MOVF       FARG_GPIO_getPinValue_pin+0, 0
	MOVWF      R0+0
	MOVF       6, 0
	MOVWF      GPIO_getPinValue_pinVal_L0+0
	MOVF       R0+0, 0
L__GPIO_getPinValue101:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_getPinValue102
	RRF        GPIO_getPinValue_pinVal_L0+0, 1
	BCF        GPIO_getPinValue_pinVal_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_getPinValue101
L__GPIO_getPinValue102:
	MOVLW      1
	ANDWF      GPIO_getPinValue_pinVal_L0+0, 1
	GOTO       L_GPIO_getPinValue36
;gpio.c,55 :: 		case GPIO_PORTC: pinVal = GET_BIT(PORTC_REG, pin); break;
L_GPIO_getPinValue39:
	MOVF       FARG_GPIO_getPinValue_pin+0, 0
	MOVWF      R0+0
	MOVF       7, 0
	MOVWF      GPIO_getPinValue_pinVal_L0+0
	MOVF       R0+0, 0
L__GPIO_getPinValue103:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_getPinValue104
	RRF        GPIO_getPinValue_pinVal_L0+0, 1
	BCF        GPIO_getPinValue_pinVal_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_getPinValue103
L__GPIO_getPinValue104:
	MOVLW      1
	ANDWF      GPIO_getPinValue_pinVal_L0+0, 1
	GOTO       L_GPIO_getPinValue36
;gpio.c,56 :: 		case GPIO_PORTD: pinVal = GET_BIT(PORTD_REG, pin); break;
L_GPIO_getPinValue40:
	MOVF       FARG_GPIO_getPinValue_pin+0, 0
	MOVWF      R0+0
	MOVF       8, 0
	MOVWF      GPIO_getPinValue_pinVal_L0+0
	MOVF       R0+0, 0
L__GPIO_getPinValue105:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_getPinValue106
	RRF        GPIO_getPinValue_pinVal_L0+0, 1
	BCF        GPIO_getPinValue_pinVal_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_getPinValue105
L__GPIO_getPinValue106:
	MOVLW      1
	ANDWF      GPIO_getPinValue_pinVal_L0+0, 1
	GOTO       L_GPIO_getPinValue36
;gpio.c,57 :: 		case GPIO_PORTE: pinVal = GET_BIT(PORTE_REG, pin); break;
L_GPIO_getPinValue41:
	MOVF       FARG_GPIO_getPinValue_pin+0, 0
	MOVWF      R0+0
	MOVF       9, 0
	MOVWF      GPIO_getPinValue_pinVal_L0+0
	MOVF       R0+0, 0
L__GPIO_getPinValue107:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_getPinValue108
	RRF        GPIO_getPinValue_pinVal_L0+0, 1
	BCF        GPIO_getPinValue_pinVal_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_getPinValue107
L__GPIO_getPinValue108:
	MOVLW      1
	ANDWF      GPIO_getPinValue_pinVal_L0+0, 1
	GOTO       L_GPIO_getPinValue36
;gpio.c,58 :: 		}
L_GPIO_getPinValue35:
	MOVF       FARG_GPIO_getPinValue_port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_getPinValue37
	MOVF       FARG_GPIO_getPinValue_port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_getPinValue38
	MOVF       FARG_GPIO_getPinValue_port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_getPinValue39
	MOVF       FARG_GPIO_getPinValue_port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_getPinValue40
	MOVF       FARG_GPIO_getPinValue_port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_getPinValue41
L_GPIO_getPinValue36:
;gpio.c,59 :: 		return pinVal;
	MOVF       GPIO_getPinValue_pinVal_L0+0, 0
	MOVWF      R0+0
;gpio.c,60 :: 		}
L_end_GPIO_getPinValue:
	RETURN
; end of _GPIO_getPinValue

_GPIO_setPortDirection:

;gpio.c,62 :: 		void GPIO_setPortDirection(u8 port, u8 direction) {
;gpio.c,63 :: 		switch(port) {
	GOTO       L_GPIO_setPortDirection42
;gpio.c,64 :: 		case GPIO_PORTA: TRISA_REG = direction; break;
L_GPIO_setPortDirection44:
	MOVF       FARG_GPIO_setPortDirection_direction+0, 0
	MOVWF      133
	GOTO       L_GPIO_setPortDirection43
;gpio.c,65 :: 		case GPIO_PORTB: TRISB_REG = direction; break;
L_GPIO_setPortDirection45:
	MOVF       FARG_GPIO_setPortDirection_direction+0, 0
	MOVWF      134
	GOTO       L_GPIO_setPortDirection43
;gpio.c,66 :: 		case GPIO_PORTC: TRISC_REG = direction; break;
L_GPIO_setPortDirection46:
	MOVF       FARG_GPIO_setPortDirection_direction+0, 0
	MOVWF      135
	GOTO       L_GPIO_setPortDirection43
;gpio.c,67 :: 		case GPIO_PORTD: TRISD_REG = direction; break;
L_GPIO_setPortDirection47:
	MOVF       FARG_GPIO_setPortDirection_direction+0, 0
	MOVWF      136
	GOTO       L_GPIO_setPortDirection43
;gpio.c,68 :: 		case GPIO_PORTE: TRISE_REG = direction; break;
L_GPIO_setPortDirection48:
	MOVF       FARG_GPIO_setPortDirection_direction+0, 0
	MOVWF      137
	GOTO       L_GPIO_setPortDirection43
;gpio.c,69 :: 		}
L_GPIO_setPortDirection42:
	MOVF       FARG_GPIO_setPortDirection_port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPortDirection44
	MOVF       FARG_GPIO_setPortDirection_port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPortDirection45
	MOVF       FARG_GPIO_setPortDirection_port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPortDirection46
	MOVF       FARG_GPIO_setPortDirection_port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPortDirection47
	MOVF       FARG_GPIO_setPortDirection_port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPortDirection48
L_GPIO_setPortDirection43:
;gpio.c,70 :: 		}
L_end_GPIO_setPortDirection:
	RETURN
; end of _GPIO_setPortDirection

_GPIO_setPortValue:

;gpio.c,72 :: 		void GPIO_setPortValue(u8 port, u8 value) {
;gpio.c,73 :: 		switch(port) {
	GOTO       L_GPIO_setPortValue49
;gpio.c,74 :: 		case GPIO_PORTA: PORTA_REG = value; break;
L_GPIO_setPortValue51:
	MOVF       FARG_GPIO_setPortValue_value+0, 0
	MOVWF      5
	GOTO       L_GPIO_setPortValue50
;gpio.c,75 :: 		case GPIO_PORTB: PORTB_REG = value; break;
L_GPIO_setPortValue52:
	MOVF       FARG_GPIO_setPortValue_value+0, 0
	MOVWF      6
	GOTO       L_GPIO_setPortValue50
;gpio.c,76 :: 		case GPIO_PORTC: PORTC_REG = value; break;
L_GPIO_setPortValue53:
	MOVF       FARG_GPIO_setPortValue_value+0, 0
	MOVWF      7
	GOTO       L_GPIO_setPortValue50
;gpio.c,77 :: 		case GPIO_PORTD: PORTD_REG = value; break;
L_GPIO_setPortValue54:
	MOVF       FARG_GPIO_setPortValue_value+0, 0
	MOVWF      8
	GOTO       L_GPIO_setPortValue50
;gpio.c,78 :: 		case GPIO_PORTE: PORTE_REG = value; break;
L_GPIO_setPortValue55:
	MOVF       FARG_GPIO_setPortValue_value+0, 0
	MOVWF      9
	GOTO       L_GPIO_setPortValue50
;gpio.c,79 :: 		}
L_GPIO_setPortValue49:
	MOVF       FARG_GPIO_setPortValue_port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPortValue51
	MOVF       FARG_GPIO_setPortValue_port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPortValue52
	MOVF       FARG_GPIO_setPortValue_port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPortValue53
	MOVF       FARG_GPIO_setPortValue_port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPortValue54
	MOVF       FARG_GPIO_setPortValue_port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_setPortValue55
L_GPIO_setPortValue50:
;gpio.c,80 :: 		}
L_end_GPIO_setPortValue:
	RETURN
; end of _GPIO_setPortValue
