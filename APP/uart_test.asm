
_app_uart_test:

;uart_test.c,4 :: 		void app_uart_test(void)
;uart_test.c,8 :: 		UART_Init();
	CALL       _UART_Init+0
;uart_test.c,10 :: 		while(1)
L_app_uart_test0:
;uart_test.c,12 :: 		receivedChar = UART_ReceiveChar();
	CALL       _UART_ReceiveChar+0
;uart_test.c,13 :: 		UART_SendChar(receivedChar);
	MOVF       R0+0, 0
	MOVWF      FARG_UART_SendChar_txValue+0
	CALL       _UART_SendChar+0
;uart_test.c,14 :: 		}
	GOTO       L_app_uart_test0
;uart_test.c,15 :: 		}
L_end_app_uart_test:
	RETURN
; end of _app_uart_test
