/*
 * Lab6.c
 *
 * Created: 3/31/2021 4:44:18 PM
 * Author : John
 */ 

 /*Use the last 3 digits of your Red ID to decide the values for X & Z
 John Sadiq's REDID: 825764388, Z = 8. X = 3.

 Duty cycle frequency [(Z+1)*100 Hz]
 Duty Cycle f = (8+3) * 100Hz = 1100Hz.
 Period/s: t = 1/f = 1.1ms.

Interrupt period [(X+1) ms]
Scan Period = (3+1)ms = 4ms.
 */

#define F_CPU 16000000UL
#define BAUD 9600							
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)	
#define LED_TOGGLE (PORTB ^= (1<<PORTB5))	
#define LED_ON (PORTB |= (1<<5))
#define LED_OFF (PORTB &= ~(1<<5))

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>


void Keypad_intlize(void)
{
	//column
	DDRB	&= ~((1<<0)|(1<<1)|(1<<2)|(1<<3));	
	PORTB	|= ((1<<0)|(1<<1)|(1<<2)|(1<<3));	
	//row
	DDRD	|= ((1<<4)|(1<<5)|(1<<6)|(1<<7)); 	
	PORTD	|= ((1<<4)|(1<<5)|(1<<6)|(1<<7));	
	//LED
	DDRB	|= (1<<5);							
}

unsigned int row, col;	

/*((keyboard[row][col])/10)*250*/
char keyboard[4][4]=			{{25,50,75,249},
								{100,125,150,249},
								{175,200,225,249},
								{0,0,0,249}};

void scankey(void)
{

	for(row=0; row< 4; row++)
	{
		PORTD &= ~(1<<(row+4));					// Set ROW OUTPUT as LOW one at a time to check
		
		for(col=0;col<=3; col++)
		{
			if ((!(PINB & (1<<col))))				// Checking column to find which button is pressed
			{
						OCR0B = (keyboard[row][col]);		//Use the index [r][c] to set dimming percentage in the timer
	}
		}
		
		PORTD |= (1<<(row+4));					//Set PORT back to HIGH after checking entire row
	}
}

/*Scanning Keyboard every 4ms*/
/*
calculate OCRA, (4ms*16M) / 256 = 250
because it is 250, we use the 256 pre scaler
*/
void Scan_Timer2(void)
{
	OCR2A = 250;							// Setting OCR2A to 4ms
	TCCR2A |= (1 << WGM21);					// ENABLE CTC mode
	TCCR2B |= (1 << CS22);					// Set Pre Scaler to 256
	TIMSK2 |= (1 << OCIE2A);				// ENABLE the ISR COMPA
}

ISR (TIMER2_COMPA_vect)		
{
	scankey();
}

/*Dimming Duty Cycle 1100Hz = 1.1ms cycle*/

/*
OCROA = (1.1ms) / (256/16000000) = 68.75
I will be rounding up to 69
 */
void freq_Timer0(void)						
{
	OCR0A = 69;								// Setting OCRA to 1.1ms			
	TCCR0A |= (1 << WGM01);					// ENABLE CTC mode
	TCCR0B |= (1 << CS02);					// Set Pre Scaler 256 
	TIMSK0 |= (1 << OCIE0A)|(1 << OCIE0B);	// ENABLE the ISR COMPA and COMPB 
}


ISR (TIMER0_COMPA_vect)
{
	if(OCR0B != 0)
	LED_ON;
}

ISR (TIMER0_COMPB_vect)
{
	if(OCR0B < 250)
	LED_OFF;
}

int main(void)
{
	cli();	// DISABLE global Interrupts
	Keypad_intlize();
	Scan_Timer2();
	freq_Timer0();
	sei();	// ENABLE global Interrupts
	while(1)
	{
	}
}