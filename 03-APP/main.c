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
#include <stdio.h>
#include "Led.h"
#include "Button.h"
#include "Buzzer.h"
#include "Lcd.h"
#include "Eeprom.h"
#include "Interrupts.h"
#include <Bit_Math.h>
#include "Dio.h"
#include "Adc.h"
#include "Timer0.h"
#include <avr/interrupt.h>


#define BAUD_PRESCALE (103)

u8 no_of_overflow=0;
u8 no_of_count=0;
u16 value;
f64 volt;

u8 hours=11;
u8 minutes=14;
u8 seconds=0;

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



ISR(TIMER0_OVF_vect)   //for creating clock
{
	u8 hourBuffer[10];
	u8 minBuffer[10];
	u8 secBuffer[10];


	no_of_overflow++;
	Set_Counter_Reg(0);
	if(no_of_overflow==62){
		Set_Counter_Reg(256-128);
	}
	else if(no_of_overflow==63){
		seconds++;
		if(seconds==60){
			seconds=0;
			minutes++;
		}
		if(minutes==60){
			minutes=0;
			hours++;
		}
		if(hours==13){
			hours=1;
		}
		itoa(hours,hourBuffer,10);
		itoa(minutes,minBuffer,10);
		itoa(seconds,secBuffer,10);

		LCD_GoToRowColumn(0,0);
		LCD_DisplayStr(hourBuffer);
		LCD_GoToRowColumn(0,2);
		LCD_DisplayStr(":");
		LCD_GoToRowColumn(0,4);
		LCD_DisplayStr(minBuffer);
		LCD_GoToRowColumn(0,6);
		LCD_DisplayStr(":");
		LCD_GoToRowColumn(0,8);
		LCD_DisplayStr(secBuffer);

		no_of_overflow=0;
	}

}


ISR(TIMER0_COMP_vect)
{
	no_of_count++;
	Set_Counter_Reg(0);
	if(no_of_count==62){
		Set_Output_Compare_Reg(256-128);
	}
	else if(no_of_count==63){
		Led_Toggle(LED2);
		no_of_count=0;
		Set_Output_Compare_Reg(256);
	}
}

//ISR(TIMER0_OVF_vect)
//{
//	no_of_overflow++;
//	Set_Counter_Reg(0);
//	if(no_of_overflow==62){
//		Set_Counter_Reg(256-128);
//	}
//	else if(no_of_overflow==63){
//		Led_Toggle(LED2);
//		no_of_overflow=0;
//	}
//
//}


static void configure_Motor(){
	Dio_ConfigChannel(DIO_PORTD, DIO_CH_4, OUTPUT);
	Dio_ConfigChannel(DIO_PORTC, DIO_CH_3, OUTPUT);
	Dio_ConfigChannel(DIO_PORTC, DIO_CH_4, OUTPUT);

}

static void configure_PWM(){
	CLEAR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);

	SET_BIT(TCCR1A,0);
//	SET_BIT(TCCR1A,1);
	CLEAR_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);


	CLEAR_BIT(TCCR1B,0);
	CLEAR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);

}







void SPI_Init()					/* SPI Initialize function */
{
	DDRB &= ~((1<<5)|(1<<7)|(1<<4));  /* Make MOSI, SCK, SS as
 						input pins */
	DDRB |= (1<<6);			/* Make MISO pin as
						output pin */
	SPCR = (1<<SPE);			/* Enable SPI in slave mode */
}

u8 SPI_Receive()			/* SPI Receive data function */
{
	while(!(SPSR & (1<<SPIF)));	/* Wait till reception complete */
	return(SPDR);			/* Return received data */
}

int main(void){
	u8 data;
	SPI_Init();
	Led_INIT();
	while(1){
		data= SPI_Receive();
		if(data == 'm'){
			Led_Toggle(LED0);
		}

	}

}

//
//int main(void){
//	UART_Init();
//	Led_INIT();
//	Button_INIT();
//	UART_TxStr("Hello Mohamed");
//	while(1){
//
//		if(UART_RxChar()=='m'){
//			Led_Toggle(LED0);
//		}
//		if(UART_RxChar()=='n'){
//			Led_Toggle(LED1);
//		}
//
//		if(Button_READ(BUTTON0)==PRESSED){
//			UART_TxChar('n');
//			_delay_ms(250);
//		}
//		if(Button_READ(BUTTON1)==PRESSED){
//			UART_TxChar('m');
//			_delay_ms(250);
//		}
//		if(Button_READ(BUTTON2)==PRESSED){
//			UART_TxChar('l');
//			_delay_ms(250);
//		}
//
//
//
//
//
////		if(UART_RxChar()=='s'){
////			Led_Toggle(LED1);
////		}
//	}
//}


//int main(void){
//	u8 buffer[10];
//
//
//	u16 value;
//	Adc_Configure(AVCC, DIV_FACTOR_128, ADC_POLLING);
//	Adc_Channel_Sel(ADC1);
//
//	LCD_Init();
//	LCD_Cmd(_LCD_CURSOR_OFF);
//
//
//	Led_INIT();
//
//	Timer0_Configure(NORMAL_MODE, NORMAL_OPERATION, CLK_1024_PRESCALER, 0, 0);
//
//	WDG_ON();
//
//	while(1){
//		value = Adc_StartConversion(RIGHT_ADJUSTED);
//		LCD_GoToRowColumn(1,2);
//		itoa(value,buffer,10);   //function to convert any number to ascii
//		LCD_DisplayStr(buffer);
//
//
//	}
//}

//int main(void){
//	while(1){
//
//	}
//}


//int main(void){
//	configure_PWM();
//	configure_Motor();
//
//	while(1){
//		Dio_WRITEChannel(DIO_PORTC, DIO_CH_5, STD_HIGH);
//		Dio_WRITEChannel(DIO_PORTC, DIO_CH_6, STD_LOW);
//
//		OCR1AL=0x00;
//		OCR1AH=0x00;
//
//	}
//}


//
//int main(void){
//	configure_Motor();
//	Dio_WRITEChannel(DIO_PORTD, DIO_CH_4, STD_HIGH);
//	while(1){
//
//
//		Dio_WRITEChannel(DIO_PORTC, DIO_CH_3, STD_HIGH);
//		Dio_WRITEChannel(DIO_PORTC, DIO_CH_4, STD_LOW);
//
//		_delay_ms(2000);
//
//		Dio_WRITEChannel(DIO_PORTC, DIO_CH_4, STD_HIGH);
//		Dio_WRITEChannel(DIO_PORTC, DIO_CH_3, STD_HIGH);
//
//		_delay_ms(2000);
//
//
//		Dio_WRITEChannel(DIO_PORTC, DIO_CH_3, STD_LOW);
//		Dio_WRITEChannel(DIO_PORTC, DIO_CH_4, STD_HIGH);
//
//		_delay_ms(2000);
//
//
//
//	}
//}

//int main(void){
//
//
//	u8 buffer[10];
//	configure_ADC();
//	LCD_Init();
//	while(1){
//		start_conversion();
//		sprintf(buffer,"%d",value);
//		LCD_GoToRowColumn(0,0);
//		LCD_DisplayStr(buffer);
//	}
//}

//
//int main(void)
//{
////	configure_Timer();
//	configure_TimerCTC();
//	configure_ADC();
//	configure_ISR();
//	//initialize inputs and outputs
//	u8 bufr[10];
//	s8 num=10;
//
//
//
//	Led_INIT();
//	Button_INIT();
//	Buzzer_INIT();
//	SSD_Init();
//	LCD_Init();
//	LCD_Cmd(_LCD_CURSOR_OFF);
//
// 	s8 count=0;
//	//SSD_Display(count);
//
//
//
//	LCD_WriteCustomChr();
//	LCD_GoToRowColumn(0,15);
//	LCD_DisplayChr(0);
//
//	LCD_GoToRowColumn(0,0);
//	LCD_DisplayStr("Count : ");
//
//
//	//u8 x=EEPROM_Read(0);
//	//EEPROM_Write(0,count);
//
//	if(EEPROM_Read(0)!=0x00){
//		count =EEPROM_Read(0);
//	}
//
//    while (1)
//    {
//
//		//configure_ADC();
//    	start_conversion();
//    	itoa(value,bufr,10);   //function to convert any number to ascii
//		LCD_GoToRowColumn(1,0);
//		LCD_DisplayStr(bufr);
//
//
//
//		LCD_GoToRowColumn(1,8);
//		count =EEPROM_Read(0);
//
//		LCD_DisplayChr((count/10)+48);
//		LCD_DisplayChr((count%10)+48);
//
//		if(Button_READ(BUTTON0)==PRESSED){
//
//			count++;
//			if (count == 100) count =0;
//
//			//Buzzer_TurnON(BUZZER0);
//			//Buzzer_TurnOFF(BUZZER0);
//			_delay_ms(250);
//		}
//
//		if(Button_READ(BUTTON1)==PRESSED){
//			count--;
//
//			if (count == -1) count =99;
//			//Buzzer_TurnON(BUZZER0);
//			//Buzzer_TurnOFF(BUZZER0);
//			_delay_ms(250);
//
//		}
//		EEPROM_Write(0,count);
//
//
//
//
//
//
//		//SSD_Display(count);
//
////
//		//LCD_DisplayStr("I");
//		//_delay_ms(2000);
//		//LCD_Cmd(_LCD_CLEAR);
//		//LCD_DisplayStr("am");
//		//_delay_ms(2000);
//		//LCD_Cmd(_LCD_CLEAR);
//		//LCD_DisplayStr("Mohamed  :)");
//		//_delay_ms(2000);
//		//LCD_Cmd(_LCD_CLEAR);
//
//
//
//
//    }
//}

