
_GPIO_SetPinDirection:

;GPIO.c,5 :: 		void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction){
;GPIO.c,6 :: 		switch(Port){
	GOTO       L_GPIO_SetPinDirection0
;GPIO.c,7 :: 		case GPIO_PORTA: TRISA |= (Direction << Pin); break;
L_GPIO_SetPinDirection2:
	MOVF       FARG_GPIO_SetPinDirection_Pin+0, 0
	MOVWF      R1+0
	MOVF       FARG_GPIO_SetPinDirection_Direction+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection32:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection33
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection32
L__GPIO_SetPinDirection33:
	MOVF       R0+0, 0
	IORWF      TRISA+0, 1
	GOTO       L_GPIO_SetPinDirection1
;GPIO.c,8 :: 		case GPIO_PORTB: TRISB |= (Direction << Pin); break;
L_GPIO_SetPinDirection3:
	MOVF       FARG_GPIO_SetPinDirection_Pin+0, 0
	MOVWF      R1+0
	MOVF       FARG_GPIO_SetPinDirection_Direction+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection34:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection35
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection34
L__GPIO_SetPinDirection35:
	MOVF       R0+0, 0
	IORWF      TRISB+0, 1
	GOTO       L_GPIO_SetPinDirection1
;GPIO.c,9 :: 		case GPIO_PORTC: TRISC |= (Direction << Pin); break;
L_GPIO_SetPinDirection4:
	MOVF       FARG_GPIO_SetPinDirection_Pin+0, 0
	MOVWF      R1+0
	MOVF       FARG_GPIO_SetPinDirection_Direction+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection36:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection37
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection36
L__GPIO_SetPinDirection37:
	MOVF       R0+0, 0
	IORWF      TRISC+0, 1
	GOTO       L_GPIO_SetPinDirection1
;GPIO.c,10 :: 		case GPIO_PORTD: TRISD |= (Direction << Pin); break;
L_GPIO_SetPinDirection5:
	MOVF       FARG_GPIO_SetPinDirection_Pin+0, 0
	MOVWF      R1+0
	MOVF       FARG_GPIO_SetPinDirection_Direction+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection38:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection39
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection38
L__GPIO_SetPinDirection39:
	MOVF       R0+0, 0
	IORWF      TRISD+0, 1
	GOTO       L_GPIO_SetPinDirection1
;GPIO.c,11 :: 		case GPIO_PORTE: TRISE |= (Direction << Pin); break;
L_GPIO_SetPinDirection6:
	MOVF       FARG_GPIO_SetPinDirection_Pin+0, 0
	MOVWF      R1+0
	MOVF       FARG_GPIO_SetPinDirection_Direction+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection40:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection41
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection40
L__GPIO_SetPinDirection41:
	MOVF       R0+0, 0
	IORWF      TRISE+0, 1
	GOTO       L_GPIO_SetPinDirection1
;GPIO.c,12 :: 		}
L_GPIO_SetPinDirection0:
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection2
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection3
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection4
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection5
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection6
L_GPIO_SetPinDirection1:
;GPIO.c,13 :: 		}
L_end_GPIO_SetPinDirection:
	RETURN
; end of _GPIO_SetPinDirection

_GPIO_SetPinValue:

;GPIO.c,15 :: 		void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value){
;GPIO.c,16 :: 		switch(Port){
	GOTO       L_GPIO_SetPinValue7
;GPIO.c,17 :: 		case GPIO_PORTA:
L_GPIO_SetPinValue9:
;GPIO.c,18 :: 		if(Value) PORTA |= (1 << Pin);
	MOVF       FARG_GPIO_SetPinValue_Value+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue10
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue43:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue44
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue43
L__GPIO_SetPinValue44:
	MOVF       R0+0, 0
	IORWF      PORTA+0, 1
	GOTO       L_GPIO_SetPinValue11
L_GPIO_SetPinValue10:
;GPIO.c,19 :: 		else PORTA &= ~(1 << Pin);
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue45:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue46
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue45
L__GPIO_SetPinValue46:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      PORTA+0, 1
L_GPIO_SetPinValue11:
;GPIO.c,20 :: 		break;
	GOTO       L_GPIO_SetPinValue8
;GPIO.c,21 :: 		case GPIO_PORTB:
L_GPIO_SetPinValue12:
;GPIO.c,22 :: 		if(Value) PORTB |= (1 << Pin);
	MOVF       FARG_GPIO_SetPinValue_Value+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue13
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue47:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue48
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue47
L__GPIO_SetPinValue48:
	MOVF       R0+0, 0
	IORWF      PORTB+0, 1
	GOTO       L_GPIO_SetPinValue14
L_GPIO_SetPinValue13:
;GPIO.c,23 :: 		else PORTB &= ~(1 << Pin);
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue49:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue50
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue49
L__GPIO_SetPinValue50:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      PORTB+0, 1
L_GPIO_SetPinValue14:
;GPIO.c,24 :: 		break;
	GOTO       L_GPIO_SetPinValue8
;GPIO.c,25 :: 		case GPIO_PORTC:
L_GPIO_SetPinValue15:
;GPIO.c,26 :: 		if(Value) PORTC |= (1 << Pin);
	MOVF       FARG_GPIO_SetPinValue_Value+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue16
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue51:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue52
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue51
L__GPIO_SetPinValue52:
	MOVF       R0+0, 0
	IORWF      PORTC+0, 1
	GOTO       L_GPIO_SetPinValue17
L_GPIO_SetPinValue16:
;GPIO.c,27 :: 		else PORTC &= ~(1 << Pin);
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue53:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue54
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue53
L__GPIO_SetPinValue54:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      PORTC+0, 1
L_GPIO_SetPinValue17:
;GPIO.c,28 :: 		break;
	GOTO       L_GPIO_SetPinValue8
;GPIO.c,29 :: 		case GPIO_PORTD:
L_GPIO_SetPinValue18:
;GPIO.c,30 :: 		if(Value) PORTD |= (1 << Pin);
	MOVF       FARG_GPIO_SetPinValue_Value+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue19
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue55:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue56
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue55
L__GPIO_SetPinValue56:
	MOVF       R0+0, 0
	IORWF      PORTD+0, 1
	GOTO       L_GPIO_SetPinValue20
L_GPIO_SetPinValue19:
;GPIO.c,31 :: 		else PORTD &= ~(1 << Pin);
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue57:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue58
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue57
L__GPIO_SetPinValue58:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      PORTD+0, 1
L_GPIO_SetPinValue20:
;GPIO.c,32 :: 		break;
	GOTO       L_GPIO_SetPinValue8
;GPIO.c,33 :: 		case GPIO_PORTE:
L_GPIO_SetPinValue21:
;GPIO.c,34 :: 		if(Value) PORTE |= (1 << Pin);
	MOVF       FARG_GPIO_SetPinValue_Value+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue22
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue59:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue60
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue59
L__GPIO_SetPinValue60:
	MOVF       R0+0, 0
	IORWF      PORTE+0, 1
	GOTO       L_GPIO_SetPinValue23
L_GPIO_SetPinValue22:
;GPIO.c,35 :: 		else PORTE &= ~(1 << Pin);
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue61:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue62
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue61
L__GPIO_SetPinValue62:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      PORTE+0, 1
L_GPIO_SetPinValue23:
;GPIO.c,36 :: 		break;
	GOTO       L_GPIO_SetPinValue8
;GPIO.c,37 :: 		}
L_GPIO_SetPinValue7:
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue9
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue12
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue15
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue18
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue21
L_GPIO_SetPinValue8:
;GPIO.c,38 :: 		}
L_end_GPIO_SetPinValue:
	RETURN
; end of _GPIO_SetPinValue

_GPIO_GetPinValue:

;GPIO.c,40 :: 		u8 GPIO_GetPinValue(u8 Port, u8 Pin){
;GPIO.c,41 :: 		u8 val = 0;
	CLRF       GPIO_GetPinValue_val_L0+0
;GPIO.c,42 :: 		switch(Port){
	GOTO       L_GPIO_GetPinValue24
;GPIO.c,43 :: 		case GPIO_PORTA: val = (PORTA >> Pin) & 1; break;
L_GPIO_GetPinValue26:
	MOVF       FARG_GPIO_GetPinValue_Pin+0, 0
	MOVWF      R0+0
	MOVF       PORTA+0, 0
	MOVWF      GPIO_GetPinValue_val_L0+0
	MOVF       R0+0, 0
L__GPIO_GetPinValue64:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_GetPinValue65
	RRF        GPIO_GetPinValue_val_L0+0, 1
	BCF        GPIO_GetPinValue_val_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_GetPinValue64
L__GPIO_GetPinValue65:
	MOVLW      1
	ANDWF      GPIO_GetPinValue_val_L0+0, 1
	GOTO       L_GPIO_GetPinValue25
;GPIO.c,44 :: 		case GPIO_PORTB: val = (PORTB >> Pin) & 1; break;
L_GPIO_GetPinValue27:
	MOVF       FARG_GPIO_GetPinValue_Pin+0, 0
	MOVWF      R0+0
	MOVF       PORTB+0, 0
	MOVWF      GPIO_GetPinValue_val_L0+0
	MOVF       R0+0, 0
L__GPIO_GetPinValue66:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_GetPinValue67
	RRF        GPIO_GetPinValue_val_L0+0, 1
	BCF        GPIO_GetPinValue_val_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_GetPinValue66
L__GPIO_GetPinValue67:
	MOVLW      1
	ANDWF      GPIO_GetPinValue_val_L0+0, 1
	GOTO       L_GPIO_GetPinValue25
;GPIO.c,45 :: 		case GPIO_PORTC: val = (PORTC >> Pin) & 1; break;
L_GPIO_GetPinValue28:
	MOVF       FARG_GPIO_GetPinValue_Pin+0, 0
	MOVWF      R0+0
	MOVF       PORTC+0, 0
	MOVWF      GPIO_GetPinValue_val_L0+0
	MOVF       R0+0, 0
L__GPIO_GetPinValue68:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_GetPinValue69
	RRF        GPIO_GetPinValue_val_L0+0, 1
	BCF        GPIO_GetPinValue_val_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_GetPinValue68
L__GPIO_GetPinValue69:
	MOVLW      1
	ANDWF      GPIO_GetPinValue_val_L0+0, 1
	GOTO       L_GPIO_GetPinValue25
;GPIO.c,46 :: 		case GPIO_PORTD: val = (PORTD >> Pin) & 1; break;
L_GPIO_GetPinValue29:
	MOVF       FARG_GPIO_GetPinValue_Pin+0, 0
	MOVWF      R0+0
	MOVF       PORTD+0, 0
	MOVWF      GPIO_GetPinValue_val_L0+0
	MOVF       R0+0, 0
L__GPIO_GetPinValue70:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_GetPinValue71
	RRF        GPIO_GetPinValue_val_L0+0, 1
	BCF        GPIO_GetPinValue_val_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_GetPinValue70
L__GPIO_GetPinValue71:
	MOVLW      1
	ANDWF      GPIO_GetPinValue_val_L0+0, 1
	GOTO       L_GPIO_GetPinValue25
;GPIO.c,47 :: 		case GPIO_PORTE: val = (PORTE >> Pin) & 1; break;
L_GPIO_GetPinValue30:
	MOVF       FARG_GPIO_GetPinValue_Pin+0, 0
	MOVWF      R0+0
	MOVF       PORTE+0, 0
	MOVWF      GPIO_GetPinValue_val_L0+0
	MOVF       R0+0, 0
L__GPIO_GetPinValue72:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_GetPinValue73
	RRF        GPIO_GetPinValue_val_L0+0, 1
	BCF        GPIO_GetPinValue_val_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_GetPinValue72
L__GPIO_GetPinValue73:
	MOVLW      1
	ANDWF      GPIO_GetPinValue_val_L0+0, 1
	GOTO       L_GPIO_GetPinValue25
;GPIO.c,48 :: 		}
L_GPIO_GetPinValue24:
	MOVF       FARG_GPIO_GetPinValue_Port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPinValue26
	MOVF       FARG_GPIO_GetPinValue_Port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPinValue27
	MOVF       FARG_GPIO_GetPinValue_Port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPinValue28
	MOVF       FARG_GPIO_GetPinValue_Port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPinValue29
	MOVF       FARG_GPIO_GetPinValue_Port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPinValue30
L_GPIO_GetPinValue25:
;GPIO.c,49 :: 		return val;
	MOVF       GPIO_GetPinValue_val_L0+0, 0
	MOVWF      R0+0
;GPIO.c,50 :: 		}
L_end_GPIO_GetPinValue:
	RETURN
; end of _GPIO_GetPinValue
