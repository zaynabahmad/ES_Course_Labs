
_GPIO_GetTRISRegister:

;gpio_impelemntation.c,3 :: 		volatile unsigned char* GPIO_GetTRISRegister(unsigned char port)
;gpio_impelemntation.c,5 :: 		switch(port)
	GOTO       L_GPIO_GetTRISRegister0
;gpio_impelemntation.c,7 :: 		case _PORTA: return &TRISA;
L_GPIO_GetTRISRegister2:
	MOVLW      TRISA+0
	MOVWF      R0+0
	GOTO       L_end_GPIO_GetTRISRegister
;gpio_impelemntation.c,8 :: 		case _PORTB: return &TRISB;
L_GPIO_GetTRISRegister3:
	MOVLW      TRISB+0
	MOVWF      R0+0
	GOTO       L_end_GPIO_GetTRISRegister
;gpio_impelemntation.c,9 :: 		case _PORTC: return &TRISC;
L_GPIO_GetTRISRegister4:
	MOVLW      TRISC+0
	MOVWF      R0+0
	GOTO       L_end_GPIO_GetTRISRegister
;gpio_impelemntation.c,10 :: 		case _PORTD: return &TRISD;
L_GPIO_GetTRISRegister5:
	MOVLW      TRISD+0
	MOVWF      R0+0
	GOTO       L_end_GPIO_GetTRISRegister
;gpio_impelemntation.c,11 :: 		case _PORTE: return &TRISE;
L_GPIO_GetTRISRegister6:
	MOVLW      TRISE+0
	MOVWF      R0+0
	GOTO       L_end_GPIO_GetTRISRegister
;gpio_impelemntation.c,12 :: 		default: return 0;
L_GPIO_GetTRISRegister7:
	CLRF       R0+0
	GOTO       L_end_GPIO_GetTRISRegister
;gpio_impelemntation.c,13 :: 		}
L_GPIO_GetTRISRegister0:
	MOVF       FARG_GPIO_GetTRISRegister_port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetTRISRegister2
	MOVF       FARG_GPIO_GetTRISRegister_port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetTRISRegister3
	MOVF       FARG_GPIO_GetTRISRegister_port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetTRISRegister4
	MOVF       FARG_GPIO_GetTRISRegister_port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetTRISRegister5
	MOVF       FARG_GPIO_GetTRISRegister_port+0, 0
	XORLW      5
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetTRISRegister6
	GOTO       L_GPIO_GetTRISRegister7
;gpio_impelemntation.c,14 :: 		}
L_end_GPIO_GetTRISRegister:
	RETURN
; end of _GPIO_GetTRISRegister

_GPIO_GetPORTRegister:

;gpio_impelemntation.c,16 :: 		volatile unsigned char* GPIO_GetPORTRegister(unsigned char port)
;gpio_impelemntation.c,18 :: 		switch(port)
	GOTO       L_GPIO_GetPORTRegister8
;gpio_impelemntation.c,20 :: 		case _PORTA: return &PORTA;
L_GPIO_GetPORTRegister10:
	MOVLW      PORTA+0
	MOVWF      R0+0
	GOTO       L_end_GPIO_GetPORTRegister
;gpio_impelemntation.c,21 :: 		case _PORTB: return &PORTB;
L_GPIO_GetPORTRegister11:
	MOVLW      PORTB+0
	MOVWF      R0+0
	GOTO       L_end_GPIO_GetPORTRegister
;gpio_impelemntation.c,22 :: 		case _PORTC: return &PORTC;
L_GPIO_GetPORTRegister12:
	MOVLW      PORTC+0
	MOVWF      R0+0
	GOTO       L_end_GPIO_GetPORTRegister
;gpio_impelemntation.c,23 :: 		case _PORTD: return &PORTD;
L_GPIO_GetPORTRegister13:
	MOVLW      PORTD+0
	MOVWF      R0+0
	GOTO       L_end_GPIO_GetPORTRegister
;gpio_impelemntation.c,24 :: 		case _PORTE: return &PORTE;
L_GPIO_GetPORTRegister14:
	MOVLW      PORTE+0
	MOVWF      R0+0
	GOTO       L_end_GPIO_GetPORTRegister
;gpio_impelemntation.c,25 :: 		default: return 0;
L_GPIO_GetPORTRegister15:
	CLRF       R0+0
	GOTO       L_end_GPIO_GetPORTRegister
;gpio_impelemntation.c,26 :: 		}
L_GPIO_GetPORTRegister8:
	MOVF       FARG_GPIO_GetPORTRegister_port+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPORTRegister10
	MOVF       FARG_GPIO_GetPORTRegister_port+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPORTRegister11
	MOVF       FARG_GPIO_GetPORTRegister_port+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPORTRegister12
	MOVF       FARG_GPIO_GetPORTRegister_port+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPORTRegister13
	MOVF       FARG_GPIO_GetPORTRegister_port+0, 0
	XORLW      5
	BTFSC      STATUS+0, 2
	GOTO       L_GPIO_GetPORTRegister14
	GOTO       L_GPIO_GetPORTRegister15
;gpio_impelemntation.c,27 :: 		}
L_end_GPIO_GetPORTRegister:
	RETURN
; end of _GPIO_GetPORTRegister

_GPIO_Init:

;gpio_impelemntation.c,31 :: 		void GPIO_Init(void)
;gpio_impelemntation.c,33 :: 		TRISA = 0xFF;
	MOVLW      255
	MOVWF      TRISA+0
;gpio_impelemntation.c,34 :: 		TRISB = 0xFF;
	MOVLW      255
	MOVWF      TRISB+0
;gpio_impelemntation.c,35 :: 		TRISC = 0xFF;
	MOVLW      255
	MOVWF      TRISC+0
;gpio_impelemntation.c,36 :: 		TRISD = 0xFF;
	MOVLW      255
	MOVWF      TRISD+0
;gpio_impelemntation.c,37 :: 		TRISE = 0xFF;
	MOVLW      255
	MOVWF      TRISE+0
;gpio_impelemntation.c,39 :: 		PORTA = 0x00;
	CLRF       PORTA+0
;gpio_impelemntation.c,40 :: 		PORTB = 0x00;
	CLRF       PORTB+0
;gpio_impelemntation.c,41 :: 		PORTC = 0x00;
	CLRF       PORTC+0
;gpio_impelemntation.c,42 :: 		PORTD = 0x00;
	CLRF       PORTD+0
;gpio_impelemntation.c,43 :: 		PORTE = 0x00;
	CLRF       PORTE+0
;gpio_impelemntation.c,45 :: 		ADCON1 = 0x06;
	MOVLW      6
	MOVWF      ADCON1+0
;gpio_impelemntation.c,46 :: 		}
L_end_GPIO_Init:
	RETURN
; end of _GPIO_Init

_setpindirection:

;gpio_impelemntation.c,48 :: 		void setpindirection(unsigned char port, unsigned char pin, bool direction)
;gpio_impelemntation.c,50 :: 		volatile unsigned char* TRIS_reg = GPIO_GetTRISRegister(port);
	MOVF       FARG_setpindirection_port+0, 0
	MOVWF      FARG_GPIO_GetTRISRegister_port+0
	CALL       _GPIO_GetTRISRegister+0
	MOVF       R0+0, 0
	MOVWF      setpindirection_TRIS_reg_L0+0
;gpio_impelemntation.c,51 :: 		if(TRIS_reg == 0) return;
	MOVF       R0+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_setpindirection16
	GOTO       L_end_setpindirection
L_setpindirection16:
;gpio_impelemntation.c,53 :: 		if(direction == OUTPUT)
	MOVF       FARG_setpindirection_direction+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_setpindirection17
;gpio_impelemntation.c,54 :: 		*TRIS_reg &= ~(1 << pin);
	MOVF       FARG_setpindirection_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__setpindirection27:
	BTFSC      STATUS+0, 2
	GOTO       L__setpindirection28
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__setpindirection27
L__setpindirection28:
	COMF       R0+0, 0
	MOVWF      R1+0
	MOVF       setpindirection_TRIS_reg_L0+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
	ANDWF      R0+0, 1
	MOVF       setpindirection_TRIS_reg_L0+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
	GOTO       L_setpindirection18
L_setpindirection17:
;gpio_impelemntation.c,56 :: 		*TRIS_reg |= (1 << pin);
	MOVF       FARG_setpindirection_pin+0, 0
	MOVWF      R0+0
	MOVLW      1
	MOVWF      R1+0
	MOVF       R0+0, 0
L__setpindirection29:
	BTFSC      STATUS+0, 2
	GOTO       L__setpindirection30
	RLF        R1+0, 1
	BCF        R1+0, 0
	ADDLW      255
	GOTO       L__setpindirection29
L__setpindirection30:
	MOVF       setpindirection_TRIS_reg_L0+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
	IORWF      R0+0, 1
	MOVF       setpindirection_TRIS_reg_L0+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
L_setpindirection18:
;gpio_impelemntation.c,57 :: 		}
L_end_setpindirection:
	RETURN
; end of _setpindirection

_setpinvalue:

;gpio_impelemntation.c,59 :: 		void setpinvalue(unsigned char port, unsigned char pin, bool value)
;gpio_impelemntation.c,61 :: 		volatile unsigned char* PORT_reg = GPIO_GetPORTRegister(port);
	MOVF       FARG_setpinvalue_port+0, 0
	MOVWF      FARG_GPIO_GetPORTRegister_port+0
	CALL       _GPIO_GetPORTRegister+0
	MOVF       R0+0, 0
	MOVWF      setpinvalue_PORT_reg_L0+0
;gpio_impelemntation.c,62 :: 		if(PORT_reg == 0) return;
	MOVF       R0+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_setpinvalue19
	GOTO       L_end_setpinvalue
L_setpinvalue19:
;gpio_impelemntation.c,64 :: 		if(value == HIGH)
	MOVF       FARG_setpinvalue_value+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_setpinvalue20
;gpio_impelemntation.c,65 :: 		*PORT_reg |= (1 << pin);
	MOVF       FARG_setpinvalue_pin+0, 0
	MOVWF      R0+0
	MOVLW      1
	MOVWF      R1+0
	MOVF       R0+0, 0
L__setpinvalue32:
	BTFSC      STATUS+0, 2
	GOTO       L__setpinvalue33
	RLF        R1+0, 1
	BCF        R1+0, 0
	ADDLW      255
	GOTO       L__setpinvalue32
L__setpinvalue33:
	MOVF       setpinvalue_PORT_reg_L0+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
	IORWF      R0+0, 1
	MOVF       setpinvalue_PORT_reg_L0+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
	GOTO       L_setpinvalue21
L_setpinvalue20:
;gpio_impelemntation.c,67 :: 		*PORT_reg &= ~(1 << pin);
	MOVF       FARG_setpinvalue_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__setpinvalue34:
	BTFSC      STATUS+0, 2
	GOTO       L__setpinvalue35
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__setpinvalue34
L__setpinvalue35:
	COMF       R0+0, 0
	MOVWF      R1+0
	MOVF       setpinvalue_PORT_reg_L0+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
	ANDWF      R0+0, 1
	MOVF       setpinvalue_PORT_reg_L0+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
L_setpinvalue21:
;gpio_impelemntation.c,68 :: 		}
L_end_setpinvalue:
	RETURN
; end of _setpinvalue

_getpinvalue:

;gpio_impelemntation.c,70 :: 		unsigned char getpinvalue(unsigned char port, unsigned char pin)
;gpio_impelemntation.c,72 :: 		volatile unsigned char* PORT_reg = GPIO_GetPORTRegister(port);
	MOVF       FARG_getpinvalue_port+0, 0
	MOVWF      FARG_GPIO_GetPORTRegister_port+0
	CALL       _GPIO_GetPORTRegister+0
	MOVF       R0+0, 0
	MOVWF      getpinvalue_PORT_reg_L0+0
;gpio_impelemntation.c,73 :: 		if(PORT_reg == 0) return 0;
	MOVF       R0+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_getpinvalue22
	CLRF       R0+0
	GOTO       L_end_getpinvalue
L_getpinvalue22:
;gpio_impelemntation.c,75 :: 		return ((*PORT_reg >> pin) & 0x01);
	MOVF       getpinvalue_PORT_reg_L0+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R2+0
	MOVF       FARG_getpinvalue_pin+0, 0
	MOVWF      R1+0
	MOVF       R2+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
L__getpinvalue37:
	BTFSC      STATUS+0, 2
	GOTO       L__getpinvalue38
	RRF        R0+0, 1
	BCF        R0+0, 7
	ADDLW      255
	GOTO       L__getpinvalue37
L__getpinvalue38:
	MOVLW      1
	ANDWF      R0+0, 1
;gpio_impelemntation.c,76 :: 		}
L_end_getpinvalue:
	RETURN
; end of _getpinvalue
