 /********************************************************************************************************************
 *  File		: Dio.h
 *	Module		: DIO
 *	Target		: ATMEGA32
 *	Author		: mAboushenif
 *  Description	:
 *********************************************************************************************************************/
#ifndef DIO_H_
#define DIO_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"
#include "Dio_Cfg.h"
#include "Dio_Private.h"

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
	DIO_CH_0,
	DIO_CH_1,
	DIO_CH_2,
	DIO_CH_3,
	DIO_CH_4,
	DIO_CH_5,
	DIO_CH_6,
	DIO_CH_7
	}Dio_ChannelID; 
	
typedef enum{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD	
	}Dio_PortID;


typedef enum{
	STD_LOW,
	STD_HIGH
	}Dio_LevelType;
	

typedef enum{
	INPUT,
	OUTPUT
}Dio_DirectionType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Dio_ConfigChannel(Dio_PortID portID, Dio_ChannelID channelID, Dio_DirectionType ChannelDir);
void Dio_WRITEChannel(Dio_PortID portID, Dio_ChannelID channelID, Dio_LevelType channelLevel);
void Dio_TOGGLEChannel(Dio_PortID portID, Dio_ChannelID channelID);

Dio_LevelType Dio_ReadChannel(Dio_PortID portID, Dio_ChannelID channelID);

void Dio_CONFIGChannelGroup(Dio_PortID portID, u8 mask, Dio_DirectionType ChannelDir);
void Dio_WRITEChannelGroup(Dio_PortID portID, u8 mask, u8 position, u8 data);

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: FILE_NAME.h
 *********************************************************************************************************************/
