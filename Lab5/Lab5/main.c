/*
 * Lab5.c
 *
 * Created: 3/31/2021 4:44:18 PM
 * Author : John
 */ 
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL


void keypad_note(int freq, int a)
{
	timer_init(freq);  
	while (!(PINB & (1<<a)))
	{
		while((TIFR0 & (1 << OCF0B)) == 0 )
		{
			PORTD |= (1 << 1);
		}
		TIFR0 |= (1 << OCR0B);
		
		while((TIFR0 & (1 << OCF0A)) == 0)
		{
			PORTD &= ~ (1 << OCF0A);
		}
		TIFR0 |= (1 << OCR0A);
	}
}

void keypad_init(void)
{
	DDRD |= ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7));
	DDRB &= ~(1 << 0) & ~(1 << 1) & ~(1 << 2) & ~(1 << 3);
	PORTB |= ((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3));
	PORTD |= (1<<4|1<<5|1<<6|1<<7);
	DDRD |= (1 << 1);
	DDRB |= (1 << PORTB5);
}

void timer_init(int freq)
{
	TCCR0A |= (1 << WGM01); //ctc
	OCR0A = freq;
	OCR0B = freq * 0.5;
	TCCR0B |= (1 << CS02); //ps 256
}



int main(void)
{
	keypad_init();
	const int keypad[4][4] = {{141,133,126,119},
							{112,105,99,94},
							{88,83,79,74},
							{70,66,62,59}};
	while(1)
	{
		for (int row = 4; row <= 7; row++)
		{
			PORTD &= ~(1<<row);
			for (int col = 0; col <= 3; col++)
			{
				if(!(PINB & (1<<col)))
				{
					keypad_note(keypad[row-4][col],col);
				}
				PORTB |= (1<<0|1<<1|1<<2|1<<3);
			}
			PORTD |= (1<<row);
		}
	}
	
	
}
