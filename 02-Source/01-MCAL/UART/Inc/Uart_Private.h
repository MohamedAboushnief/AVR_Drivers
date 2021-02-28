 /********************************************************************************************************************
 *  File		: Uart_Private.h
 *	Module		: UART
 *	Target		: ATMEGA32
 *	Author		: mAboushenif
 *  Description	:
 *********************************************************************************************************************/
#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define USART_DATA_REG                (*(volatile u8 *) 0x2C)

#define USART_CONTROL_STATUS_REG_A 	  (*(volatile u8 *) 0x2B)
#define MPCM  (0) // Multi-processor Communication Mode
#define U2X   (1) // Double the USART Transmission Speed
#define PE    (2) // Parity Error
#define DOR   (3) // Data OverRun
#define FE    (4) // Frame Error
#define UDRE  (5) // USART Data Register Empty
#define TXC   (6) // USART Transmit Complete
#define RXC   (7) // USART Receive Complete


#define USART_CONTROL_STATUS_REG_B 	  (*(volatile u8 *) 0x2A)
#define TXB8  (0) // Transmit Data Bit 8
#define RXB8  (1) // Receive Data Bit 8
#define UCSZ2 (2) // Character Size
#define TXEN  (3) // Transmitter Enable
#define RXEN  (4) // Receiver Enable
#define UDRIE (5) // USART Data Register Empty Interrupt Enable
#define TXCIE (6) // TX Complete Interrupt Enable
#define RXCIE (7) // RX Complete Interrupt Enable


#define USART_CONTROL_STATUS_REG_C 	  (*(volatile u8 *) 0x40)
#define UCPOL  (0) // Clock Polarity
#define UCSZ0  (1) // Character Size
#define UCSZ1  (2)
#define USBS   (3) // Stop Bit select
#define UPM0   (4) // Parity select
#define UPM1   (5)
#define UMSEL  (6) // USART Mode Select
#define URSEL  (7) // Register Select

#define USART_BAUD_RATE_REGISTER_H	  (*(volatile u8 *) 0x40)
#define USART_BAUD_RATE_REGISTER_L	  (*(volatile u8 *) 0x29)

// to enable global interrupts to use the interrupt mode in UART
#define STATUS_REG          		  (*(volatile u8 *) 0x5F)
#define GLOBAL_INT_EN (7)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Uart_Private.h
 *********************************************************************************************************************/
