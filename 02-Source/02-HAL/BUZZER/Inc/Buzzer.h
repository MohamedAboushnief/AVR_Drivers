 /********************************************************************************************************************
 *  File		: Buzzer.h
 *	Module		: Buzzer
 *	Target		: General
 *	Author		: mAboushenif
 *  Description	: define data types of the buzzer and prototypes
 *********************************************************************************************************************/
#ifndef BUZZER_H_
#define BUZZER_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Dio.h"
#include "Buzzer_Cfg.h"

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
	 BUZZER0
	}BUZZER_ID;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Buzzer_TurnON(BUZZER_ID BuzzerID);
void Buzzer_TurnOFF(BUZZER_ID BuzzerID);
void Buzzer_Toggle(BUZZER_ID BuzzerID);
void Buzzer_INIT(void);

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Buzzer.h
 *********************************************************************************************************************/
