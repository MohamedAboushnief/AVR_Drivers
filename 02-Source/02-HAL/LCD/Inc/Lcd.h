 /********************************************************************************************************************
 *  File		: Lcd.h
 *	Module		: LCD
 *	Target		: General
 *	Author		: mAboushenif
 *  Description	: Driver for LCD peripheral
 *********************************************************************************************************************/

#ifndef LCD_H_
#define LCD_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#define F_CPU 16000000UL
#include "Dio.h"
#include "Lcd_Cfg.h"
#include <util/delay.h>

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum{
	_LCD_CLEAR=0x01,
	_LCD_CURSOR_OFF=0x0C,
	_LCD_CURSOR_ON=0x0F,
	_LCD_4BIT_MODE=0x28,
	_LCD_8BIT_MODE=0x38,
	_LCD_ON=0x0F,
	_LCD_OFF=0x08,
	_LCD_CURSOR_UNDERLINE=0x0E,
	_LCD_CURSOR_SHIFT_LEFT=0x10,
	_LCD_CURSOR_SHIFT_RIGHT=0x14,
	_LCD_CURSOR_INCREMENT=0x06
	}LcdCmdType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void LCD_Init(void);
void LCD_DisplayChr(u8 chr);
void LCD_DisplayStr(u8 * str);
void LCD_Cmd(u8 cmd);
void LCD_GoToRowColumn(u8 row, u8 column);
void LCD_WriteCustomChr(void);

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Lcd.h
 *********************************************************************************************************************/
