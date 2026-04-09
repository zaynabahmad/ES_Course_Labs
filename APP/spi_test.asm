
_spi_test_run:

;spi_test.c,3 :: 		void spi_test_run(void) {
;spi_test.c,4 :: 		SPI_MasterInit();
	CALL       _SPI_MasterInit+0
;spi_test.c,6 :: 		SPI_Tranceive(0xAA);
	MOVLW      170
	MOVWF      FARG_SPI_Tranceive_Data+0
	CALL       _SPI_Tranceive+0
;spi_test.c,7 :: 		}
L_end_spi_test_run:
	RETURN
; end of _spi_test_run
