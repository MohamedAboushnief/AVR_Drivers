 /********************************************************************************************************************
 *  File		: Interrupts_Private.h
 *	Module		: Interrupts
 *	Target		: ATMEGA32
 *	Author		: mAboushenif
 *  Description	:
 *********************************************************************************************************************/
#ifndef INTERRUPTS_PRIVATE_H_
#define INTERRUPTS_PRIVATE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

//To enable Global Interrupt
#define STATUS_REG          (*(volatile u8*)0x5F)
#define GLOBAL_INT_EN (7)


//to configure IN0 and INT1 interrupt requests as falling edge, rising edge ,...
#define MCU_CONTROL_REG     (*(volatile u8*)0x55)
#define ISC00 				(0)
#define ISC01 				(1)
#define ISC10 				(2)
#define ISC11 				(3)

//to configure INT2 interrupt request as falling edge, rising edge ,...
#define MCU_CONTROL_STATUS_REG  (*(volatile u8*)0x54)
#define ISC2				    (6)


// to enable the external Interrupts but first GLobal Interrupt must be 1
#define GENERAL_INT_CONTROL_REG  (*(volatile u8*)0x5B)
#define INT1 				(5)
#define INT0 				(6)
#define INT2 				(7)












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
 *  END OF FILE: Interrupts_Private.h
 *********************************************************************************************************************/
