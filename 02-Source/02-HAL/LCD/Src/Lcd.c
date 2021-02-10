 /**********************************************************************************************************************
 *  File		: Lcd.c
 *	Module		: Button
 *	Target		: General
 *	Author		: mAboushenif
 *  Description	: contains functions to interface with LCD     
 * 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Lcd.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

u8 customChar[]=
{
	0b00000100,
	0b00011111,
	0b00010001,
	0b00010001,
	0b00011111,
	0b00011111,
	0b00011111,
	0b00011111
	
};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : static void enablePulse(void)
* \Description     : 
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : void
* \Return value:   : None
*
*******************************************************************************/
static void enablePulse(void){
	
	Dio_WRITEChannel(LCD_EN_PORT,LCD_EN_CHANNEL,STD_HIGH);
	_delay_us(1);
	Dio_WRITEChannel(LCD_EN_PORT,LCD_EN_CHANNEL,STD_LOW);
	_delay_ms(2);

	
}


/******************************************************************************
* \Syntax          : static void LCD_Write(void)
* \Description     :
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : data
* \Return value:   : None
*
*******************************************************************************/
static void LCD_Write(u8 data){
	
	u8 MSB_Nibble = data>>LCD_DATA_GRP_POS;
	u8 LSB_Nibble = data;
	Dio_WRITEChannelGroup(LCD_DATA_PORT,LCD_MASK,LCD_DATA_GRP_POS,MSB_Nibble);
	enablePulse();
	Dio_WRITEChannelGroup(LCD_DATA_PORT,LCD_MASK,LCD_DATA_GRP_POS,LSB_Nibble);
	enablePulse();
	
	
	
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void LCD_Init(void)
* \Description     : Configure LCD pins as output                             
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : void                                                                    
* \Return value:   : None
*                                                                  
*******************************************************************************/
void LCD_Init(void){
	
		Dio_CONFIGChannelGroup(LCD_DATA_PORT,LCD_MASK,OUTPUT);
		Dio_ConfigChannel(LCD_RS_PORT,LCD_RS_CHANNEL,OUTPUT);
		Dio_ConfigChannel(LCD_RW_PORT,LCD_RW_CHANNEL,OUTPUT);
		Dio_ConfigChannel(LCD_EN_PORT,LCD_EN_CHANNEL,OUTPUT);
		
		_delay_ms(15);
		LCD_Cmd(0x03);
		_delay_ms(5);
		LCD_Cmd(0x03);
		_delay_us(102);
		LCD_Cmd(0x03);
		LCD_Cmd(0x02);
		LCD_Cmd(0x02);
		LCD_Cmd(_LCD_4BIT_MODE);
		LCD_Cmd(_LCD_CLEAR);
		


		
}

/******************************************************************************
* \Syntax          : void LCD_Cmd(u8 cmd)
* \Description     : send commands to the LCD 
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : cmd
* \Return value:   : None
*
*******************************************************************************/
void LCD_Cmd(u8 cmd){
	Dio_WRITEChannel(LCD_RS_PORT,LCD_RS_CHANNEL,STD_LOW);  //cmd mode
	Dio_WRITEChannel(LCD_RW_PORT,LCD_RW_CHANNEL,STD_LOW);  //write mode
	LCD_Write(cmd);
}


/******************************************************************************
* \Syntax          : void LCD_DisplayChr(u8 chr)
* \Description     : send char to the LCD
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : chr
* \Return value:   : None
*
*******************************************************************************/


void LCD_DisplayChr(u8 chr){
	Dio_WRITEChannel(LCD_RS_PORT,LCD_RS_CHANNEL,STD_HIGH); //data mode
	Dio_WRITEChannel(LCD_RW_PORT,LCD_RW_CHANNEL,STD_LOW);  //write mode
	LCD_Write(chr);
}



/******************************************************************************
* \Syntax          : void LCD_DisplayStr(u8 * str)
* \Description     : send str to the LCD
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : str
* \Return value:   : None
*
*******************************************************************************/


void LCD_DisplayStr(u8 * str){
	
	while(*str != '\0'){
		LCD_DisplayChr(*str);
		str++;
	}
}



/******************************************************************************
* \Syntax          : void LCD_GoToRowColumn(u8 row, u8 column)
* \Description     : write in position on lcd
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : row 
					 column
* \Return value:   : None
*
*******************************************************************************/

void LCD_GoToRowColumn(u8 row, u8 column){
	
	switch(row){
		case 0:
		LCD_Cmd(0x80+column);
		break;
		
		case 1:
		LCD_Cmd(0xC0+column);
		break;
	}
}


/******************************************************************************
* \Syntax          : void LCD_WriteCustomChr(void)
* \Description     : write in CGRAM a custom char
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : CustomChrPtr
* \Return value:   : None
*
*******************************************************************************/

void LCD_WriteCustomChr(void){
	u8 index;
	LCD_Cmd(0x40);
	
	for(index=0 ; index<8 ; index++){
		LCD_DisplayChr(customChar[index]);
	}

}




/**********************************************************************************************************************
 *  END OF FILE: Lcd.c
 *********************************************************************************************************************/
