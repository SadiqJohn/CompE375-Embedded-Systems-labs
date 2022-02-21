/*
 * Lab2.c
 *
 * Created: 2/17/2021 7:37:24 PM
 * Author : John 
 */ 
#define F_CPU 16000000UL //16 mHz Clock
#define BAUD 9600// define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)// set baud rate
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>

// function to initialize UART
void uart_init(void)
{

	UBRR0H = (BAUDRATE>>8);        // shift the register right by 8 bits
	UBRR0L = BAUDRATE;              // set baud rate
	UCSR0B|= (1<<TXEN0)|(1<<RXEN0); // enable receiver and transmitter, 
									//TXEN => enable transmitter, RXEN => enable receiver
	UCSR0C|= (1<<UCSZ00)|(1<<UCSZ01);   // 8bit data format (Data bits)
}

void uartTrx (char redID)   // sends the redID
{
	while(!(UCSR0A & (1<<UDRE0))); // wait while data is being received
	UDR0 = redID;                 // return 8-bit data
}

unsigned char uartRec (void)   // received the redID
{
	while ( (!(UCSR0A) ) & (1<<RXC0) );
	return UDR0;
}

int main(void)
{
	uart_init();
	char redID[] = "825764388\n";
	while (1)
	{
		for (int i=0; redID[i] != '\0'; i++)
		{
			uartTrx(redID[i]);
			_delay_ms(500);
		}
	}
}