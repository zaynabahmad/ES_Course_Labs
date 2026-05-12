#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#define SSPCON   (*((volatile u8*)0x14))
#define SSPCON2  (*((volatile u8*)0x91))
#define SSPADD   (*((volatile u8*)0x93))
#define SSPSTAT  (*((volatile u8*)0x94))
#define SSPBUF   (*((volatile u8*)0x13))
#define TRISC    (*((volatile u8*)0x87))

/* SSPCON bit positions */
#define SSPEN    5   /* SSP Enable */
#define CKP      4   /* Clock Idle State (I2C slave clock release) */
#define SSPM3    3   /* SSP Mode Select bit 3 */
#define SSPM2    2   /* SSP Mode Select bit 2 */
#define SSPM1    1   /* SSP Mode Select bit 1 */
#define SSPM0    0   /* SSP Mode Select bit 0 */

/* SSPCON2 bit positions */
#define GCEN     7   /* General Call Enable    */
#define ACKSTAT  6   /* ACK Status: 0=ACK, 1=NACK received */
#define ACKDT    5   /* ACK Data bit to send   */
#define ACKEN    4   /* ACK Sequence Enable    */
#define RCEN     3   /* Receive Enable         */
#define PEN      2   /* STOP Condition Enable  */
#define RSEN     1   /* Repeated START Enable  */
#define SEN      0   /* START Condition Enable */

/* SSPSTAT bit positions */
#define SMP      7   /* Slew Rate Control: 1=disabled (standard) */
#define CKE      6   /* SMBus Inputs */
#define D_A      5   /* Data/Address bit */
#define P        4   /* STOP bit detected */
#define S        3   /* START bit detected */
#define R_W      2   /* R/W bit information */
#define UA       1   /* Update Address */
#define BF       0   /* Buffer Full */

#endif
