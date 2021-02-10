 /********************************************************************************************************************
 *  File		: Ssd_Cfg.h
 *	Module		: Seven segments display
 *	Target		: General
 *	Author		: mAboushenif
 *  Description	: configuration file to change the ports and channels of seven segments display when needed
 *********************************************************************************************************************/

#ifndef SSD_CFG_H_
#define SSD_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SSD_DIG1_EN_PORT			DIO_PORTB
#define SSD_DIG1_EN_CHANNEL			DIO_CH_1

#define SSD_DIG2_EN_PORT			DIO_PORTB
#define SSD_DIG2_EN_CHANNEL			DIO_CH_2

#define SSD_DATA_PORT				DIO_PORTA
#define SSD_DATA_GRP_POS			(4)
#define SSD_MASK					(0xF0)


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
 *  END OF FILE: Ssd_Cfg.h
 *********************************************************************************************************************/
