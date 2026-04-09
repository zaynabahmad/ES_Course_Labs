#line 1 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/APP/spi_test.c"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/spi/spi_interface.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/spi/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 12 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/spi/spi_interface.h"
void SPI_MasterInit(void);
u8 SPI_Tranceive(u8 Data);
#line 3 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/APP/spi_test.c"
void spi_test_run(void) {
 SPI_MasterInit();

 SPI_Tranceive(0xAA);
}
