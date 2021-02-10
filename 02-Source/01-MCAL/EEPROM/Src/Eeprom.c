 /**********************************************************************************************************************
 *  File		: Eeprom.c
 *	Module		: EEPROM
 *	Target		: ATMEGA32
 *	Author		: mAboushenif
 *  Description	:      
 * 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Eeprom.h"

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
* \Syntax          : void EEPROM_Write(u16 address, u8 data)
* \Description     : write in EEPROM                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : address
					 data                                                                      
* \Return value:   : None
*                                                                  
*******************************************************************************/

//check datasheet for the function
void EEPROM_Write(u16 address, u8 data){
	while(EEPROM_CR_REG & (1<<EEWE)){
		;
	}
	
	EEPROM_ARH_REG= address>>8;
	EEPROM_ARL_REG=address;
	
	EEPROM_DR_REG=data;
	SET_BIT(EEPROM_CR_REG,EEMWE);
	SET_BIT(EEPROM_CR_REG,EEWE);

}

/******************************************************************************
* \Syntax          : u8 EEPROM_Read(u16 address)
* \Description     : read from EEPROM                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : address                                                                      
* \Return value:   : u8
*                                                                  
*******************************************************************************/

u8 EEPROM_Read(u16 address){
	
	while(EEPROM_CR_REG & (1<<EEWE)){
		;
	}
	EEPROM_ARH_REG= address>>8;
	EEPROM_ARL_REG= address;
	
	SET_BIT(EEPROM_CR_REG,EERE);
	
	return EEPROM_DR_REG;	
	
}

 

/**********************************************************************************************************************
 *  END OF FILE: Eeprom.c
 *********************************************************************************************************************/