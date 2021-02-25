 /********************************************************************************************************************
 *  File		: Timer0_Private.h
 *	Module		: TIMER0
 *	Target		: ATMEGA32
 *	Author		: mAboushenif
 *  Description	: Registers of Timer0
 *********************************************************************************************************************/
#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define TIMER0_COUNTER_CONTROL_REG         (* (volatile u8*) 0x53)    // Timer/Counter Control Register
#define CS00  (0)   // clock select bits
#define CS01  (1)
#define CS02  (2)

#define WGM01 (3)   // waveform mode generation bit mode
#define WGM00 (6)

#define COM00 (4)   // compare output mode PWM / Non PWM
#define COM01 (5)

#define FOC0  (7)	// force output compare



#define TIMER0_COUNTER_REG   				(* (volatile u8*) 0x52)   // Timer/Counter Register
#define TIMER0_OUTPUT_COMPARE_REG			(* (volatile u8*) 0x5C)	// Output Compare Register

#define TIMER0_COUNTER_INT_M_REG			(* (volatile u8*) 0x59)	// Timer/Counter Interrupt Mask Register
#define TOIE0 (0)   // Timer/Counter0 Overflow Interrupt Enable
#define OCIE0 (1)   // Timer/Counter0 Output Compare Match Interrupt Enable

#define TIMER0_COUNTER_INT_F_REG  			(* (volatile u8*) 0x58)	// Timer/Counter Interrupt Flag Register
#define TOV0  (0)   // Timer/Counter0 Overflow Flag
#define OCF0  (1)	// Output Compare Flag 0

#define TIMER0_SPECIAL_FUNC_REG     		(* (volatile u8*) 0x50)   // Special Function IO Register
#define PSR10 (0)   // Prescaler Reset Timer/Counter1 and Timer/Counter0

// to enable global interrupts to use the interrupt mode in Timer0
#define STATUS_REG          				(*(volatile u8*)0x5F)
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
 *  END OF FILE: Timer0_Private.h
 *********************************************************************************************************************/
