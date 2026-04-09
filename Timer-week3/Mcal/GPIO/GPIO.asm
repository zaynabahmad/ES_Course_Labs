
_GPIO_SetPinDirection:

;GPIO.c,5 :: 		void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction)
;GPIO.c,7 :: 		if (Direction == GPIO_OUTPUT)
	MOVF       FARG_GPIO_SetPinDirection_Direction+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection0
;GPIO.c,9 :: 		switch (Port)
	GOTO       L_GPIO_SetPinDirection1
;GPIO.c,11 :: 		case GPIO_PORTA: CLR_BIT(TRISA, Pin); break;
L_GPIO_SetPinDirection3:
	MOVF       FARG_GPIO_SetPinDirection_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection49:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection50
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection49
L__GPIO_SetPinDirection50:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      TRISA+0, 1
	GOTO       L_GPIO_SetPinDirection2
;GPIO.c,12 :: 		case GPIO_PORTB: CLR_BIT(TRISB, Pin); break;
L_GPIO_SetPinDirection4:
	MOVF       FARG_GPIO_SetPinDirection_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection51:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection52
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection51
L__GPIO_SetPinDirection52:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      TRISB+0, 1
	GOTO       L_GPIO_SetPinDirection2
;GPIO.c,13 :: 		case GPIO_PORTC: CLR_BIT(TRISC, Pin); break;
L_GPIO_SetPinDirection5:
	MOVF       FARG_GPIO_SetPinDirection_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection53:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection54
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection53
L__GPIO_SetPinDirection54:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      TRISC+0, 1
	GOTO       L_GPIO_SetPinDirection2
;GPIO.c,14 :: 		case GPIO_PORTD: CLR_BIT(TRISD, Pin); break;
L_GPIO_SetPinDirection6:
	MOVF       FARG_GPIO_SetPinDirection_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection55:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection56
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection55
L__GPIO_SetPinDirection56:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      TRISD+0, 1
	GOTO       L_GPIO_SetPinDirection2
;GPIO.c,15 :: 		case GPIO_PORTE: CLR_BIT(TRISE, Pin); break;
L_GPIO_SetPinDirection7:
	MOVF       FARG_GPIO_SetPinDirection_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection57:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection58
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection57
L__GPIO_SetPinDirection58:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      TRISE+0, 1
	GOTO       L_GPIO_SetPinDirection2
;GPIO.c,16 :: 		}
L_GPIO_SetPinDirection1:
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection3
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection4
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection5
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection6
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection7
L_GPIO_SetPinDirection2:
;GPIO.c,17 :: 		}
	GOTO       L_GPIO_SetPinDirection8
L_GPIO_SetPinDirection0:
;GPIO.c,18 :: 		else if (Direction == GPIO_INPUT)
	MOVF       FARG_GPIO_SetPinDirection_Direction+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection9
;GPIO.c,20 :: 		switch (Port)
	GOTO       L_GPIO_SetPinDirection10
;GPIO.c,22 :: 		case GPIO_PORTA: SET_BIT(TRISA, Pin); break;
L_GPIO_SetPinDirection12:
	MOVF       FARG_GPIO_SetPinDirection_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection59:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection60
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection59
L__GPIO_SetPinDirection60:
	MOVF       R0+0, 0
	IORWF      TRISA+0, 1
	GOTO       L_GPIO_SetPinDirection11
;GPIO.c,23 :: 		case GPIO_PORTB: SET_BIT(TRISB, Pin); break;
L_GPIO_SetPinDirection13:
	MOVF       FARG_GPIO_SetPinDirection_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection61:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection62
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection61
L__GPIO_SetPinDirection62:
	MOVF       R0+0, 0
	IORWF      TRISB+0, 1
	GOTO       L_GPIO_SetPinDirection11
;GPIO.c,24 :: 		case GPIO_PORTC: SET_BIT(TRISC, Pin); break;
L_GPIO_SetPinDirection14:
	MOVF       FARG_GPIO_SetPinDirection_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection63:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection64
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection63
L__GPIO_SetPinDirection64:
	MOVF       R0+0, 0
	IORWF      TRISC+0, 1
	GOTO       L_GPIO_SetPinDirection11
;GPIO.c,25 :: 		case GPIO_PORTD: SET_BIT(TRISD, Pin); break;
L_GPIO_SetPinDirection15:
	MOVF       FARG_GPIO_SetPinDirection_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection65:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection66
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection65
L__GPIO_SetPinDirection66:
	MOVF       R0+0, 0
	IORWF      TRISD+0, 1
	GOTO       L_GPIO_SetPinDirection11
;GPIO.c,26 :: 		case GPIO_PORTE: SET_BIT(TRISE, Pin); break;
L_GPIO_SetPinDirection16:
	MOVF       FARG_GPIO_SetPinDirection_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection67:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection68
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection67
L__GPIO_SetPinDirection68:
	MOVF       R0+0, 0
	IORWF      TRISE+0, 1
	GOTO       L_GPIO_SetPinDirection11
;GPIO.c,27 :: 		}
L_GPIO_SetPinDirection10:
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection12
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection13
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection14
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection15
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection16
L_GPIO_SetPinDirection11:
;GPIO.c,28 :: 		}
L_GPIO_SetPinDirection9:
L_GPIO_SetPinDirection8:
;GPIO.c,29 :: 		}
L_end_GPIO_SetPinDirection:
	RETURN
; end of _GPIO_SetPinDirection

_GPIO_SetPinValue:

;GPIO.c,31 :: 		void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value)
;GPIO.c,33 :: 		if (Value == GPIO_HIGH)
	MOVF       FARG_GPIO_SetPinValue_Value+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue17
;GPIO.c,35 :: 		switch (Port)
	GOTO       L_GPIO_SetPinValue18
;GPIO.c,37 :: 		case GPIO_PORTA: SET_BIT(PORTA, Pin); break;
L_GPIO_SetPinValue20:
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue70:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue71
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue70
L__GPIO_SetPinValue71:
	MOVF       R0+0, 0
	IORWF      PORTA+0, 1
	GOTO       L_GPIO_SetPinValue19
;GPIO.c,38 :: 		case GPIO_PORTB: SET_BIT(PORTB, Pin); break;
L_GPIO_SetPinValue21:
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue72:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue73
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue72
L__GPIO_SetPinValue73:
	MOVF       R0+0, 0
	IORWF      PORTB+0, 1
	GOTO       L_GPIO_SetPinValue19
;GPIO.c,39 :: 		case GPIO_PORTC: SET_BIT(PORTC, Pin); break;
L_GPIO_SetPinValue22:
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue74:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue75
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue74
L__GPIO_SetPinValue75:
	MOVF       R0+0, 0
	IORWF      PORTC+0, 1
	GOTO       L_GPIO_SetPinValue19
;GPIO.c,40 :: 		case GPIO_PORTD: SET_BIT(PORTD, Pin); break;
L_GPIO_SetPinValue23:
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue76:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue77
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue76
L__GPIO_SetPinValue77:
	MOVF       R0+0, 0
	IORWF      PORTD+0, 1
	GOTO       L_GPIO_SetPinValue19
;GPIO.c,41 :: 		case GPIO_PORTE: SET_BIT(PORTE, Pin); break;
L_GPIO_SetPinValue24:
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue78:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue79
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue78
L__GPIO_SetPinValue79:
	MOVF       R0+0, 0
	IORWF      PORTE+0, 1
	GOTO       L_GPIO_SetPinValue19
;GPIO.c,42 :: 		}
L_GPIO_SetPinValue18:
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue20
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue21
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue22
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue23
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue24
L_GPIO_SetPinValue19:
;GPIO.c,43 :: 		}
	GOTO       L_GPIO_SetPinValue25
L_GPIO_SetPinValue17:
;GPIO.c,44 :: 		else if (Value == GPIO_LOW)
	MOVF       FARG_GPIO_SetPinValue_Value+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue26
;GPIO.c,46 :: 		switch (Port)
	GOTO       L_GPIO_SetPinValue27
;GPIO.c,48 :: 		case GPIO_PORTA: CLR_BIT(PORTA, Pin); break;
L_GPIO_SetPinValue29:
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue80:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue81
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue80
L__GPIO_SetPinValue81:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      PORTA+0, 1
	GOTO       L_GPIO_SetPinValue28
;GPIO.c,49 :: 		case GPIO_PORTB: CLR_BIT(PORTB, Pin); break;
L_GPIO_SetPinValue30:
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue82:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue83
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue82
L__GPIO_SetPinValue83:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      PORTB+0, 1
	GOTO       L_GPIO_SetPinValue28
;GPIO.c,50 :: 		case GPIO_PORTC: CLR_BIT(PORTC, Pin); break;
L_GPIO_SetPinValue31:
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue84:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue85
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue84
L__GPIO_SetPinValue85:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      PORTC+0, 1
	GOTO       L_GPIO_SetPinValue28
;GPIO.c,51 :: 		case GPIO_PORTD: CLR_BIT(PORTD, Pin); break;
L_GPIO_SetPinValue32:
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue86:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue87
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue86
L__GPIO_SetPinValue87:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      PORTD+0, 1
	GOTO       L_GPIO_SetPinValue28
;GPIO.c,52 :: 		case GPIO_PORTE: CLR_BIT(PORTE, Pin); break;
L_GPIO_SetPinValue33:
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue88:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue89
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue88
L__GPIO_SetPinValue89:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      PORTE+0, 1
	GOTO       L_GPIO_SetPinValue28
;GPIO.c,53 :: 		}
L_GPIO_SetPinValue27:
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue29
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue30
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue31
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue32
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue33
L_GPIO_SetPinValue28:
;GPIO.c,54 :: 		}
L_GPIO_SetPinValue26:
L_GPIO_SetPinValue25:
;GPIO.c,55 :: 		}
L_end_GPIO_SetPinValue:
	RETURN
; end of _GPIO_SetPinValue

_GPIO_TogglePinValue:

;GPIO.c,57 :: 		void GPIO_TogglePinValue(u8 Port, u8 Pin)
;GPIO.c,59 :: 		switch (Port)
	GOTO       L_GPIO_TogglePinValue34
;GPIO.c,61 :: 		case GPIO_PORTA: TOGGLE_BIT(PORTA, Pin); break;
L_GPIO_TogglePinValue36:
	MOVF       FARG_GPIO_TogglePinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_TogglePinValue91:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_TogglePinValue92
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_TogglePinValue91
L__GPIO_TogglePinValue92:
	MOVF       R0+0, 0
	XORWF      PORTA+0, 1
	GOTO       L_GPIO_TogglePinValue35
;GPIO.c,62 :: 		case GPIO_PORTB: TOGGLE_BIT(PORTB, Pin); break;
L_GPIO_TogglePinValue37:
	MOVF       FARG_GPIO_TogglePinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_TogglePinValue93:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_TogglePinValue94
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_TogglePinValue93
L__GPIO_TogglePinValue94:
	MOVF       R0+0, 0
	XORWF      PORTB+0, 1
	GOTO       L_GPIO_TogglePinValue35
;GPIO.c,63 :: 		case GPIO_PORTC: TOGGLE_BIT(PORTC, Pin); break;
L_GPIO_TogglePinValue38:
	MOVF       FARG_GPIO_TogglePinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_TogglePinValue95:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_TogglePinValue96
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_TogglePinValue95
L__GPIO_TogglePinValue96:
	MOVF       R0+0, 0
	XORWF      PORTC+0, 1
	GOTO       L_GPIO_TogglePinValue35
;GPIO.c,64 :: 		case GPIO_PORTD: TOGGLE_BIT(PORTD, Pin); break;
L_GPIO_TogglePinValue39:
	MOVF       FARG_GPIO_TogglePinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_TogglePinValue97:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_TogglePinValue98
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_TogglePinValue97
L__GPIO_TogglePinValue98:
	MOVF       R0+0, 0
	XORWF      PORTD+0, 1
	GOTO       L_GPIO_TogglePinValue35
;GPIO.c,65 :: 		case GPIO_PORTE: TOGGLE_BIT(PORTE, Pin); break;
L_GPIO_TogglePinValue40:
	MOVF       FARG_GPIO_TogglePinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_TogglePinValue99:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_TogglePinValue100
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_TogglePinValue99
L__GPIO_TogglePinValue100:
	MOVF       R0+0, 0
	XORWF      PORTE+0, 1
	GOTO       L_GPIO_TogglePinValue35
;GPIO.c,66 :: 		}
L_GPIO_TogglePinValue34:
	MOVF       FARG_GPIO_TogglePinValue_Port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_TogglePinValue36
	MOVF       FARG_GPIO_TogglePinValue_Port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_TogglePinValue37
	MOVF       FARG_GPIO_TogglePinValue_Port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_TogglePinValue38
	MOVF       FARG_GPIO_TogglePinValue_Port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_TogglePinValue39
	MOVF       FARG_GPIO_TogglePinValue_Port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_TogglePinValue40
L_GPIO_TogglePinValue35:
;GPIO.c,67 :: 		}
L_end_GPIO_TogglePinValue:
	RETURN
; end of _GPIO_TogglePinValue

_GPIO_GetPinValue:

;GPIO.c,69 :: 		u8 GPIO_GetPinValue(u8 Port, u8 Pin)
;GPIO.c,71 :: 		u8 PinValue = 0;
	CLRF       GPIO_GetPinValue_PinValue_L0+0
;GPIO.c,72 :: 		switch (Port)
	GOTO       L_GPIO_GetPinValue41
;GPIO.c,74 :: 		case GPIO_PORTA: PinValue = GET_BIT(PORTA, Pin); break;
L_GPIO_GetPinValue43:
	MOVF       FARG_GPIO_GetPinValue_Pin+0, 0
	MOVWF      R0+0
	MOVF       PORTA+0, 0
	MOVWF      GPIO_GetPinValue_PinValue_L0+0
	MOVF       R0+0, 0
L__GPIO_GetPinValue102:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_GetPinValue103
	RRF        GPIO_GetPinValue_PinValue_L0+0, 1
	BCF        GPIO_GetPinValue_PinValue_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_GetPinValue102
L__GPIO_GetPinValue103:
	MOVLW      1
	ANDWF      GPIO_GetPinValue_PinValue_L0+0, 1
	GOTO       L_GPIO_GetPinValue42
;GPIO.c,75 :: 		case GPIO_PORTB: PinValue = GET_BIT(PORTB, Pin); break;
L_GPIO_GetPinValue44:
	MOVF       FARG_GPIO_GetPinValue_Pin+0, 0
	MOVWF      R0+0
	MOVF       PORTB+0, 0
	MOVWF      GPIO_GetPinValue_PinValue_L0+0
	MOVF       R0+0, 0
L__GPIO_GetPinValue104:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_GetPinValue105
	RRF        GPIO_GetPinValue_PinValue_L0+0, 1
	BCF        GPIO_GetPinValue_PinValue_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_GetPinValue104
L__GPIO_GetPinValue105:
	MOVLW      1
	ANDWF      GPIO_GetPinValue_PinValue_L0+0, 1
	GOTO       L_GPIO_GetPinValue42
;GPIO.c,76 :: 		case GPIO_PORTC: PinValue = GET_BIT(PORTC, Pin); break;
L_GPIO_GetPinValue45:
	MOVF       FARG_GPIO_GetPinValue_Pin+0, 0
	MOVWF      R0+0
	MOVF       PORTC+0, 0
	MOVWF      GPIO_GetPinValue_PinValue_L0+0
	MOVF       R0+0, 0
L__GPIO_GetPinValue106:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_GetPinValue107
	RRF        GPIO_GetPinValue_PinValue_L0+0, 1
	BCF        GPIO_GetPinValue_PinValue_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_GetPinValue106
L__GPIO_GetPinValue107:
	MOVLW      1
	ANDWF      GPIO_GetPinValue_PinValue_L0+0, 1
	GOTO       L_GPIO_GetPinValue42
;GPIO.c,77 :: 		case GPIO_PORTD: PinValue = GET_BIT(PORTD, Pin); break;
L_GPIO_GetPinValue46:
	MOVF       FARG_GPIO_GetPinValue_Pin+0, 0
	MOVWF      R0+0
	MOVF       PORTD+0, 0
	MOVWF      GPIO_GetPinValue_PinValue_L0+0
	MOVF       R0+0, 0
L__GPIO_GetPinValue108:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_GetPinValue109
	RRF        GPIO_GetPinValue_PinValue_L0+0, 1
	BCF        GPIO_GetPinValue_PinValue_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_GetPinValue108
L__GPIO_GetPinValue109:
	MOVLW      1
	ANDWF      GPIO_GetPinValue_PinValue_L0+0, 1
	GOTO       L_GPIO_GetPinValue42
;GPIO.c,78 :: 		case GPIO_PORTE: PinValue = GET_BIT(PORTE, Pin); break;
L_GPIO_GetPinValue47:
	MOVF       FARG_GPIO_GetPinValue_Pin+0, 0
	MOVWF      R0+0
	MOVF       PORTE+0, 0
	MOVWF      GPIO_GetPinValue_PinValue_L0+0
	MOVF       R0+0, 0
L__GPIO_GetPinValue110:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_GetPinValue111
	RRF        GPIO_GetPinValue_PinValue_L0+0, 1
	BCF        GPIO_GetPinValue_PinValue_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_GetPinValue110
L__GPIO_GetPinValue111:
	MOVLW      1
	ANDWF      GPIO_GetPinValue_PinValue_L0+0, 1
	GOTO       L_GPIO_GetPinValue42
;GPIO.c,79 :: 		}
L_GPIO_GetPinValue41:
	MOVF       FARG_GPIO_GetPinValue_Port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPinValue43
	MOVF       FARG_GPIO_GetPinValue_Port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPinValue44
	MOVF       FARG_GPIO_GetPinValue_Port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPinValue45
	MOVF       FARG_GPIO_GetPinValue_Port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPinValue46
	MOVF       FARG_GPIO_GetPinValue_Port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPinValue47
L_GPIO_GetPinValue42:
;GPIO.c,80 :: 		return PinValue;
	MOVF       GPIO_GetPinValue_PinValue_L0+0, 0
	MOVWF      R0+0
;GPIO.c,81 :: 		}
L_end_GPIO_GetPinValue:
	RETURN
; end of _GPIO_GetPinValue
