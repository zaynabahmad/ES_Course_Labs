
_GPIO_SetPinDirection:

;GPIO_program.c,7 :: 		void GPIO_SetPinDirection(uint8 port, uint8 pin, uint8 direction)
;GPIO_program.c,9 :: 		switch(port)
	GOTO       L_GPIO_SetPinDirection0
;GPIO_program.c,11 :: 		case GPIO_PORTA:
L_GPIO_SetPinDirection2:
;GPIO_program.c,12 :: 		if(direction == GPIO_INPUT)  SET_BIT(TRISA, pin);
	MOVF       FARG_GPIO_SetPinDirection_direction+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection3
	MOVF       FARG_GPIO_SetPinDirection_pin+0, 0
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
	MOVF       R0+0, 0
	IORWF      TRISA+0, 1
	GOTO       L_GPIO_SetPinDirection4
L_GPIO_SetPinDirection3:
;GPIO_program.c,13 :: 		else                         CLEAR_BIT(TRISA, pin);
	MOVF       FARG_GPIO_SetPinDirection_pin+0, 0
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
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      TRISA+0, 1
L_GPIO_SetPinDirection4:
;GPIO_program.c,14 :: 		break;
	GOTO       L_GPIO_SetPinDirection1
;GPIO_program.c,16 :: 		case GPIO_PORTB:
L_GPIO_SetPinDirection5:
;GPIO_program.c,17 :: 		if(direction == GPIO_INPUT)  SET_BIT(TRISB, pin);
	MOVF       FARG_GPIO_SetPinDirection_direction+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection6
	MOVF       FARG_GPIO_SetPinDirection_pin+0, 0
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
	MOVF       R0+0, 0
	IORWF      TRISB+0, 1
	GOTO       L_GPIO_SetPinDirection7
L_GPIO_SetPinDirection6:
;GPIO_program.c,18 :: 		else                         CLEAR_BIT(TRISB, pin);
	MOVF       FARG_GPIO_SetPinDirection_pin+0, 0
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
L_GPIO_SetPinDirection7:
;GPIO_program.c,19 :: 		break;
	GOTO       L_GPIO_SetPinDirection1
;GPIO_program.c,21 :: 		case GPIO_PORTC:
L_GPIO_SetPinDirection8:
;GPIO_program.c,22 :: 		if(direction == GPIO_INPUT)  SET_BIT(TRISC, pin);
	MOVF       FARG_GPIO_SetPinDirection_direction+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection9
	MOVF       FARG_GPIO_SetPinDirection_pin+0, 0
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
	MOVF       R0+0, 0
	IORWF      TRISC+0, 1
	GOTO       L_GPIO_SetPinDirection10
L_GPIO_SetPinDirection9:
;GPIO_program.c,23 :: 		else                         CLEAR_BIT(TRISC, pin);
	MOVF       FARG_GPIO_SetPinDirection_pin+0, 0
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
	ANDWF      TRISC+0, 1
L_GPIO_SetPinDirection10:
;GPIO_program.c,24 :: 		break;
	GOTO       L_GPIO_SetPinDirection1
;GPIO_program.c,26 :: 		case GPIO_PORTD:
L_GPIO_SetPinDirection11:
;GPIO_program.c,27 :: 		if(direction == GPIO_INPUT)  SET_BIT(TRISD, pin);
	MOVF       FARG_GPIO_SetPinDirection_direction+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection12
	MOVF       FARG_GPIO_SetPinDirection_pin+0, 0
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
	MOVF       R0+0, 0
	IORWF      TRISD+0, 1
	GOTO       L_GPIO_SetPinDirection13
L_GPIO_SetPinDirection12:
;GPIO_program.c,28 :: 		else                         CLEAR_BIT(TRISD, pin);
	MOVF       FARG_GPIO_SetPinDirection_pin+0, 0
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
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      TRISD+0, 1
L_GPIO_SetPinDirection13:
;GPIO_program.c,29 :: 		break;
	GOTO       L_GPIO_SetPinDirection1
;GPIO_program.c,31 :: 		case GPIO_PORTE:
L_GPIO_SetPinDirection14:
;GPIO_program.c,32 :: 		if(direction == GPIO_INPUT)  SET_BIT(TRISE, pin);
	MOVF       FARG_GPIO_SetPinDirection_direction+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection15
	MOVF       FARG_GPIO_SetPinDirection_pin+0, 0
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
	IORWF      TRISE+0, 1
	GOTO       L_GPIO_SetPinDirection16
L_GPIO_SetPinDirection15:
;GPIO_program.c,33 :: 		else                         CLEAR_BIT(TRISE, pin);
	MOVF       FARG_GPIO_SetPinDirection_pin+0, 0
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
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      TRISE+0, 1
L_GPIO_SetPinDirection16:
;GPIO_program.c,34 :: 		break;
	GOTO       L_GPIO_SetPinDirection1
;GPIO_program.c,36 :: 		default: break;
L_GPIO_SetPinDirection17:
	GOTO       L_GPIO_SetPinDirection1
;GPIO_program.c,37 :: 		}
L_GPIO_SetPinDirection0:
	MOVF       FARG_GPIO_SetPinDirection_port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection2
	MOVF       FARG_GPIO_SetPinDirection_port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection5
	MOVF       FARG_GPIO_SetPinDirection_port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection8
	MOVF       FARG_GPIO_SetPinDirection_port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection11
	MOVF       FARG_GPIO_SetPinDirection_port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection14
	GOTO       L_GPIO_SetPinDirection17
L_GPIO_SetPinDirection1:
;GPIO_program.c,38 :: 		}
L_end_GPIO_SetPinDirection:
	RETURN
; end of _GPIO_SetPinDirection

_GPIO_WritePin:

;GPIO_program.c,40 :: 		void GPIO_WritePin(uint8 port, uint8 pin, uint8 value)
;GPIO_program.c,42 :: 		switch(port)
	GOTO       L_GPIO_WritePin18
;GPIO_program.c,44 :: 		case GPIO_PORTA:
L_GPIO_WritePin20:
;GPIO_program.c,45 :: 		if(value == GPIO_HIGH)  SET_BIT(PORTA, pin);
	MOVF       FARG_GPIO_WritePin_value+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_WritePin21
	MOVF       FARG_GPIO_WritePin_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_WritePin66:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_WritePin67
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_WritePin66
L__GPIO_WritePin67:
	MOVF       R0+0, 0
	IORWF      PORTA+0, 1
	GOTO       L_GPIO_WritePin22
L_GPIO_WritePin21:
;GPIO_program.c,46 :: 		else                    CLEAR_BIT(PORTA, pin);
	MOVF       FARG_GPIO_WritePin_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_WritePin68:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_WritePin69
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_WritePin68
L__GPIO_WritePin69:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      PORTA+0, 1
L_GPIO_WritePin22:
;GPIO_program.c,47 :: 		break;
	GOTO       L_GPIO_WritePin19
;GPIO_program.c,49 :: 		case GPIO_PORTB:
L_GPIO_WritePin23:
;GPIO_program.c,50 :: 		if(value == GPIO_HIGH)  SET_BIT(PORTB, pin);
	MOVF       FARG_GPIO_WritePin_value+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_WritePin24
	MOVF       FARG_GPIO_WritePin_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_WritePin70:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_WritePin71
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_WritePin70
L__GPIO_WritePin71:
	MOVF       R0+0, 0
	IORWF      PORTB+0, 1
	GOTO       L_GPIO_WritePin25
L_GPIO_WritePin24:
;GPIO_program.c,51 :: 		else                    CLEAR_BIT(PORTB, pin);
	MOVF       FARG_GPIO_WritePin_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_WritePin72:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_WritePin73
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_WritePin72
L__GPIO_WritePin73:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      PORTB+0, 1
L_GPIO_WritePin25:
;GPIO_program.c,52 :: 		break;
	GOTO       L_GPIO_WritePin19
;GPIO_program.c,54 :: 		case GPIO_PORTC:
L_GPIO_WritePin26:
;GPIO_program.c,55 :: 		if(value == GPIO_HIGH)  SET_BIT(PORTC, pin);
	MOVF       FARG_GPIO_WritePin_value+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_WritePin27
	MOVF       FARG_GPIO_WritePin_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_WritePin74:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_WritePin75
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_WritePin74
L__GPIO_WritePin75:
	MOVF       R0+0, 0
	IORWF      PORTC+0, 1
	GOTO       L_GPIO_WritePin28
L_GPIO_WritePin27:
;GPIO_program.c,56 :: 		else                    CLEAR_BIT(PORTC, pin);
	MOVF       FARG_GPIO_WritePin_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_WritePin76:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_WritePin77
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_WritePin76
L__GPIO_WritePin77:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      PORTC+0, 1
L_GPIO_WritePin28:
;GPIO_program.c,57 :: 		break;
	GOTO       L_GPIO_WritePin19
;GPIO_program.c,59 :: 		case GPIO_PORTD:
L_GPIO_WritePin29:
;GPIO_program.c,60 :: 		if(value == GPIO_HIGH)  SET_BIT(PORTD, pin);
	MOVF       FARG_GPIO_WritePin_value+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_WritePin30
	MOVF       FARG_GPIO_WritePin_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_WritePin78:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_WritePin79
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_WritePin78
L__GPIO_WritePin79:
	MOVF       R0+0, 0
	IORWF      PORTD+0, 1
	GOTO       L_GPIO_WritePin31
L_GPIO_WritePin30:
;GPIO_program.c,61 :: 		else                    CLEAR_BIT(PORTD, pin);
	MOVF       FARG_GPIO_WritePin_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_WritePin80:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_WritePin81
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_WritePin80
L__GPIO_WritePin81:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      PORTD+0, 1
L_GPIO_WritePin31:
;GPIO_program.c,62 :: 		break;
	GOTO       L_GPIO_WritePin19
;GPIO_program.c,64 :: 		case GPIO_PORTE:
L_GPIO_WritePin32:
;GPIO_program.c,65 :: 		if(value == GPIO_HIGH)  SET_BIT(PORTE, pin);
	MOVF       FARG_GPIO_WritePin_value+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_WritePin33
	MOVF       FARG_GPIO_WritePin_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_WritePin82:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_WritePin83
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_WritePin82
L__GPIO_WritePin83:
	MOVF       R0+0, 0
	IORWF      PORTE+0, 1
	GOTO       L_GPIO_WritePin34
L_GPIO_WritePin33:
;GPIO_program.c,66 :: 		else                    CLEAR_BIT(PORTE, pin);
	MOVF       FARG_GPIO_WritePin_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_WritePin84:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_WritePin85
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_WritePin84
L__GPIO_WritePin85:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      PORTE+0, 1
L_GPIO_WritePin34:
;GPIO_program.c,67 :: 		break;
	GOTO       L_GPIO_WritePin19
;GPIO_program.c,69 :: 		default: break;
L_GPIO_WritePin35:
	GOTO       L_GPIO_WritePin19
;GPIO_program.c,70 :: 		}
L_GPIO_WritePin18:
	MOVF       FARG_GPIO_WritePin_port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_WritePin20
	MOVF       FARG_GPIO_WritePin_port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_WritePin23
	MOVF       FARG_GPIO_WritePin_port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_WritePin26
	MOVF       FARG_GPIO_WritePin_port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_WritePin29
	MOVF       FARG_GPIO_WritePin_port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_WritePin32
	GOTO       L_GPIO_WritePin35
L_GPIO_WritePin19:
;GPIO_program.c,71 :: 		}
L_end_GPIO_WritePin:
	RETURN
; end of _GPIO_WritePin

_GPIO_ReadPin:

;GPIO_program.c,73 :: 		uint8 GPIO_ReadPin(uint8 port, uint8 pin)
;GPIO_program.c,75 :: 		uint8 val = GPIO_LOW;
	CLRF       GPIO_ReadPin_val_L0+0
;GPIO_program.c,77 :: 		switch(port)
	GOTO       L_GPIO_ReadPin36
;GPIO_program.c,79 :: 		case GPIO_PORTA: val = READ_BIT(PORTA, pin); break;
L_GPIO_ReadPin38:
	MOVF       FARG_GPIO_ReadPin_pin+0, 0
	MOVWF      R0+0
	MOVF       PORTA+0, 0
	MOVWF      GPIO_ReadPin_val_L0+0
	MOVF       R0+0, 0
L__GPIO_ReadPin87:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_ReadPin88
	RRF        GPIO_ReadPin_val_L0+0, 1
	BCF        GPIO_ReadPin_val_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_ReadPin87
L__GPIO_ReadPin88:
	MOVLW      1
	ANDWF      GPIO_ReadPin_val_L0+0, 1
	GOTO       L_GPIO_ReadPin37
;GPIO_program.c,80 :: 		case GPIO_PORTB: val = READ_BIT(PORTB, pin); break;
L_GPIO_ReadPin39:
	MOVF       FARG_GPIO_ReadPin_pin+0, 0
	MOVWF      R0+0
	MOVF       PORTB+0, 0
	MOVWF      GPIO_ReadPin_val_L0+0
	MOVF       R0+0, 0
L__GPIO_ReadPin89:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_ReadPin90
	RRF        GPIO_ReadPin_val_L0+0, 1
	BCF        GPIO_ReadPin_val_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_ReadPin89
L__GPIO_ReadPin90:
	MOVLW      1
	ANDWF      GPIO_ReadPin_val_L0+0, 1
	GOTO       L_GPIO_ReadPin37
;GPIO_program.c,81 :: 		case GPIO_PORTC: val = READ_BIT(PORTC, pin); break;
L_GPIO_ReadPin40:
	MOVF       FARG_GPIO_ReadPin_pin+0, 0
	MOVWF      R0+0
	MOVF       PORTC+0, 0
	MOVWF      GPIO_ReadPin_val_L0+0
	MOVF       R0+0, 0
L__GPIO_ReadPin91:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_ReadPin92
	RRF        GPIO_ReadPin_val_L0+0, 1
	BCF        GPIO_ReadPin_val_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_ReadPin91
L__GPIO_ReadPin92:
	MOVLW      1
	ANDWF      GPIO_ReadPin_val_L0+0, 1
	GOTO       L_GPIO_ReadPin37
;GPIO_program.c,82 :: 		case GPIO_PORTD: val = READ_BIT(PORTD, pin); break;
L_GPIO_ReadPin41:
	MOVF       FARG_GPIO_ReadPin_pin+0, 0
	MOVWF      R0+0
	MOVF       PORTD+0, 0
	MOVWF      GPIO_ReadPin_val_L0+0
	MOVF       R0+0, 0
L__GPIO_ReadPin93:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_ReadPin94
	RRF        GPIO_ReadPin_val_L0+0, 1
	BCF        GPIO_ReadPin_val_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_ReadPin93
L__GPIO_ReadPin94:
	MOVLW      1
	ANDWF      GPIO_ReadPin_val_L0+0, 1
	GOTO       L_GPIO_ReadPin37
;GPIO_program.c,83 :: 		case GPIO_PORTE: val = READ_BIT(PORTE, pin); break;
L_GPIO_ReadPin42:
	MOVF       FARG_GPIO_ReadPin_pin+0, 0
	MOVWF      R0+0
	MOVF       PORTE+0, 0
	MOVWF      GPIO_ReadPin_val_L0+0
	MOVF       R0+0, 0
L__GPIO_ReadPin95:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_ReadPin96
	RRF        GPIO_ReadPin_val_L0+0, 1
	BCF        GPIO_ReadPin_val_L0+0, 7
	ADDLW      255
	GOTO       L__GPIO_ReadPin95
L__GPIO_ReadPin96:
	MOVLW      1
	ANDWF      GPIO_ReadPin_val_L0+0, 1
	GOTO       L_GPIO_ReadPin37
;GPIO_program.c,84 :: 		default: break;
L_GPIO_ReadPin43:
	GOTO       L_GPIO_ReadPin37
;GPIO_program.c,85 :: 		}
L_GPIO_ReadPin36:
	MOVF       FARG_GPIO_ReadPin_port+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_ReadPin38
	MOVF       FARG_GPIO_ReadPin_port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_ReadPin39
	MOVF       FARG_GPIO_ReadPin_port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_ReadPin40
	MOVF       FARG_GPIO_ReadPin_port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_ReadPin41
	MOVF       FARG_GPIO_ReadPin_port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_ReadPin42
	GOTO       L_GPIO_ReadPin43
L_GPIO_ReadPin37:
;GPIO_program.c,87 :: 		return val;
	MOVF       GPIO_ReadPin_val_L0+0, 0
	MOVWF      R0+0
;GPIO_program.c,88 :: 		}
L_end_GPIO_ReadPin:
	RETURN
; end of _GPIO_ReadPin
