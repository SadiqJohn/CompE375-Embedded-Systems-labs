/*
 * Lab3.c
 *
 * Created: 2/25/2021 7:00:37 PM
 * Author : John
 */ 

#define F_CPU 16000000UL
#define BAUD 9600							// define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)	// set baud rate
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>


// function to initialize UART
void USART_intlize (void)				
{
	UBRR0H  = (BAUDRATE>>8);			
	UBRR0L  = BAUDRATE;					
	UCSR0B |= ((1<<TXEN0)|(1<<RXEN0));	
	UCSR0C |= ((1<<UCSZ00)|(1<<UCSZ01));
}

void USART_transm(unsigned char data)	
{
	while (! ( UCSR0A & (1<<UDRE0) ) );	
	UDR0 = data;						
}

unsigned char keypad[4][4]=  {{'1','2','3','A'},
							  {'4','5','6','B'},
							  {'7','8','9','C'},
							  {'*','0','#','D'}};

int main(void)
{
	USART_intlize();							
	unsigned int row = 0;
	unsigned int col = 0;
	
	//COLUMNS (OUTPUT)
	DDRB &= ~((1<<DDB0)|(1<<DDB1)|(1<<DDB2)|(1<<DDB4)); 	//Set PORTB as input 0
		
	//ROWS (INPUT)
	DDRD |= ((1<<DDD4)|(1<<DDD5)|(1<<DDD6)|(1<<DDD7)); 		//Set PORTD as output 1
	
	PORTB |= ((1<<DDB0)|(1<<DDB1)|(1<<DDB2)|(1<<DDB3));		//Pull-up resistor enabled by default at 1
	PORTD |= ((1<<DDD4)|(1<<DDD5)|(1<<DDD6)|(1<<DDD7));		//Sets Ports on rows as outputs high
	
	while (1)
	{
		for(row=0; row< 4; row++)
		{
			PORTD &= ~(1<<(row+DDD4));						//Set PORT LOW one at a time to check
				for(col=0;col<=3; col++)
				{
					if (!(PINB & (1<<col)))				//Checking if push button is pressed
					{
						_delay_ms(300);					    //Delay for button bounce
						USART_transm(keypad[row][col]);		//Transmit the index [row][col]
					}
				}
			PORTD |= (1<<(row+4));						//Set PORT back to HIGH after checking entire row
		}
	}								
}										