/*
 * Lab 7.c
 *
 * Created: 4/15/2021 6:08:52 PM
 * Author : John
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#define LEDON PORTB |= (1<<5) //LED ON
#define LEDOFF PORTB &= ~(1<<5) // LED OFF

/*
RedID = 825764388
X = 3, Y = 8, Z = 8
Timer Interrupt = (3+1) = 4ms for OCR0A
DUTY cycle frequency = (8+1) * 100Hz = 900Hz / 1.11ms for OCR2A
Y mod 6 = channel 2
*/

void timer0_initialization() {
	TCCR0A |= (1<<WGM01); //CTC mode
	OCR0A = 249; //Using ps = 256, 4m / (250-1) 
	TCCR0B |= (1<<CS02); //Pre-scaler = 256
	TIMSK0 |= (1<<OCIE0A); //Enabling compare match A Interrupt for timer 0
}

void timer2_initialization(uint16_t variable) {
	TCCR2A |= (1<<WGM21); //CTC mode
	OCR2A = 69; //Using PS = 256, 1.11ms/ (69.375 - 1) then rounded to 69
	OCR2B = OCR2A * (variable/1024.00); //calculating OCR2B
	TCCR2B |= (1<<CS22) ; //PS = 256
	TIMSK2 |= (1<<OCIE2A) | (1<<OCIE2B); //Enabling compare match A & B Interrupts
}

void adc_init(void){
	ADMUX &= 0b00010000; //Clearing all bits except for the reserved one
	DDRB |= (1<<DDB5); //Set LED as output
	DDRC &= ~(1<<PINC2); //Setting input at PORTC pin 2
	ADMUX |= 0b01000001; //Setting VCC reference and ADC1
	ADCSRA |= (1<<ADEN) | (1<<ADIE) | (1<<ADPS1) | (1<<ADPS2) | (1<<ADPS0); //Enable ADC
}

uint16_t variable = 0;
int main(void)
{
	timer0_initialization();
	adc_init();
	sei(); //enable global interrupt
	
	/* Replace with your application code */
	while(1)
	{
	}
}
ISR (TIMER0_COMPA_vect){
	ADCSRA |= (1<<ADSC); //Timer 0 overflow occurs, start conversion
}

ISR (ADC_vect){
	uint16_t variable = ADC; //ADC Conversion Complete, save result to variable
	timer2_initialization(variable); //Pass result to timer2_initialization() function
}

ISR(TIMER2_COMPA_vect){
	LEDON;
}

ISR (TIMER2_COMPB_vect){
	LEDOFF;
}
