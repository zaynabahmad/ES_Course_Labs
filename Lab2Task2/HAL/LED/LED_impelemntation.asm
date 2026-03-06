
_LED_Init:

;LED_impelemntation.c,4 :: 		unsigned char port2, unsigned char pin2)
;LED_impelemntation.c,6 :: 		setpindirection(port1, pin1, OUTPUT);
	MOVF       FARG_LED_Init_port1+0, 0
	MOVWF      FARG_setpindirection_port+0
	MOVF       FARG_LED_Init_pin1+0, 0
	MOVWF      FARG_setpindirection_pin+0
	CLRF       FARG_setpindirection_direction+0
	CALL       _setpindirection+0
;LED_impelemntation.c,7 :: 		setpindirection(port2, pin2, OUTPUT);
	MOVF       FARG_LED_Init_port2+0, 0
	MOVWF      FARG_setpindirection_port+0
	MOVF       FARG_LED_Init_pin2+0, 0
	MOVWF      FARG_setpindirection_pin+0
	CLRF       FARG_setpindirection_direction+0
	CALL       _setpindirection+0
;LED_impelemntation.c,9 :: 		setpinvalue(port1, pin1, LOW);
	MOVF       FARG_LED_Init_port1+0, 0
	MOVWF      FARG_setpinvalue_port+0
	MOVF       FARG_LED_Init_pin1+0, 0
	MOVWF      FARG_setpinvalue_pin+0
	CLRF       FARG_setpinvalue_value+0
	CALL       _setpinvalue+0
;LED_impelemntation.c,10 :: 		setpinvalue(port2, pin2, LOW);
	MOVF       FARG_LED_Init_port2+0, 0
	MOVWF      FARG_setpinvalue_port+0
	MOVF       FARG_LED_Init_pin2+0, 0
	MOVWF      FARG_setpinvalue_pin+0
	CLRF       FARG_setpinvalue_value+0
	CALL       _setpinvalue+0
;LED_impelemntation.c,11 :: 		}
L_end_LED_Init:
	RETURN
; end of _LED_Init

_LED_On:

;LED_impelemntation.c,13 :: 		void LED_On(unsigned char port, unsigned char pin)
;LED_impelemntation.c,15 :: 		setpinvalue(port, pin, HIGH);
	MOVF       FARG_LED_On_port+0, 0
	MOVWF      FARG_setpinvalue_port+0
	MOVF       FARG_LED_On_pin+0, 0
	MOVWF      FARG_setpinvalue_pin+0
	MOVLW      1
	MOVWF      FARG_setpinvalue_value+0
	CALL       _setpinvalue+0
;LED_impelemntation.c,16 :: 		}
L_end_LED_On:
	RETURN
; end of _LED_On

_LED_Off:

;LED_impelemntation.c,18 :: 		void LED_Off(unsigned char port, unsigned char pin)
;LED_impelemntation.c,20 :: 		setpinvalue(port, pin, LOW);
	MOVF       FARG_LED_Off_port+0, 0
	MOVWF      FARG_setpinvalue_port+0
	MOVF       FARG_LED_Off_pin+0, 0
	MOVWF      FARG_setpinvalue_pin+0
	CLRF       FARG_setpinvalue_value+0
	CALL       _setpinvalue+0
;LED_impelemntation.c,21 :: 		}
L_end_LED_Off:
	RETURN
; end of _LED_Off
