 /**********************************************************************************************************************
 *  File		: Adc.c
 *	Module		: ADC
 *	Target		: ATMEGA32
 *	Author		: mAboushenif
 *  Description	:
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Adc.h"

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
* \Syntax          : void Adc_Configure(Voltage_Ref_Selection, Adc_Prescaler_Sel_Bits)
* \Description     : Configure ADC
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : voltage_ref
					 channels_number
* \Return value:   : None
*
*******************************************************************************/
void Adc_Configure(Voltage_Ref_Selection voltage_ref, Adc_Prescaler_Sel_Bits prescaler_mode ,Adc_Conv_Mode conv_mode){
	// Enable ADC
	SET_BIT(ADC_CONTROL_STATUS_REG_A,ADEN);

	//choose convrsion mode polling vs interrupt
	if(conv_mode==ADC_INTERRUPT){
		SET_BIT(STATUS_REG,GLOBAL_INT_EN);
		SET_BIT(ADC_CONTROL_STATUS_REG_A,ADIE);
	}
	else if(conv_mode==ADC_POLLING){
		CLEAR_BIT(ADC_CONTROL_STATUS_REG_A,ADIE);
	}


	//choose voltage reference mode
	switch(voltage_ref){
		case AREF:
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,REFS0);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,REFS1);
			break;
		case AVCC:
			SET_BIT(ADC_MULTIPLEXER_SEL_REG,REFS0);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,REFS1);
			break;
		case INTERNAL:
			SET_BIT(ADC_MULTIPLEXER_SEL_REG,REFS0);
			SET_BIT(ADC_MULTIPLEXER_SEL_REG,REFS1);
			break;
	}

	//choose voltage reference mode
	switch(prescaler_mode){
		case DIV_FACTOR_2:
			CLEAR_BIT(ADC_CONTROL_STATUS_REG_A,ADPS0);
			CLEAR_BIT(ADC_CONTROL_STATUS_REG_A,ADPS1);
			CLEAR_BIT(ADC_CONTROL_STATUS_REG_A,ADPS2);
			break;
		case DIV_FACTOR_4:
			CLEAR_BIT(ADC_CONTROL_STATUS_REG_A,ADPS0);
			SET_BIT(ADC_CONTROL_STATUS_REG_A,ADPS1);
			CLEAR_BIT(ADC_CONTROL_STATUS_REG_A,ADPS2);
			break;
		case DIV_FACTOR_8:
			SET_BIT(ADC_CONTROL_STATUS_REG_A,ADPS0);
			SET_BIT(ADC_CONTROL_STATUS_REG_A,ADPS1);
			CLEAR_BIT(ADC_CONTROL_STATUS_REG_A,ADPS2);
			break;
		case DIV_FACTOR_16:
			CLEAR_BIT(ADC_CONTROL_STATUS_REG_A,ADPS0);
			CLEAR_BIT(ADC_CONTROL_STATUS_REG_A,ADPS1);
			SET_BIT(ADC_CONTROL_STATUS_REG_A,ADPS2);
			break;
		case DIV_FACTOR_32:
			SET_BIT(ADC_CONTROL_STATUS_REG_A,ADPS0);
			CLEAR_BIT(ADC_CONTROL_STATUS_REG_A,ADPS1);
			SET_BIT(ADC_CONTROL_STATUS_REG_A,ADPS2);
			break;
		case DIV_FACTOR_64:
			CLEAR_BIT(ADC_CONTROL_STATUS_REG_A,ADPS0);
			SET_BIT(ADC_CONTROL_STATUS_REG_A,ADPS1);
			SET_BIT(ADC_CONTROL_STATUS_REG_A,ADPS2);
			break;
		case DIV_FACTOR_128:
			SET_BIT(ADC_CONTROL_STATUS_REG_A,ADPS0);
			SET_BIT(ADC_CONTROL_STATUS_REG_A,ADPS1);
			SET_BIT(ADC_CONTROL_STATUS_REG_A,ADPS2);
			break;
	}
}


/******************************************************************************
* \Syntax          : void Adc_Channel_Sel(Adc_ChannelID)
* \Description     : Choose ADC channel to use
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : channel
* \Return value:   : None
*
*******************************************************************************/
void Adc_Channel_Sel(Adc_ChannelID channel){

	// choose ADC
	switch(channel){
		case ADC0:
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX0);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX1);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX2);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX3);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX4);
			break;
		case ADC1:
			SET_BIT(ADC_MULTIPLEXER_SEL_REG,MUX0);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX1);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX2);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX3);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX4);
			break;
		case ADC2:
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX0);
			SET_BIT(ADC_MULTIPLEXER_SEL_REG,MUX1);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX2);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX3);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX4);
			break;
		case ADC3:
			SET_BIT(ADC_MULTIPLEXER_SEL_REG,MUX0);
			SET_BIT(ADC_MULTIPLEXER_SEL_REG,MUX1);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX2);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX3);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX4);
			break;
		case ADC4:
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX0);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX1);
			SET_BIT(ADC_MULTIPLEXER_SEL_REG,MUX2);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX3);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX4);
			break;
		case ADC5:
			SET_BIT(ADC_MULTIPLEXER_SEL_REG,MUX0);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX1);
			SET_BIT(ADC_MULTIPLEXER_SEL_REG,MUX2);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX3);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX4);
			break;
		case ADC6:
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX0);
			SET_BIT(ADC_MULTIPLEXER_SEL_REG,MUX1);
			SET_BIT(ADC_MULTIPLEXER_SEL_REG,MUX2);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX3);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX4);
			break;
		case ADC7:
			SET_BIT(ADC_MULTIPLEXER_SEL_REG,MUX0);
			SET_BIT(ADC_MULTIPLEXER_SEL_REG,MUX1);
			SET_BIT(ADC_MULTIPLEXER_SEL_REG,MUX2);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX3);
			CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG,MUX4);
			break;
	}
}

/******************************************************************************
* \Syntax          : u16 Adc_StartConversion(Adc_Result_Adjustment)
* \Description     : start conversion if polling mode
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : result_alignment
* \Return value:   : u16
*
*******************************************************************************/

u16 Adc_StartConversion(Adc_Result_Adjustment result_alignment){
	u16 result;

	//start conversion
	SET_BIT(ADC_CONTROL_STATUS_REG_A,ADSC);

	while(! CHECK_BIT(ADC_CONTROL_STATUS_REG_A,ADIF)){
		; // conversion is happening
	}

	//clear the ADIF flag as mentioned in data sheet
	CLEAR_BIT(ADC_CONTROL_STATUS_REG_A,ADIF);

	if(result_alignment==LEFT_ADJUSTED){
		CLEAR_BIT(ADC_MULTIPLEXER_SEL_REG, ADLAR);

		result=ADC_DATA_REG_LOW;
		result|= ADC_DATA_REG_HIGH<<8;
	}

	if(result_alignment==RIGHT_ADJUSTED){
		SET_BIT(ADC_MULTIPLEXER_SEL_REG, ADLAR);

		result=ADC_DATA_REG_LOW>>8;
		result|= ADC_DATA_REG_HIGH<<2;
	}


	//continue
	return result;


}


/**********************************************************************************************************************
 *  END OF FILE: Adc.c
 *********************************************************************************************************************/
