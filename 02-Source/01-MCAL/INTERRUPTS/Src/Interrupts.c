 /**********************************************************************************************************************
 *  File		: Interrupts.c
 *	Module		: Interrupts
 *	Target		: ATMEGA32
 *	Author		: mAboushenif
 *  Description	:
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Interrupts.h"

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
* \Syntax          : void Global_Interrupt_En(void);
* \Description     : enable Global Interrupt flag
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : void
* \Return value:   : None
*
*******************************************************************************/

void Global_Interrupt_En(){
	SET_BIT(STATUS_REG,GLOBAL_INT_EN);
}


/******************************************************************************
* \Syntax          : void Global_Interrupt_Dis(void);
* \Description     : enable Global Interrupt flag
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : void
* \Return value:   : None
*
*******************************************************************************/

void Global_Interrupt_Dis(){
	CLEAR_BIT(STATUS_REG,GLOBAL_INT_EN);
}


/******************************************************************************
* \Syntax          : void Ext_Interrupt_Enable(Ext_Interrupt_ID)
* \Description     : enable Interrupt flag
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : interruptNo
* \Return value:   : None
*
*******************************************************************************/


void Ext_Interrupt_Enable(Ext_Interrupt_ID interruptNo){
	switch(interruptNo){
	case Interrupt0:
		SET_BIT(GENERAL_INT_CONTROL_REG,INT0);
		break;

	case Interrupt1:
		SET_BIT(GENERAL_INT_CONTROL_REG,INT1);
		break;

	case Interrupt2:
		SET_BIT(GENERAL_INT_CONTROL_REG,INT2);
		break;
	}

}

/******************************************************************************
* \Syntax          : void Interrupt_Disable(Ext_Interrupt_ID)
* \Description     : disable Interrupt flag
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : interruptNo
* \Return value:   : None
*
*******************************************************************************/

void Ext_Interrupt_Disable(Ext_Interrupt_ID interruptNo){
	switch(interruptNo){
	case Interrupt0:
		CLEAR_BIT(GENERAL_INT_CONTROL_REG,INT0);
		break;

	case Interrupt1:
		CLEAR_BIT(GENERAL_INT_CONTROL_REG,INT1);
		break;

	case Interrupt2:
		CLEAR_BIT(GENERAL_INT_CONTROL_REG,INT2);
		break;
	}

}

/******************************************************************************
* \Syntax          : void Ext_Interrupt_Config(Ext_Interrupt_ID,Interrupt_Mode)
* \Description     : configure Interrupt mode
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : interruptNo mode
* \Return value:   : None
*
*******************************************************************************/

void Ext_Interrupt_Config(Ext_Interrupt_ID interruptNo,Interrupt_Mode mode){

	switch(interruptNo){
		case Interrupt0:
			if(mode==Low){
				CLEAR_BIT(MCU_CONTROL_REG,ISC00);
				CLEAR_BIT(MCU_CONTROL_REG,ISC01);
			}
			else if(mode==Falling_Edge){
				CLEAR_BIT(MCU_CONTROL_REG,ISC00);
				SET_BIT(MCU_CONTROL_REG,ISC01);
			}
			else if(mode==Rising_Edge){
				SET_BIT(MCU_CONTROL_REG,ISC00);
				SET_BIT(MCU_CONTROL_REG,ISC01);
			}
			else if(mode==Any_Change){
				SET_BIT(MCU_CONTROL_REG,ISC00);
				CLEAR_BIT(MCU_CONTROL_REG,ISC01);
			}
			break;

		case Interrupt1:
			if(mode==Low){
				CLEAR_BIT(MCU_CONTROL_REG,ISC10);
				CLEAR_BIT(MCU_CONTROL_REG,ISC11);
			}
			else if(mode==Falling_Edge){
				CLEAR_BIT(MCU_CONTROL_REG,ISC10);
				SET_BIT(MCU_CONTROL_REG,ISC11);
			}
			else if(mode==Rising_Edge){
				SET_BIT(MCU_CONTROL_REG,ISC10);
				SET_BIT(MCU_CONTROL_REG,ISC11);
			}
			else if(mode==Any_Change){
				SET_BIT(MCU_CONTROL_REG,ISC10);
				CLEAR_BIT(MCU_CONTROL_REG,ISC11);
			}
			break;

		case Interrupt2:
			if(mode==Falling_Edge){
				CLEAR_BIT(MCU_CONTROL_REG,ISC2);
			}
			else if(mode==Rising_Edge){
				SET_BIT(MCU_CONTROL_REG,ISC2);
			}
			break;
		}



}
/**********************************************************************************************************************
 *  END OF FILE: Interrupts.c
 *********************************************************************************************************************/
