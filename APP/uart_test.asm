
_UART_Test:

;uart_test.c,4 :: 		void UART_Test(void)
;uart_test.c,6 :: 		UART_Init();
	CALL       _UART_Init+0
;uart_test.c,7 :: 		UART_SendString("UART Test Started...\n");
	MOVLW      ?lstr1_uart_test+0
	MOVWF      FARG_UART_SendString_str+0
	CALL       _UART_SendString+0
;uart_test.c,9 :: 		while(1)
L_UART_Test0:
;uart_test.c,11 :: 		char received = UART_ReceiveChar();
	CALL       _UART_ReceiveChar+0
;uart_test.c,12 :: 		UART_SendChar(received);
	MOVF       R0+0, 0
	MOVWF      FARG_UART_SendChar_d+0
	CALL       _UART_SendChar+0
;uart_test.c,13 :: 		}
	GOTO       L_UART_Test0
;uart_test.c,14 :: 		}
L_end_UART_Test:
	RETURN
; end of _UART_Test
