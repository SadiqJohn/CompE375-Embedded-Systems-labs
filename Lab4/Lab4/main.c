/*
 * Lab4.c
 *
 * Created: 3/7/2021 3:34:12 PM
 * Author : John Sadiq
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

int main(void)
{
	
	OCR0A = 155;	// amount of time to reach max
	OCR0B = 0;		// affected by push
	
	//B7 is the button
	//B5 is the light on the board
	DDRB &= ~(1<<7); //enables button
	PORTB |= (1<<7); //output
	DDRB |= (1<<5); // light
	
	//timers
	TCCR0A |= (1<<WGM01);	//WGM01 = enabling CTC mode (Clear Timer on Compare)
	TCCR0B |= (1<<CS02) | (1<<CS00);	//book page 108, (101 = clk/1024)
		
    while (1) 
    {
		PORTB |= (1<<5);					// led on
		while ( (TIFR0 & (1<<OCF0B) ) == 0){}	//when flag from OCR0B
			TIFR0 |= (1<<OCF0B);				// reset flag 
		
		PORTB &= ~(1<<5);					// led off
		while ( (TIFR0 & (1<<OCF0A) ) == 0){}	//when flag from OCR0A
			TIFR0 |= (1<<OCF0A);				// reset flag 
			
		if(!(PINB & (1<<7))  && (OCR0B < OCR0A)) //when button is pushed
		{
			OCR0B++;	//increments duty cycle until OCR0B = OCR0A
		}
		
		if (PINB &(1<<7) && (OCR0B >0))	//when button is not pushed
		{
			OCR0B--;	//increments duty cycle until OCR0B = 0
		}
    }
}