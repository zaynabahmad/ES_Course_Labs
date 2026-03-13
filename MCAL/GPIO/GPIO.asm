
_GPIO_SetPinDirection:

;GPIO.c,6 :: 		void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction)
;GPIO.c,8 :: 		switch(Port)
	GOTO       L_GPIO_SetPinDirection0
;GPIO.c,10 :: 		case GPIO_PORTA:
L_GPIO_SetPinDirection2:
;GPIO.c,11 :: 		if(Direction == GPIO_OUTPUT) CLR_BIT(TRISA, Pin);
	MOVF       FARG_GPIO_SetPinDirection_Direction+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection3
	MOVF       FARG_GPIO_SetPinDirection_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection45:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection46
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection45
L__GPIO_SetPinDirection46:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      133, 1
	GOTO       L_GPIO_SetPinDirection4
L_GPIO_SetPinDirection3:
;GPIO.c,12 :: 		else SET_BIT(TRISA, Pin);
	MOVF       FARG_GPIO_SetPinDirection_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection47:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection48
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection47
L__GPIO_SetPinDirection48:
	MOVF       R0+0, 0
	IORWF      133, 1
L_GPIO_SetPinDirection4:
;GPIO.c,13 :: 		break;
	GOTO       L_GPIO_SetPinDirection1
;GPIO.c,14 :: 		case GPIO_PORTB:
L_GPIO_SetPinDirection5:
;GPIO.c,15 :: 		if(Direction == GPIO_OUTPUT) CLR_BIT(TRISB, Pin);
	MOVF       FARG_GPIO_SetPinDirection_Direction+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection6
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
	ANDWF      134, 1
	GOTO       L_GPIO_SetPinDirection7
L_GPIO_SetPinDirection6:
;GPIO.c,16 :: 		else SET_BIT(TRISB, Pin);
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
	MOVF       R0+0, 0
	IORWF      134, 1
L_GPIO_SetPinDirection7:
;GPIO.c,17 :: 		break;
	GOTO       L_GPIO_SetPinDirection1
;GPIO.c,18 :: 		case GPIO_PORTC:
L_GPIO_SetPinDirection8:
;GPIO.c,19 :: 		if(Direction == GPIO_OUTPUT) CLR_BIT(TRISC, Pin);
	MOVF       FARG_GPIO_SetPinDirection_Direction+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection9
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
	ANDWF      135, 1
	GOTO       L_GPIO_SetPinDirection10
L_GPIO_SetPinDirection9:
;GPIO.c,20 :: 		else SET_BIT(TRISC, Pin);
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
	MOVF       R0+0, 0
	IORWF      135, 1
L_GPIO_SetPinDirection10:
;GPIO.c,21 :: 		break;
	GOTO       L_GPIO_SetPinDirection1
;GPIO.c,22 :: 		case GPIO_PORTD:
L_GPIO_SetPinDirection11:
;GPIO.c,23 :: 		if(Direction == GPIO_OUTPUT) CLR_BIT(TRISD, Pin);
	MOVF       FARG_GPIO_SetPinDirection_Direction+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection12
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
	ANDWF      136, 1
	GOTO       L_GPIO_SetPinDirection13
L_GPIO_SetPinDirection12:
;GPIO.c,24 :: 		else SET_BIT(TRISD, Pin);
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
	IORWF      136, 1
L_GPIO_SetPinDirection13:
;GPIO.c,25 :: 		break;
	GOTO       L_GPIO_SetPinDirection1
;GPIO.c,26 :: 		case GPIO_PORTE:
L_GPIO_SetPinDirection14:
;GPIO.c,27 :: 		if(Direction == GPIO_OUTPUT) CLR_BIT(TRISE, Pin);
	MOVF       FARG_GPIO_SetPinDirection_Direction+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection15
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
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      137, 1
	GOTO       L_GPIO_SetPinDirection16
L_GPIO_SetPinDirection15:
;GPIO.c,28 :: 		else SET_BIT(TRISE, Pin);
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
	IORWF      137, 1
L_GPIO_SetPinDirection16:
;GPIO.c,29 :: 		break;
	GOTO       L_GPIO_SetPinDirection1
;GPIO.c,30 :: 		default: break;
L_GPIO_SetPinDirection17:
	GOTO       L_GPIO_SetPinDirection1
;GPIO.c,31 :: 		}
L_GPIO_SetPinDirection0:
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection2
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection5
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection8
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection11
	MOVF       FARG_GPIO_SetPinDirection_Port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection14
	GOTO       L_GPIO_SetPinDirection17
L_GPIO_SetPinDirection1:
;GPIO.c,32 :: 		}
L_end_GPIO_SetPinDirection:
	RETURN
; end of _GPIO_SetPinDirection

_GPIO_SetPinValue:

;GPIO.c,34 :: 		void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value)
;GPIO.c,36 :: 		switch(Port)
	GOTO       L_GPIO_SetPinValue18
;GPIO.c,38 :: 		case GPIO_PORTA:
L_GPIO_SetPinValue20:
;GPIO.c,39 :: 		if(Value == GPIO_HIGH) SET_BIT(PORTA, Pin);
	MOVF       FARG_GPIO_SetPinValue_Value+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue21
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue66:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue67
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue66
L__GPIO_SetPinValue67:
	MOVF       R0+0, 0
	IORWF      5, 1
	GOTO       L_GPIO_SetPinValue22
L_GPIO_SetPinValue21:
;GPIO.c,40 :: 		else CLR_BIT(PORTA, Pin);
	MOVF       FARG_GPIO_SetPinValue_Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinValue68:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinValue69
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinValue68
L__GPIO_SetPinValue69:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      5, 1
L_GPIO_SetPinValue22:
;GPIO.c,41 :: 		break;
	GOTO       L_GPIO_SetPinValue19
;GPIO.c,42 :: 		case GPIO_PORTB:
L_GPIO_SetPinValue23:
;GPIO.c,43 :: 		if(Value == GPIO_HIGH) SET_BIT(PORTB, Pin);
	MOVF       FARG_GPIO_SetPinValue_Value+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue24
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
	IORWF      6, 1
	GOTO       L_GPIO_SetPinValue25
L_GPIO_SetPinValue24:
;GPIO.c,44 :: 		else CLR_BIT(PORTB, Pin);
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
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      6, 1
L_GPIO_SetPinValue25:
;GPIO.c,45 :: 		break;
	GOTO       L_GPIO_SetPinValue19
;GPIO.c,46 :: 		case GPIO_PORTC:
L_GPIO_SetPinValue26:
;GPIO.c,47 :: 		if(Value == GPIO_HIGH) SET_BIT(PORTC, Pin);
	MOVF       FARG_GPIO_SetPinValue_Value+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue27
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
	IORWF      7, 1
	GOTO       L_GPIO_SetPinValue28
L_GPIO_SetPinValue27:
;GPIO.c,48 :: 		else CLR_BIT(PORTC, Pin);
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
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      7, 1
L_GPIO_SetPinValue28:
;GPIO.c,49 :: 		break;
	GOTO       L_GPIO_SetPinValue19
;GPIO.c,50 :: 		case GPIO_PORTD:
L_GPIO_SetPinValue29:
;GPIO.c,51 :: 		if(Value == GPIO_HIGH) SET_BIT(PORTD, Pin);
	MOVF       FARG_GPIO_SetPinValue_Value+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue30
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
	IORWF      8, 1
	GOTO       L_GPIO_SetPinValue31
L_GPIO_SetPinValue30:
;GPIO.c,52 :: 		else CLR_BIT(PORTD, Pin);
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
	ANDWF      8, 1
L_GPIO_SetPinValue31:
;GPIO.c,53 :: 		break;
	GOTO       L_GPIO_SetPinValue19
;GPIO.c,54 :: 		case GPIO_PORTE:
L_GPIO_SetPinValue32:
;GPIO.c,55 :: 		if(Value == GPIO_HIGH) SET_BIT(PORTE, Pin);
	MOVF       FARG_GPIO_SetPinValue_Value+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue33
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
	MOVF       R0+0, 0
	IORWF      9, 1
	GOTO       L_GPIO_SetPinValue34
L_GPIO_SetPinValue33:
;GPIO.c,56 :: 		else CLR_BIT(PORTE, Pin);
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
	ANDWF      9, 1
L_GPIO_SetPinValue34:
;GPIO.c,57 :: 		break;
	GOTO       L_GPIO_SetPinValue19
;GPIO.c,58 :: 		default: break;
L_GPIO_SetPinValue35:
	GOTO       L_GPIO_SetPinValue19
;GPIO.c,59 :: 		}
L_GPIO_SetPinValue18:
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue20
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue23
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue26
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue29
	MOVF       FARG_GPIO_SetPinValue_Port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinValue32
	GOTO       L_GPIO_SetPinValue35
L_GPIO_SetPinValue19:
;GPIO.c,60 :: 		}
L_end_GPIO_SetPinValue:
	RETURN
; end of _GPIO_SetPinValue

_GPIO_GetPinValue:

;GPIO.c,62 :: 		u8 GPIO_GetPinValue(u8 Port, u8 Pin)
;GPIO.c,64 :: 		u8 Local_Value = 0;
	CLRF       GPIO_GetPinValue_Local_Value_L0+0
;GPIO.c,65 :: 		switch(Port)
	GOTO       L_GPIO_GetPinValue36
;GPIO.c,67 :: 		case GPIO_PORTA: Local_Value = GET_BIT(PORTA, Pin); break;
L_GPIO_GetPinValue38:
	MOVF       FARG_GPIO_GetPinValue_Pin+0, 0
	MOVWF      R0+0
	MOVF       5, 0
	MOVWF      GPIO_GetPinValue_Local_Value_L0+0
	MOVF       R0+0, 0
L__GPIO_GetPinValue87:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_GetPinValue88
	RRF        GPIO_GetPinValue_Local_Value_L0+0, 1
	BCF        GPIO_GetPinValue_Local_Value_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_GetPinValue87
L__GPIO_GetPinValue88:
	MOVLW      1
	ANDWF      GPIO_GetPinValue_Local_Value_L0+0, 1
	GOTO       L_GPIO_GetPinValue37
;GPIO.c,68 :: 		case GPIO_PORTB: Local_Value = GET_BIT(PORTB, Pin); break;
L_GPIO_GetPinValue39:
	MOVF       FARG_GPIO_GetPinValue_Pin+0, 0
	MOVWF      R0+0
	MOVF       6, 0
	MOVWF      GPIO_GetPinValue_Local_Value_L0+0
	MOVF       R0+0, 0
L__GPIO_GetPinValue89:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_GetPinValue90
	RRF        GPIO_GetPinValue_Local_Value_L0+0, 1
	BCF        GPIO_GetPinValue_Local_Value_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_GetPinValue89
L__GPIO_GetPinValue90:
	MOVLW      1
	ANDWF      GPIO_GetPinValue_Local_Value_L0+0, 1
	GOTO       L_GPIO_GetPinValue37
;GPIO.c,69 :: 		case GPIO_PORTC: Local_Value = GET_BIT(PORTC, Pin); break;
L_GPIO_GetPinValue40:
	MOVF       FARG_GPIO_GetPinValue_Pin+0, 0
	MOVWF      R0+0
	MOVF       7, 0
	MOVWF      GPIO_GetPinValue_Local_Value_L0+0
	MOVF       R0+0, 0
L__GPIO_GetPinValue91:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_GetPinValue92
	RRF        GPIO_GetPinValue_Local_Value_L0+0, 1
	BCF        GPIO_GetPinValue_Local_Value_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_GetPinValue91
L__GPIO_GetPinValue92:
	MOVLW      1
	ANDWF      GPIO_GetPinValue_Local_Value_L0+0, 1
	GOTO       L_GPIO_GetPinValue37
;GPIO.c,70 :: 		case GPIO_PORTD: Local_Value = GET_BIT(PORTD, Pin); break;
L_GPIO_GetPinValue41:
	MOVF       FARG_GPIO_GetPinValue_Pin+0, 0
	MOVWF      R0+0
	MOVF       8, 0
	MOVWF      GPIO_GetPinValue_Local_Value_L0+0
	MOVF       R0+0, 0
L__GPIO_GetPinValue93:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_GetPinValue94
	RRF        GPIO_GetPinValue_Local_Value_L0+0, 1
	BCF        GPIO_GetPinValue_Local_Value_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_GetPinValue93
L__GPIO_GetPinValue94:
	MOVLW      1
	ANDWF      GPIO_GetPinValue_Local_Value_L0+0, 1
	GOTO       L_GPIO_GetPinValue37
;GPIO.c,71 :: 		case GPIO_PORTE: Local_Value = GET_BIT(PORTE, Pin); break;
L_GPIO_GetPinValue42:
	MOVF       FARG_GPIO_GetPinValue_Pin+0, 0
	MOVWF      R0+0
	MOVF       9, 0
	MOVWF      GPIO_GetPinValue_Local_Value_L0+0
	MOVF       R0+0, 0
L__GPIO_GetPinValue95:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_GetPinValue96
	RRF        GPIO_GetPinValue_Local_Value_L0+0, 1
	BCF        GPIO_GetPinValue_Local_Value_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_GetPinValue95
L__GPIO_GetPinValue96:
	MOVLW      1
	ANDWF      GPIO_GetPinValue_Local_Value_L0+0, 1
	GOTO       L_GPIO_GetPinValue37
;GPIO.c,72 :: 		default: break;
L_GPIO_GetPinValue43:
	GOTO       L_GPIO_GetPinValue37
;GPIO.c,73 :: 		}
L_GPIO_GetPinValue36:
	MOVF       FARG_GPIO_GetPinValue_Port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPinValue38
	MOVF       FARG_GPIO_GetPinValue_Port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPinValue39
	MOVF       FARG_GPIO_GetPinValue_Port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPinValue40
	MOVF       FARG_GPIO_GetPinValue_Port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPinValue41
	MOVF       FARG_GPIO_GetPinValue_Port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPinValue42
	GOTO       L_GPIO_GetPinValue43
L_GPIO_GetPinValue37:
;GPIO.c,74 :: 		return Local_Value;
	MOVF       GPIO_GetPinValue_Local_Value_L0+0, 0
	MOVWF      R0+0
;GPIO.c,75 :: 		}
L_end_GPIO_GetPinValue:
	RETURN
; end of _GPIO_GetPinValue

_GPIO_Init:

;GPIO.c,77 :: 		void GPIO_Init(void)
;GPIO.c,79 :: 		TRISA = GPIO_PORTA_DIR;
	CLRF       133
;GPIO.c,80 :: 		TRISB = GPIO_PORTB_DIR;
	MOVLW      255
	MOVWF      134
;GPIO.c,82 :: 		PORTA = GPIO_PORTA_INIT_VAL;
	CLRF       5
;GPIO.c,83 :: 		PORTB = GPIO_PORTB_INIT_VAL;
	CLRF       6
;GPIO.c,84 :: 		}
L_end_GPIO_Init:
	RETURN
; end of _GPIO_Init
