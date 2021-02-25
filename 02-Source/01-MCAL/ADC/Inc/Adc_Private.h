 /********************************************************************************************************************
 *  File		: Adc_Private.h
 *	Module		: ADC
 *	Target		: ATMEGA32
 *	Author		: mAboushenif
 *  Description	:
 *********************************************************************************************************************/
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define ADC_MULTIPLEXER_SEL_REG         (* (volatile u8*) 0x27)
// For analog channel selection
#define MUX0   (0)
#define MUX1   (1)
#define MUX2   (2)
#define MUX3   (3)
#define MUX4   (4)
// If 1 it is left adjusted else it is right adjusted
#define ADLAR  (5)
// Reference selection bits
#define REFS0  (6)
#define REFS1  (7)


#define ADC_CONTROL_STATUS_REG_A	    (* (volatile u8*) 0x26)
// Prescaler Selection Bits
#define ADPS0   (0)
#define ADPS1   (1)
#define ADPS2   (2)
// ADC Interrupt Enable
#define ADIE    (3)
// ADC Interrupt Flag
#define ADIF    (4)
// ADC Auto Trigger Enable
#define ADATE   (5)
// ADC Start Conversion
#define ADSC    (6)
// ADC Enable
#define ADEN    (7)


//  Result is found in those two registers
#define ADC_DATA_REG_LOW			    (* (volatile u8*) 0x24)
#define ADC_DATA_REG_HIGH			    (* (volatile u8*) 0x25)

#define SPECIAL_FUNCTION_IO_REG         (* (volatile u8*) 0x50)
// always write this bit to 0
#define RESERVED_BIT (4)
// ADC auto trigger source
#define ADTS0    (5)
#define ADTS1    (6)
#define ADTS2    (7)

// to enable global interrupts to use the interrupt mode in ADC
#define STATUS_REG          (*(volatile u8*)0x5F)
#define GLOBAL_INT_EN (7)










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
 *  END OF FILE: Adc_Private.h
 *********************************************************************************************************************/
