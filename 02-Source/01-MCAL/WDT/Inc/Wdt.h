 /********************************************************************************************************************
 *  File		: Wdt.h
 *	Module		: WDT
 *	Target		: ATMEGA32
 *	Author		: mAboushenif
 *  Description	: Functions prototypes and enums of Watch dog timer
 *********************************************************************************************************************/
#ifndef WDT_H_
#define WDT_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Wdt_Private.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


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
void WDG_ON(void);
void WDG_OFF(void);
void WDG_Refresh(void);


#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Wdt.h
 *********************************************************************************************************************/
