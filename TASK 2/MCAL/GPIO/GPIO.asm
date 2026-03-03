
_GPIO_SetPinDirection:

;GPIO.c,3 :: 		void GPIO_SetPinDirection(char port, char pin, char direction)
;GPIO.c,5 :: 		if(port == 'A')
	MOVF       FARG_GPIO_SetPinDirection_port+0, 0
	XORLW      65
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection0
;GPIO.c,7 :: 		if(direction == INPUT)
	MOVF       FARG_GPIO_SetPinDirection_direction+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection1
;GPIO.c,8 :: 		TRISA |= (1 << pin);
	MOVF       FARG_GPIO_SetPinDirection_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection12:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection13
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection12
L__GPIO_SetPinDirection13:
	MOVF       R0+0, 0
	IORWF      TRISA+0, 1
	GOTO       L_GPIO_SetPinDirection2
L_GPIO_SetPinDirection1:
;GPIO.c,10 :: 		TRISA &= ~(1 << pin);
	MOVF       FARG_GPIO_SetPinDirection_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection14:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection15
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection14
L__GPIO_SetPinDirection15:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      TRISA+0, 1
L_GPIO_SetPinDirection2:
;GPIO.c,11 :: 		}
	GOTO       L_GPIO_SetPinDirection3
L_GPIO_SetPinDirection0:
;GPIO.c,13 :: 		else if(port == 'B')
	MOVF       FARG_GPIO_SetPinDirection_port+0, 0
	XORLW      66
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection4
;GPIO.c,15 :: 		if(direction == INPUT)
	MOVF       FARG_GPIO_SetPinDirection_direction+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_SetPinDirection5
;GPIO.c,16 :: 		TRISB |= (1 << pin);
	MOVF       FARG_GPIO_SetPinDirection_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection16:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection17
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection16
L__GPIO_SetPinDirection17:
	MOVF       R0+0, 0
	IORWF      TRISB+0, 1
	GOTO       L_GPIO_SetPinDirection6
L_GPIO_SetPinDirection5:
;GPIO.c,18 :: 		TRISB &= ~(1 << pin);
	MOVF       FARG_GPIO_SetPinDirection_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_SetPinDirection18:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_SetPinDirection19
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_SetPinDirection18
L__GPIO_SetPinDirection19:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      TRISB+0, 1
L_GPIO_SetPinDirection6:
;GPIO.c,19 :: 		}
L_GPIO_SetPinDirection4:
L_GPIO_SetPinDirection3:
;GPIO.c,20 :: 		}
L_end_GPIO_SetPinDirection:
	RETURN
; end of _GPIO_SetPinDirection

_GPIO_WritePin:

;GPIO.c,22 :: 		void GPIO_WritePin(char port, char pin, char value)
;GPIO.c,24 :: 		if(port == 'B')
	MOVF       FARG_GPIO_WritePin_port+0, 0
	XORLW      66
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_WritePin7
;GPIO.c,26 :: 		if(value == HIGH)
	MOVF       FARG_GPIO_WritePin_value+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_WritePin8
;GPIO.c,27 :: 		PORTB |= (1 << pin);
	MOVF       FARG_GPIO_WritePin_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_WritePin21:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_WritePin22
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_WritePin21
L__GPIO_WritePin22:
	MOVF       R0+0, 0
	IORWF      PORTB+0, 1
	GOTO       L_GPIO_WritePin9
L_GPIO_WritePin8:
;GPIO.c,29 :: 		PORTB &= ~(1 << pin);
	MOVF       FARG_GPIO_WritePin_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_WritePin23:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_WritePin24
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__GPIO_WritePin23
L__GPIO_WritePin24:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      PORTB+0, 1
L_GPIO_WritePin9:
;GPIO.c,30 :: 		}
L_GPIO_WritePin7:
;GPIO.c,31 :: 		}
L_end_GPIO_WritePin:
	RETURN
; end of _GPIO_WritePin

_GPIO_ReadPin:

;GPIO.c,33 :: 		char GPIO_ReadPin(char port, char pin)
;GPIO.c,35 :: 		if(port == 'A')
	MOVF       FARG_GPIO_ReadPin_port+0, 0
	XORLW      65
	BTFSS      STATUS+0, 2
	GOTO       L_GPIO_ReadPin10
;GPIO.c,36 :: 		return (PORTA >> pin) & 1;   // ? THIS IS CORRECT FOR PIC
	MOVF       FARG_GPIO_ReadPin_pin+0, 0
	MOVWF      R1+0
	MOVF       PORTA+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
L__GPIO_ReadPin26:
	BTFSC      STATUS+0, 2
	GOTO       L__GPIO_ReadPin27
	RRF        R0+0, 1
	BCF        R0+0, 7
	ADDLW      255
	GOTO       L__GPIO_ReadPin26
L__GPIO_ReadPin27:
	MOVLW      1
	ANDWF      R0+0, 1
	GOTO       L_end_GPIO_ReadPin
L_GPIO_ReadPin10:
;GPIO.c,38 :: 		return 0;
	CLRF       R0+0
;GPIO.c,39 :: 		}
L_end_GPIO_ReadPin:
	RETURN
; end of _GPIO_ReadPin
