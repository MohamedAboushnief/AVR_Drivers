 /**********************************************************************************************************************
 *  File		: DIO.c
 *	Module		: DIO
 *	Target		: ATMEGA32
 *	Author		: mAboushenif
 *  Description	:      
 * 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Dio.h"

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
* \Syntax          : void Dio_ConfigChannel(Dio_PortID portID, Dio_ChannelID channelID, Dio_DirectionType ChannelDir)     
* \Description     : Define direction of IO channel                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : portID
					 channelID     
					 channelDir                                                                 
* \Return value:   : None
*                                                                  
*******************************************************************************/
void Dio_ConfigChannel(Dio_PortID portID, Dio_ChannelID channelID, Dio_DirectionType channelDir)
{
	switch(portID){
		case DIO_PORTA:
			if(channelDir == INPUT){	
			CLEAR_BIT(DIO_PORTA_DDR,channelID);
			}
			else{
			SET_BIT(DIO_PORTA_DDR,channelID);	
			}
		break;
		
		case DIO_PORTB:
			if(channelDir == INPUT){
				CLEAR_BIT(DIO_PORTB_DDR,channelID);
			}
			else{
				SET_BIT(DIO_PORTB_DDR,channelID);
			}
		break;
		
		case DIO_PORTC:
			if(channelDir == INPUT){	
				CLEAR_BIT(DIO_PORTC_DDR,channelID);	
			}
			else{
				SET_BIT(DIO_PORTC_DDR,channelID);
			}
		break;
		
		case DIO_PORTD:
			if(channelDir == INPUT){
				CLEAR_BIT(DIO_PORTD_DDR,channelID);	
			}
			else{	
				SET_BIT(DIO_PORTD_DDR,channelID);
			}
		break;
	}
}



/******************************************************************************
* \Syntax          : void Dio_WRITEChannel(Dio_PortID portID, Dio_ChannelID channelID, Dio_LevelType channelLevel)     
* \Description     : Set Output of PORT register                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : portID   Port ID
					 channelLevel                                                                      
* \Return value:   : None
*                                                                  
*******************************************************************************/
void Dio_WRITEChannel(Dio_PortID portID, Dio_ChannelID channelID, Dio_LevelType channelLevel){
	
	switch(portID){
		case DIO_PORTA:
			if(channelLevel == STD_LOW){	
			CLEAR_BIT(DIO_PORTA_DATA_OUT,channelID);
			}
			else{
			SET_BIT(DIO_PORTA_DATA_OUT,channelID);	
			}
		break;
		
		case DIO_PORTB:
			if(channelLevel == STD_LOW){
				CLEAR_BIT(DIO_PORTB_DATA_OUT,channelID);
			}
			else{
				SET_BIT(DIO_PORTB_DATA_OUT,channelID);
			}
		break;
		
		case DIO_PORTC:
			if(channelLevel == STD_LOW){	
				CLEAR_BIT(DIO_PORTC_DATA_OUT,channelID);	
			}
			else{
				SET_BIT(DIO_PORTC_DATA_OUT,channelID);
			}
		break;
		
		case DIO_PORTD:
			if(channelLevel == STD_LOW){
				CLEAR_BIT(DIO_PORTD_DATA_OUT,channelID);	
			}
			else{	
				SET_BIT(DIO_PORTD_DATA_OUT,channelID);
			}
		break;
	}
}


/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_PortID portID, Dio_ChannelID channelID)     
* \Description     : Returns value of bit in PIN register                              
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : portID
					 channelID                                                                      
* \Return value:   : STD_LOW or STD_HIGH
*                                                                  
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_PortID portID, Dio_ChannelID channelID){
	
	switch(portID){
		case DIO_PORTA:
			if(CHECK_BIT(DIO_PORTA_DATA_IN,channelID)){
				return STD_HIGH;
			}
			else{
				return STD_LOW;
			}
		break;
		
		case DIO_PORTB:
			if(CHECK_BIT(DIO_PORTB_DATA_IN,channelID)){
				return STD_HIGH;
			}
			else{
				return STD_LOW;
			}
		break;
		
		case DIO_PORTC:
			if(CHECK_BIT(DIO_PORTC_DATA_IN,channelID)){
				return STD_HIGH;
			}
			else{
				return STD_LOW;
			}
		break;
		
		case DIO_PORTD:
			if(CHECK_BIT(DIO_PORTD_DATA_IN,channelID)){
				return STD_HIGH;
			}
			else{
				return STD_LOW;
			}
		break;
		
		
	}
}   




/******************************************************************************
* \Syntax          : void Dio_TOGGLEChannel(Dio_PortID portID, Dio_ChannelID channelID)
* \Description     : Toggle the output of the channel                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Port ID
					 channelLevel                                                                      
* \Return value:   : None
*                                                                  
*******************************************************************************/
void Dio_TOGGLEChannel(Dio_PortID portID, Dio_ChannelID channelID){
	
	switch(portID){
		case DIO_PORTA:
		FLIP_BIT(DIO_PORTA_DATA_OUT,channelID);
		break;
		
		case DIO_PORTB:
		FLIP_BIT(DIO_PORTB_DATA_OUT,channelID);
		break;
		
		case DIO_PORTC:
		FLIP_BIT(DIO_PORTC_DATA_OUT,channelID);
		break;
		
		case DIO_PORTD:
		FLIP_BIT(DIO_PORTD_DATA_OUT,channelID);		
		break;
	}
}




/******************************************************************************
* \Syntax          : void Dio_CONFIGChannelGroup(Dio_PortID portID, u8 channels_number, Dio_DirectionType ChannelDir)
* \Description     : Define direction of IO channel group                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Port ID
					 channels_number                                                                      
* \Return value:   : None
*                                                                  
*******************************************************************************/

void Dio_CONFIGChannelGroup(Dio_PortID portID, u8 mask, Dio_DirectionType ChannelDir){
	
	switch(portID){
		case DIO_PORTA:
			if(ChannelDir== OUTPUT){
				DIO_PORTA_DDR|= mask;
			}
			else{
				DIO_PORTA_DDR&= ~(mask);
			}
		break;
		
		case DIO_PORTB:
			if(ChannelDir== OUTPUT){
				DIO_PORTB_DDR|= mask;
			}
			else{
				DIO_PORTB_DDR&= ~(mask);
			}
		break;
		
		case DIO_PORTC:
			if(ChannelDir== OUTPUT){
				DIO_PORTC_DDR|= mask;
			}
			else{
				DIO_PORTC_DDR&= ~(mask);
			}
		break;
		
		case DIO_PORTD:
			if(ChannelDir== OUTPUT){
				DIO_PORTD_DDR|= mask;
			}
			else{
				DIO_PORTD_DDR&= ~(mask);
			}
		break;
	}
}





/******************************************************************************
* \Syntax          : void Dio_WRITEChannelGroup(Dio_PortID portID, u8 mask, u8 position, u8 data)
* \Description     : Define direction of IO channel group                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Port ID
					 channels_number                                                                      
* \Return value:   : None
*                                                                  
*******************************************************************************/

void Dio_WRITEChannelGroup(Dio_PortID portID, u8 mask, u8 position, u8 data){
	
	switch(portID){
		case DIO_PORTA:
			DIO_PORTA_DATA_OUT &= ~(mask);
			DIO_PORTA_DATA_OUT |= (data<<position);
		break;
		
		case DIO_PORTB:
			DIO_PORTB_DATA_OUT &= ~(mask);
			DIO_PORTB_DATA_OUT |= (data<<position);
		break;
		
		case DIO_PORTC:
			DIO_PORTC_DATA_OUT &= ~(mask);
			DIO_PORTC_DATA_OUT |= (data<<position);	
		break;
		
		case DIO_PORTD:
			DIO_PORTD_DATA_OUT &= ~(mask);
			DIO_PORTD_DATA_OUT |= (data<<position);	
		break;
	}
}

 

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
