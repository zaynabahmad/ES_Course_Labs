
_main:

;main.c,5 :: 		void main()
;main.c,7 :: 		ADCON1 = 0x07;   // ?? VERY IMPORTANT (All PORTA digital)
	MOVLW      7
	MOVWF      ADCON1+0
;main.c,9 :: 		TRISA = 0xFF;   // Make PORTA input
	MOVLW      255
	MOVWF      TRISA+0
;main.c,10 :: 		TRISB = 0x00;   // Make PORTB output
	CLRF       TRISB+0
;main.c,12 :: 		PORTA = 0x00;
	CLRF       PORTA+0
;main.c,13 :: 		PORTB = 0x00;
	CLRF       PORTB+0
;main.c,15 :: 		while(1)
L_main0:
;main.c,17 :: 		if((PORTA.F0) == 1)   // RA0 pressed
	BTFSS      PORTA+0, 0
	GOTO       L_main2
;main.c,19 :: 		PORTB.F0 = 1;
	BSF        PORTB+0, 0
;main.c,20 :: 		PORTB.F1 = 1;
	BSF        PORTB+0, 1
;main.c,21 :: 		Delay_ms(200);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      8
	MOVWF      R12+0
	MOVLW      119
	MOVWF      R13+0
L_main3:
	DECFSZ     R13+0, 1
	GOTO       L_main3
	DECFSZ     R12+0, 1
	GOTO       L_main3
	DECFSZ     R11+0, 1
	GOTO       L_main3
;main.c,23 :: 		PORTB.F0 = 0;
	BCF        PORTB+0, 0
;main.c,24 :: 		PORTB.F1 = 0;
	BCF        PORTB+0, 1
;main.c,25 :: 		Delay_ms(200);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      8
	MOVWF      R12+0
	MOVLW      119
	MOVWF      R13+0
L_main4:
	DECFSZ     R13+0, 1
	GOTO       L_main4
	DECFSZ     R12+0, 1
	GOTO       L_main4
	DECFSZ     R11+0, 1
	GOTO       L_main4
;main.c,26 :: 		}
	GOTO       L_main5
L_main2:
;main.c,28 :: 		else if((PORTA.F1) == 1)  // RA1 pressed
	BTFSS      PORTA+0, 1
	GOTO       L_main6
;main.c,30 :: 		PORTB.F0 = 1;
	BSF        PORTB+0, 0
;main.c,31 :: 		PORTB.F1 = 1;
	BSF        PORTB+0, 1
;main.c,32 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main7:
	DECFSZ     R13+0, 1
	GOTO       L_main7
	DECFSZ     R12+0, 1
	GOTO       L_main7
	DECFSZ     R11+0, 1
	GOTO       L_main7
	NOP
	NOP
;main.c,34 :: 		PORTB.F0 = 0;
	BCF        PORTB+0, 0
;main.c,35 :: 		PORTB.F1 = 0;
	BCF        PORTB+0, 1
;main.c,36 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main8:
	DECFSZ     R13+0, 1
	GOTO       L_main8
	DECFSZ     R12+0, 1
	GOTO       L_main8
	DECFSZ     R11+0, 1
	GOTO       L_main8
	NOP
	NOP
;main.c,37 :: 		}
	GOTO       L_main9
L_main6:
;main.c,41 :: 		PORTB.F0 = 0;
	BCF        PORTB+0, 0
;main.c,42 :: 		PORTB.F1 = 0;
	BCF        PORTB+0, 1
;main.c,43 :: 		}
L_main9:
L_main5:
;main.c,44 :: 		}
	GOTO       L_main0
;main.c,45 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
