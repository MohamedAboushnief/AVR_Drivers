 /**********************************************************************************************************************
 *  File		: Led.c
 *	Module		: LED
 *	Target		: General
 *	Author		: mAboushenif
 *  Description	:      
 * 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Led.h"

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
* \Syntax          : void Led_TurnON(LED_ID LedID)
* \Description     : turn on LED                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : LedID                                                                    
* \Return value:   : None
*                                                                  
*******************************************************************************/

void Led_TurnON(LED_ID LedID){
	switch(LedID){
		case LED0:
		Dio_WRITEChannel(LED0_PORT,LED0_CHANNEL,STD_HIGH);
		break;
		
		case LED1:
		Dio_WRITEChannel(LED1_PORT,LED1_CHANNEL,STD_HIGH);
		break;
		
		case LED2:
		Dio_WRITEChannel(LED2_PORT,LED2_CHANNEL,STD_HIGH);
		break;
	}
}


/******************************************************************************
* \Syntax          : void Led_TurnOFF(LED_ID LedID)
* \Description     : turn off LED
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : LedID
* \Return value:   : None
*
*******************************************************************************/

void Led_TurnOFF(LED_ID LedID){
	switch(LedID){
		case LED0:
		Dio_WRITEChannel(LED0_PORT,LED0_CHANNEL,STD_LOW);
		break;
		
		case LED1:
		Dio_WRITEChannel(LED1_PORT,LED1_CHANNEL,STD_LOW);
		break;
		
		case LED2:
		Dio_WRITEChannel(LED2_PORT,LED2_CHANNEL,STD_LOW);
		break;
	}
}

/******************************************************************************
* \Syntax          : void Led_INIT(void)
* \Description     : initialize LEDs as output
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : void
* \Return value:   : None
*
*******************************************************************************/

void Led_INIT(void){
	Dio_ConfigChannel(LED0_PORT,LED0_CHANNEL,OUTPUT);
	Dio_ConfigChannel(LED1_PORT,LED1_CHANNEL,OUTPUT);
	Dio_ConfigChannel(LED2_PORT,LED2_CHANNEL,OUTPUT);
	
}

/******************************************************************************
* \Syntax          : void Led_Toggle(LED_ID LedID)
* \Description     : Flip the output of the LED
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : LedID
* \Return value:   : None
*
*******************************************************************************/

void Led_Toggle(LED_ID LedID){
	switch(LedID){
		case LED0:
		Dio_TOGGLEChannel(LED0_PORT,LED0_CHANNEL);
		break;
		
		case LED1:
		Dio_TOGGLEChannel(LED1_PORT,LED1_CHANNEL);
		break;
		
		case LED2:
		Dio_TOGGLEChannel(LED2_PORT,LED2_CHANNEL);
		break;
		
	}
	
}

/**********************************************************************************************************************
 *  END OF FILE: Led.c
 *********************************************************************************************************************/
