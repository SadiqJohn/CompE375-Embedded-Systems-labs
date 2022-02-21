/*
 * Lab 8.c
 *
 * Created: 4/22/2021 9:54:53 PM
 * Author : John
 */ 


#define F_CPU 16000000UL
#define BAUD 9600                           // define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)    // set baud rate
#define LED_ON (PORTB |= (1<<5))
#define LED_OFF (PORTB &= ~(1<<5))
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/eeprom.h>
void CTC_intlize(void)
{
	OCR0A = 155;                            		// Setting Timer0 for CTC, 10ms, 155
	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS00)|(1 << CS02);				// Set up timer with pre-scale = 1024, and ENABLE CTC mode
	TIMSK0 |= (1 << OCIE0A)|(1 << OCIE0B);			// Set the ISR COMPA vect and COMPB vect;
	sei(); //enable interrupts
}

ISR (TIMER0_COMPA_vect)
{
	if(OCR0B != 0)
	LED_ON;
}
ISR (TIMER0_COMPB_vect)
{
	if(OCR0B < 156)
	LED_OFF;
}
void READ_WRITE_EEPROM(void)
{
	uint8_t ReadByte;								
	uint8_t LoadByte;
	
	ReadByte = eeprom_read_byte((uint8_t*)0x33);	//Read BYTE in a location of EEPROM
			
	if(ReadByte < 155)								//Check if BYTE read is less than 155
	{
		OCR0B = ReadByte;							//Set OCR0B as read BYTE
		LoadByte = ReadByte + 16;					//Add BYTE by 16(about 10% of 155)
		eeprom_write_byte((uint8_t*)0x33, LoadByte);//Load new value to EEPROM location
	}
			
	else
	{
		OCR0B = 156;								//If BYTE read is greater than 155
		LoadByte = 0;							//Reset OCR0B to zero on next turn on
		eeprom_write_byte((uint8_t*)0x33, LoadByte);//Reset BYTE in location to zero
	}		
}
int main(void)
{
	cli();
	DDRB  |= (1<<5);	// Set PinB5(LED) as an OUTPUT
	LED_OFF;			// Default OFF
	CTC_intlize();
	READ_WRITE_EEPROM();
	while (1)
	{
	}
}//end of main
