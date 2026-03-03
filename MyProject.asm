
_short_sequence:

;MyProject.c,1 :: 		void short_sequence() {
;MyProject.c,2 :: 		PORTB.B0 = 1;
	BSF        PORTB+0, 0
;MyProject.c,3 :: 		PORTB.B1 = 0;
	BCF        PORTB+0, 1
;MyProject.c,4 :: 		Delay_ms(200);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      8
	MOVWF      R12+0
	MOVLW      119
	MOVWF      R13+0
L_short_sequence0:
	DECFSZ     R13+0, 1
	GOTO       L_short_sequence0
	DECFSZ     R12+0, 1
	GOTO       L_short_sequence0
	DECFSZ     R11+0, 1
	GOTO       L_short_sequence0
;MyProject.c,5 :: 		PORTB.B0 = 0;
	BCF        PORTB+0, 0
;MyProject.c,6 :: 		PORTB.B1 = 1;
	BSF        PORTB+0, 1
;MyProject.c,7 :: 		Delay_ms(200);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      8
	MOVWF      R12+0
	MOVLW      119
	MOVWF      R13+0
L_short_sequence1:
	DECFSZ     R13+0, 1
	GOTO       L_short_sequence1
	DECFSZ     R12+0, 1
	GOTO       L_short_sequence1
	DECFSZ     R11+0, 1
	GOTO       L_short_sequence1
;MyProject.c,8 :: 		}
L_end_short_sequence:
	RETURN
; end of _short_sequence

_long_sequence:

;MyProject.c,10 :: 		void long_sequence() {
;MyProject.c,11 :: 		PORTB.B0 = 1;
	BSF        PORTB+0, 0
;MyProject.c,12 :: 		PORTB.B1 = 0;
	BCF        PORTB+0, 1
;MyProject.c,13 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_long_sequence2:
	DECFSZ     R13+0, 1
	GOTO       L_long_sequence2
	DECFSZ     R12+0, 1
	GOTO       L_long_sequence2
	DECFSZ     R11+0, 1
	GOTO       L_long_sequence2
	NOP
	NOP
;MyProject.c,14 :: 		PORTB.B0 = 0;
	BCF        PORTB+0, 0
;MyProject.c,15 :: 		PORTB.B1 = 1;
	BSF        PORTB+0, 1
;MyProject.c,16 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_long_sequence3:
	DECFSZ     R13+0, 1
	GOTO       L_long_sequence3
	DECFSZ     R12+0, 1
	GOTO       L_long_sequence3
	DECFSZ     R11+0, 1
	GOTO       L_long_sequence3
	NOP
	NOP
;MyProject.c,17 :: 		}
L_end_long_sequence:
	RETURN
; end of _long_sequence

_main:

;MyProject.c,19 :: 		void main() {
;MyProject.c,21 :: 		TRISB = 0x00;   // PORTB = output (LEDs)
	CLRF       TRISB+0
;MyProject.c,22 :: 		TRISD = 0xFF;   // PORTD = input (buttons)
	MOVLW      255
	MOVWF      TRISD+0
;MyProject.c,24 :: 		PORTB = 0x00;   // LEDs off
	CLRF       PORTB+0
;MyProject.c,26 :: 		while(1) {
L_main4:
;MyProject.c,28 :: 		if(PORTD.B0 == 1) {          // Button 1
	BTFSS      PORTD+0, 0
	GOTO       L_main6
;MyProject.c,29 :: 		short_sequence();
	CALL       _short_sequence+0
;MyProject.c,30 :: 		}
	GOTO       L_main7
L_main6:
;MyProject.c,32 :: 		else if(PORTD.B1 == 1) {     // Button 2
	BTFSS      PORTD+0, 1
	GOTO       L_main8
;MyProject.c,33 :: 		long_sequence();
	CALL       _long_sequence+0
;MyProject.c,34 :: 		}
	GOTO       L_main9
L_main8:
;MyProject.c,37 :: 		PORTB.B0 = 0;
	BCF        PORTB+0, 0
;MyProject.c,38 :: 		PORTB.B1 = 0;
	BCF        PORTB+0, 1
;MyProject.c,39 :: 		}
L_main9:
L_main7:
;MyProject.c,40 :: 		}
	GOTO       L_main4
;MyProject.c,41 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
