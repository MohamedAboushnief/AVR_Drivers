 /*
 * AVR_Interfacing.c
 *
 * Created: 1/15/2021 8:44:15 PM
 * Author : moham
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "Std_Types.h"
#include <util/delay.h>
#include <stdlib.h>
#include "Led.h"
#include "Button.h"
#include "Buzzer.h"
#include "Lcd.h"
#include "Eeprom.h"
#include "Interrupts.h"
#include <Bit_Math.h>

#include <avr/interrupt.h>


u16 value;
f64 volt;

ISR(INT0_vect)
{
	Led_Toggle(LED1);
	Led_Toggle(LED2);
}

static void configure_ISR(){
	Global_Interrupt_En();
	Ext_Interrupt_Config(Interrupt0,Falling_Edge);
	Ext_Interrupt_Enable(Interrupt0);
}

static void configure_ADC(){
	SET_BIT(ADCSRA,7);

	SET_BIT(ADMUX,0);
	CLEAR_BIT(ADMUX,1);
	CLEAR_BIT(ADMUX,2);
	CLEAR_BIT(ADMUX,3);
	CLEAR_BIT(ADMUX,4);

	CLEAR_BIT(ADMUX,5);


	SET_BIT(ADMUX,6);
	CLEAR_BIT(ADMUX,7);


	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);



}


static void start_conversion(){
	//start conversion
	SET_BIT(ADCSRA,6);
	while(! (CHECK_BIT(ADCSRA,4)))
		;
	SET_BIT(ADCSRA,4);
	value=ADCL;
	value|= ADCH<<8;

	f64 step= 5000/1024;
	volt = step*value;


}

int main(void)
{ 
	configure_ADC();
	configure_ISR();
	//initialize inputs and outputs
	u8 bufr[10];
	s8 num=10;
	
	

	Led_INIT();
	Button_INIT();
	Buzzer_INIT();
	SSD_Init();
	LCD_Init();
	LCD_Cmd(_LCD_CURSOR_OFF);
	
 	s8 count=0;
	//SSD_Display(count);
	
	
	
	LCD_WriteCustomChr();	
	LCD_GoToRowColumn(0,15);
	LCD_DisplayChr(0);
	
	LCD_GoToRowColumn(0,0);
	LCD_DisplayStr("Count : ");
	
	
	//u8 x=EEPROM_Read(0);
	//EEPROM_Write(0,count);
	
	if(EEPROM_Read(0)!=0x00){
		count =EEPROM_Read(0);
	}
	
    while (1) 
    {
		
		//configure_ADC();
    	start_conversion();
    	itoa(value,bufr,10);   //function to convert any number to ascii
		LCD_GoToRowColumn(1,0);
		LCD_DisplayStr(bufr);



		LCD_GoToRowColumn(1,8);
		count =EEPROM_Read(0);
		
		LCD_DisplayChr((count/10)+48);
		LCD_DisplayChr((count%10)+48);
		
		if(Button_READ(BUTTON0)==PRESSED){
			
			count++;
			if (count == 100) count =0;
			
			//Buzzer_TurnON(BUZZER0);
			//Buzzer_TurnOFF(BUZZER0);
			_delay_ms(250);
		}
		
		if(Button_READ(BUTTON1)==PRESSED){
			count--;
			
			if (count == -1) count =99;
			//Buzzer_TurnON(BUZZER0);
			//Buzzer_TurnOFF(BUZZER0);
			_delay_ms(250);

		}
		EEPROM_Write(0,count);
		
		
		
		
		
		
		//SSD_Display(count);

//
		//LCD_DisplayStr("I");
		//_delay_ms(2000);
		//LCD_Cmd(_LCD_CLEAR);
		//LCD_DisplayStr("am");
		//_delay_ms(2000);
		//LCD_Cmd(_LCD_CLEAR);
		//LCD_DisplayStr("Mohamed  :)");
		//_delay_ms(2000);
		//LCD_Cmd(_LCD_CLEAR);
																		
		
		
		
    }
}

