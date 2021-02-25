 /********************************************************************************************************************
 *  File		: Timer0.h
 *	Module		: TIMER0
 *	Target		: ATMEGA32
 *	Author		: mAboushenif
 *  Description	: Functions prototypes and enums of Timer0
 *********************************************************************************************************************/
#ifndef TIMER0_H_
#define TIMER0_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Timer0_Private.h"


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
	NORMAL_MODE,
	CTC_MODE,
	FAST_PWM,
	PHASE_CORRECT_PWM
}Timer0_Operation_Mode;

// if Fast PWM Mode or Phase Correct PWM Mode is used then TOGGLE_ON_COMPARE cannot be used as it is reserved
typedef enum{
	NORMAL_OPERATION,	// Normal port operation, OC0 disconnected.
	TOGGLE_ON_COMPARE,  // Toggle OC0 on compare match

	CLEAR_ON_COMPARE,   /* Clear OC0 on compare match / if Fast PWM  set OC0 at BOTTOM, (nin-inverting mode) /
						   if Phase correct mode Clear OC0 on compare match when up-counting.
						   Set OC0 on compare match when downcounting. */

	SET_ON_COMPARE      /* Set OC0 on compare match   / if Fast PWM clear OC0 at BOTTOM, (inverting mode) /
	 	 	 	 	 	   if Phase Correct mode Set OC0 on compare match when up-counting.
	 	 	 	 	 	   Clear OC0 on compare match when downcounting.*/
}Compare_Output_Mode;



typedef enum{
	NO_CLK_SOURCE,      // No clock source (Timer/Counter stopped).
	CLK_NO_PRESCALER,
	CLK_8_PRESCALER,
	CLK_64_PRESCALER,
	CLK_256_PRESCALER,
	CLK_1024_PRESCALER,
	CLK_EXTERNAL_FALLING, // External clock source on T0 pin. Clock on falling edge.
	CLK_EXTERNAL_RISING   // External clock source on T0 pin. Clock on rising edge.

}Timer0_Clk_Mode;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Timer0_Configure(Timer0_Operation_Mode,Compare_Output_Mode,Timer0_Clk_Mode,u8,u8);
void Set_Counter_Reg(u8);
void Set_Output_Compare_Reg(u8);



#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Timer0.h
 *********************************************************************************************************************/
