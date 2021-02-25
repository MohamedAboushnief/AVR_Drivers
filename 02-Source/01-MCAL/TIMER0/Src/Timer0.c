 /**********************************************************************************************************************
 *  File		: Timer0.c
 *	Module		: TIMER0
 *	Target		: ATMEGA32
 *	Author		: mAboushenif
 *  Description	: Configuration functions of Timer0
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Timer0.h"

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
* \Syntax          : void Timer0_Configure(Timer0_Operation_Mode,Compare_Output_Mode,Timer0_Clk_Mode)
* \Description     : Configure Timer0
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : Timer0_Operation_Mode  Compare_Output_Mode  Timer0_Clk_Mode
* \Return value:   : None
* \note 		   : give output_comp_reg value of 0x00 when not using CTC_MODE or PHASE_CORRECT_PWM
*******************************************************************************/


void Timer0_Configure(Timer0_Operation_Mode operation_mode, Compare_Output_Mode compare_mode,
		Timer0_Clk_Mode timer_clk_mode,u8 timer_count_reg, u8 output_comp_reg){

	// Enable global interrupt
	SET_BIT(STATUS_REG,GLOBAL_INT_EN);


	// choose operation mode
	switch(operation_mode){
		case NORMAL_MODE:
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,WGM00);
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,WGM01);
			SET_BIT(TIMER0_COUNTER_INT_M_REG,TOIE0);
			break;
		case PHASE_CORRECT_PWM:
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,WGM00);
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,WGM01);
			break;
		case CTC_MODE:
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,WGM00);
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,WGM01);
			SET_BIT(TIMER0_COUNTER_INT_M_REG,OCIE0);
			break;
		case FAST_PWM:
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,WGM00);
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,WGM01);
			break;
	}



	// choose compare mode
	switch(compare_mode){
		case NORMAL_OPERATION:
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,COM00);
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,COM01);
			break;
		case TOGGLE_ON_COMPARE: 		// only in non pwm mode
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,COM00);
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,COM01);
			break;
		case CLEAR_ON_COMPARE:			// Non inverting mode in PWM modes
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,COM00);
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,COM01);
			break;
		case SET_ON_COMPARE:			// inverting mode in PWM modes
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,COM00);
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,COM01);
			break;
	}

	// choose clock mode
	switch(timer_clk_mode){
		case NO_CLK_SOURCE:
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,CS00);
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,CS01);
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,CS02);
			break;
		case CLK_NO_PRESCALER:
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,CS00);
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,CS01);
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,CS02);
			break;
		case CLK_8_PRESCALER:
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,CS00);
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,CS01);
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,CS02);
			break;
		case CLK_64_PRESCALER:
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,CS00);
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,CS01);
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,CS02);
			break;
		case CLK_256_PRESCALER:
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,CS00);
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,CS01);
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,CS02);
			break;
		case CLK_1024_PRESCALER:
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,CS00);
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,CS01);
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,CS02);
			break;
		case CLK_EXTERNAL_FALLING:
			CLEAR_BIT(TIMER0_COUNTER_CONTROL_REG,CS00);
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,CS01);
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,CS02);
			break;
		case CLK_EXTERNAL_RISING:
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,CS00);
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,CS01);
			SET_BIT(TIMER0_COUNTER_CONTROL_REG,CS02);
			break;
	}

	TIMER0_COUNTER_REG = timer_count_reg;
	TIMER0_OUTPUT_COMPARE_REG = output_comp_reg;

}


/******************************************************************************
* \Syntax          : void Set_Counter_Reg(u8)
* \Description     : Set TCNT0 Reg with a value
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : u8
* \Return value:   : None
* \note 		   :
*******************************************************************************/

void Set_Counter_Reg(u8 value){
	TIMER0_COUNTER_REG = value;
}

/******************************************************************************
* \Syntax          : void Set_Output_Compare_Reg(u8)
* \Description     : Set OCR0 Reg with a value
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : u8
* \Return value:   : None
* \note 		   :
*******************************************************************************/

void Set_Output_Compare_Reg(u8 value){
	TIMER0_OUTPUT_COMPARE_REG = value;
}

/**********************************************************************************************************************
 *  END OF FILE: Timer0.c
 *********************************************************************************************************************/
