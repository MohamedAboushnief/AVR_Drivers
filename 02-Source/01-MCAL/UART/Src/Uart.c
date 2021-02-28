 /**********************************************************************************************************************
 *  File		: Uart.c
 *	Module		: UART
 *	Target		: ATMEGA32
 *	Author		: mAboushenif
 *  Description	:
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Uart.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void UART_Init(Uart_Mode, u16, Uart_Interrupt_Mode, Uart_Data_Bit, Uart_Stop_Bit, Uart_Parity_Mode ,Uart_Device_Mode)
* \Description     : Initialize UART
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : u16 Uart_Mode Uart_Data_Bit Uart_Stop_Bit Uart_Parity_Mode
* \Return value:   : void
*
*******************************************************************************/


void UART_Init(Uart_Mode uart_mode, u16 baud_rate, Uart_Interrupt_Mode interrupt_mode, Uart_Data_Bit data_size, Uart_Stop_Bit stop_bit, Uart_Parity_Mode parity_mode, Uart_Device_Mode device_mode){
	/* Set baud rate */
	USART_BAUD_RATE_REGISTER_H = (unsigned char)(baud_rate>>8);
	USART_BAUD_RATE_REGISTER_L = (unsigned char)baud_rate;

	/* Enable receiver and transmitter */
	switch(device_mode){
		case UART_RECEIVE:
			SET_BIT(USART_CONTROL_STATUS_REG_B,RXEN);
			break;
		case UART_TRANSMIT:
			SET_BIT(USART_CONTROL_STATUS_REG_B,TXEN);
			break;
		case UART_TRANSCIEVE:
			SET_BIT(USART_CONTROL_STATUS_REG_B,TXEN);
			SET_BIT(USART_CONTROL_STATUS_REG_B,RXEN);
			break;
	}


	/* Set frame formar data, stop bit, parity bits */
	SET_BIT(USART_CONTROL_STATUS_REG_C,URSEL);

	switch(data_size){
		case UART_5_BIT_DATA:
			CLEAR_BIT(USART_CONTROL_STATUS_REG_C,UCSZ0);
			CLEAR_BIT(USART_CONTROL_STATUS_REG_C,UCSZ1);
			break;
		case UART_6_BIT_DATA:
			SET_BIT(USART_CONTROL_STATUS_REG_C,UCSZ0);
			CLEAR_BIT(USART_CONTROL_STATUS_REG_C,UCSZ1);
			break;
		case UART_7_BIT_DATA:
			CLEAR_BIT(USART_CONTROL_STATUS_REG_C,UCSZ0);
			SET_BIT(USART_CONTROL_STATUS_REG_C,UCSZ1);
			break;
		case UART_8_BIT_DATA:
			SET_BIT(USART_CONTROL_STATUS_REG_C,UCSZ0);
			SET_BIT(USART_CONTROL_STATUS_REG_C,UCSZ1);
			break;
	}

	switch(stop_bit){
		case UART_1_STOP_BIT:
			CLEAR_BIT(USART_CONTROL_STATUS_REG_C,USBS);
			break;
		case UART_2_STOP_BIT:
			SET_BIT(USART_CONTROL_STATUS_REG_C,USBS);
			break;
	}

	switch(parity_mode){
		case UART_NO_PARITY:
			CLEAR_BIT(USART_CONTROL_STATUS_REG_C,UPM0);
			CLEAR_BIT(USART_CONTROL_STATUS_REG_C,UPM1);
			break;
		case UART_EVEN_PARITY:
			CLEAR_BIT(USART_CONTROL_STATUS_REG_C,UPM0);
			SET_BIT(USART_CONTROL_STATUS_REG_C,UPM1);
			break;
		case UART_ODD_PARITY:
			SET_BIT(USART_CONTROL_STATUS_REG_C,UPM0);
			SET_BIT(USART_CONTROL_STATUS_REG_C,UPM1);
			break;
	}


	/* Choose between using polling mode or interrupt*/
	switch(interrupt_mode){
		case INTERRUPT_ON:
			SET_BIT(STATUS_REG,GLOBAL_INT_EN);
			SET_BIT(USART_CONTROL_STATUS_REG_B,TXCIE);
			SET_BIT(USART_CONTROL_STATUS_REG_B,RXCIE);
			break;
		case INTERRUPT_OFF:
			break;
	}

	if(uart_mode == SYNC){
		SET_BIT(USART_CONTROL_STATUS_REG_C,UMSEL);
	}
	else if(uart_mode == ASYNC){
		CLEAR_BIT(USART_CONTROL_STATUS_REG_C,UMSEL);

	}



}

/******************************************************************************
* \Syntax          : void UART_TransmitChr(u8 data)
* \Description     : Transmit char over UART
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : data
* \Return value:   : void
*
*******************************************************************************/

void UART_TransmitChr(u8 data){

	/* Wait for empty transmit buffer */
	while (! CHECK_BIT(USART_CONTROL_STATUS_REG_A,UDRE))
	;
	/* Put data into buffer, sends the data */
	USART_DATA_REG = data;

}

/******************************************************************************
* \Syntax          : void UART_TransmitStr(u8 *str)
* \Description     : Transmit String over UART
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : *str
* \Return value:   : void
*
*******************************************************************************/

void UART_TransmitStr(u8 *str)
{
	/* Wait for empty transmit buffer */
	while (*str != '\0')
	{
		UART_TransmitChr(*str);
		str++;
	}
}

/******************************************************************************
* \Syntax          : u8 UART_ReceiveChr(void)
* \Description     : Recieve Char over UART
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : void
* \Return value:   : u8
*
*******************************************************************************/

u8 UART_ReceiveChr(void){
	/* Wait for data to be received */
	while (! CHECK_BIT(USART_CONTROL_STATUS_REG_A,RXC))
	;
	/* Get and return received data from buffer */
	return USART_DATA_REG;

}



/**********************************************************************************************************************
 *  END OF FILE: Uart.c
 *********************************************************************************************************************/
